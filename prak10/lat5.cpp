#include <iostream>
#include <cstdlib>
#include <cstring>
#define MAX 3

using namespace std;

struct Mahasiswa {
    char nrp[10];
    char nama[20];
    int kelas;
};

void InsertionSort(Mahasiswa arr[]) {
    int i, j;
    Mahasiswa curr;
    for (i = 1; i < MAX; i++) {
        curr = arr[i];
        j = i - 1;
        while (j >= 0 && strcmp(arr[j].nrp, curr.nrp) > 0) {
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
            if (strcmp(arr[j].nrp, minMhs.nrp) < 0) {
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


int main() {
    Mahasiswa mhs[MAX];
    int i;

    for (i = 0; i < MAX; i++) {
        cout << "Masukkan nrp mahasiswa " << i + 1 << ": ";
        cin >> mhs[i].nrp;
        cout << "Masukkan nama mahasiswa " << i + 1 << ": ";
        cin >> mhs[i].nama;
        cout << "Masukkan kelas mahasiswa " << i + 1 << ": ";
        cin >> mhs[i].kelas;
        cout << endl;
    }

    cout << "INSERTION SORT\n";
    InsertionSort(mhs);
    for (i = 0; i < MAX; i++)
        cout << "NRP: " << mhs[i].nrp << "\nNama: " << mhs[i].nama << "\nKelas: " << mhs[i].kelas << "\n" << endl;

    cout << "\nSELECTION SORT" << endl;
    SelectionSort(mhs);
    for (i = 0; i < MAX; i++)
        cout << "NRP: " << mhs[i].nrp << "\nNama: " << mhs[i].nama << "\nKelas: " << mhs[i].kelas << "\n" << endl;

}

