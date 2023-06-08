#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 3

using namespace std;

struct Mahasiswa {
char nrp[10];
char nama[20];
int kelas;
};

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

int main() {
    Mahasiswa mhs[MAX];
    int i;
    time_t k1, k2;

    for (i = 0; i < MAX; i++) {
        cout << "Masukkan nrp mahasiswa " << i + 1 << ": ";
        cin >> mhs[i].nrp;
        cout << "Masukkan nama mahasiswa " << i + 1 << ": ";
        cin >> mhs[i].nama;
        cout << "Masukkan kelas mahasiswa " << i + 1 << ": ";
        cin >> mhs[i].kelas;
        cout << endl;
    }
    

    cout << "BUBBLE SORT\n";
    BubbleSort(mhs, MAX);
    for (i = 0; i < MAX; i++)
        cout << "NRP: " << mhs[i].nrp << "\nNama: " << mhs[i].nama << "\nKelas: " << mhs[i].kelas << "\n" << endl;
    cout << "BUBBLE FLAG SORT" << endl;
    BubbleSortFlag(mhs, MAX);
    for (i = 0; i < MAX; i++)
        cout << "NRP: " << mhs[i].nrp << "\nNama: " << mhs[i].nama << "\nKelas: " << mhs[i].kelas << "\n" << endl;
    cout << "SHELL SORT" << endl;
    ShellSort(mhs, MAX);
    for (i = 0; i < MAX; i++)
        cout << "NRP: " << mhs[i].nrp << "\nNama: " << mhs[i].nama << "\nKelas: " << mhs[i].kelas << "\n" << endl;
}
