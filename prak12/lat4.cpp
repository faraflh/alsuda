#include <algorithm>
#include <chrono>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 4;

struct Mahasiswa {
    string nrp;
    string nama;
    int kelas;
};

void InsertionSort(Mahasiswa arr[]) {
    int i, j;
    Mahasiswa curr;
    for (i = 1; i < MAX; i++) {
        curr = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].nrp > curr.nrp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

void SelectionSort(Mahasiswa arr[]) {
    int i, j, min_id;
    Mahasiswa minMhs;
    i = 0;
    while (i < MAX - 1) {
        min_id = i;
        minMhs = arr[i];
        for (j = i + 1; j < MAX; j++) {
            if (arr[j].nrp < minMhs.nrp) {
                minMhs = arr[j];
                min_id = j;
            }
        }
        Mahasiswa temp = arr[min_id];
        arr[min_id] = arr[i];
        arr[i] = temp;
        i++;
    }
}

void BubbleSort(Mahasiswa arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].nrp > arr[j + 1].nrp) {
                Mahasiswa temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSortFlag(Mahasiswa arr[], int size) {
    bool swapped = true;
    int i = 0;
    while (swapped) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].nrp > arr[j + 1].nrp) {
                Mahasiswa temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        i++;
    }
}

void ShellSort(Mahasiswa arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            Mahasiswa temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].nrp < temp.nrp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int Partition(Mahasiswa arr[], int low, int high) {
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

void QuickSort(Mahasiswa arr[], int low, int high) {
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
    Mahasiswa mahasiswa[MAX] = {
        {"20070007", "Karina", 2},
        {"22070003", "Winter", 1},
        {"21070008", "Ning", 3},
        {"19070005", "Aeri", 7}};

    cout << "Data Mahasiswa Sebelum Diurutkan:\n";
    display(mahasiswa, MAX);

    int menu, pilih;
    double time_taken;

    cout << "ALGORITMA SORTING\n";
    cout << "1. Insertion\n";
    cout << "2. Selection\n";
    cout << "3. Bubble\n";
    cout << "4. Bubble dengan Flag\n";
    cout << "5. Shell\n";
    cout << "6. Quick\n";
    cout << "7. Merge\n";
    cout << "Pilihan: ";
    cin >> menu;

    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Pilihan: ";
    cin >> pilih;

    if (menu == 1) {
        if (pilih == 1) {
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(mahasiswa);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nASCENDING INSERTION SORT BERDASARKAN NRP" << endl;
        } else {
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(mahasiswa);
            reverse(mahasiswa, mahasiswa + MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nDESCENDING INSERTION SORT BERDASARKAN NRP" << endl;
        }
    } else if (menu == 2) {
        if (pilih == 1) {
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(mahasiswa);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nASCENDING SELECTION SORT BERDASARKAN NRP" << endl;
        } else {
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(mahasiswa);
            reverse(mahasiswa, mahasiswa + MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nDESCENDING SELECTION SORT BERDASARKAN NRP" << endl;
        }
    } else if (menu == 3) {
        if (pilih == 1) {
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(mahasiswa, MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nASCENDING BUBBLE SORT BERDASARKAN NRP" << endl;
        } else {
            auto start = chrono::high_resolution_clock::now();
            BubbleSort(mahasiswa, MAX);
            reverse(mahasiswa, mahasiswa + MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nDESCENDING BUBBLE SORT BERDASARKAN NRP" << endl;
        }
    } else if (menu == 4) {
        if (pilih == 1) {
            auto start = chrono::high_resolution_clock::now();
            BubbleSortFlag(mahasiswa, MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nASCENDING BUBBLE SORT DENGAN FLAG BERDASARKAN NRP" << endl;
        } else {
            auto start = chrono::high_resolution_clock::now();
            BubbleSortFlag(mahasiswa, MAX);
            reverse(mahasiswa, mahasiswa + MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nDESCENDING BUBBLE SORT DENGAN FLAG BERDASARKAN NRP" << endl;
        }
    } else if (menu == 5) {
        if (pilih == 1) {
            auto start = chrono::high_resolution_clock::now();
            ShellSort(mahasiswa, MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nASCENDING SHELL SORT BERDASARKAN NRP" << endl;
        } else {
            auto start = chrono::high_resolution_clock::now();
            ShellSort(mahasiswa, MAX);
            reverse(mahasiswa, mahasiswa + MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nDESCENDING SHELL SORT BERDASARKAN NRP" << endl;
        }
    } else if (menu == 6) {
        if (pilih == 1) {
            auto start = chrono::high_resolution_clock::now();
            QuickSort(mahasiswa, 0, MAX - 1);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nASCENDING QUICK SORT BERDASARKAN NRP" << endl;
        } else {
            auto start = chrono::high_resolution_clock::now();
            QuickSort(mahasiswa, 0, MAX - 1);
            reverse(mahasiswa, mahasiswa + MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nDESCENDING QUICK SORT BERDASARKAN NRP" << endl;
        }
    } else if (menu == 7) {
        if (pilih == 1) {
            auto start = chrono::high_resolution_clock::now();
            MergeSort(mahasiswa, 0, MAX - 1);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nASCENDING MERGE SORT BERDASARKAN NRP" << endl;
        } else {
            auto start = chrono::high_resolution_clock::now();
            MergeSort(mahasiswa, 0, MAX - 1);
            reverse(mahasiswa, mahasiswa + MAX);
            auto end = chrono::high_resolution_clock::now();
            double time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
            cout << "\nDESCENDING MERGE SORT BERDASARKAN NRP" << endl;
        }
    }
    display(mahasiswa, MAX);
    cout << "Waktu = " << time_taken << " detik\n";
}
