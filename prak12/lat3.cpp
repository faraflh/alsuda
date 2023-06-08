#include <iostream>
#include <vector>
using namespace std;

struct Mahasiswa {
    string nrp;
    string nama;
    int kelas;
};

int Partition(vector<Mahasiswa>& arr, int low, int high) {
    string pivot = arr[high].nrp;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].nrp < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(vector<Mahasiswa>& arr, int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void Merge(Mahasiswa arr[], int left, int median, int right) {
    int n1 = median - left + 1;
    int n2 = right - median;

    Mahasiswa L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[median + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].nrp <= R[j].nrp) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(Mahasiswa arr[], int left, int right) {
    if (left < right) {
        int median = left + (right - left) / 2;
        MergeSort(arr, left, median);
        MergeSort(arr, median + 1, right);
        Merge(arr, left, median, right);
    }
}
void display(Mahasiswa arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i].nrp << " \t" << arr[i].nama << " \t" << arr[i].kelas << endl;
    }
}

int main() {
    vector<Mahasiswa> mahasiswa = {
        {"20070007", "Karina", 2},
        {"22070003", "Winter", 1},
        {"21070008", "Ning", 3},
        {"19070005", "Aeri", 7}
    };

    cout << "Data Mahasiswa Sebelum Diurutkan:\n";
    display(mahasiswa.data(), mahasiswa.size());

    QuickSort(mahasiswa, 0, mahasiswa.size() - 1);
    cout << "\nASCENDING QUICK SORT BERDASARKAN NRP" << endl;
    display(mahasiswa.data(), mahasiswa.size());

    MergeSort(mahasiswa.data(), 0, mahasiswa.size() - 1);
    cout << "\nASCENDING MERGE SORT BERDASARKAN NRP" << endl;
    display(mahasiswa.data(), mahasiswa.size());
}
