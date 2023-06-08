#include <iostream>
#include <string>
using namespace std;

struct Pegawai {
    int NIP;
    string Nama;
    string Alamat;
    char Golongan;
};

int SequentialSearch(Pegawai arr[], int size, int keyNIP, string keyNama) {
    for (int i = 0; i < size; i++) {
        if (arr[i].NIP == keyNIP && arr[i].Nama == keyNama) {
            return i; 
        }
    }
    return -1; 
}

int BinarySearch(Pegawai arr[], int size, int keyNIP, string keyNama) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].NIP == keyNIP && arr[mid].Nama == keyNama) {
            return mid; 
        } else if (arr[mid].NIP < keyNIP || (arr[mid].NIP == keyNIP && arr[mid].Nama < keyNama)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}

void DisplayPegawaiList(Pegawai arr[], int size) {
    cout << "Daftar Pegawai:\n";
    cout << "NIP\tNama\t\tAlamat\t  Golongan\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i].NIP << "\t" << arr[i].Nama << "\t" << arr[i].Alamat << "\t  " << arr[i].Golongan << endl;
    }
}

int main() {
    const int MAX_SIZE = 5;
    Pegawai data[MAX_SIZE] = {
        {123, "Lily", "Jl. ABC", 'A'},
        {456, "ALycia", "Jl. DEF", 'B'},
        {789, "Moira", "Jl. GHI", 'C'},
        {101, "Kara", "Jl. JKL", 'A'},
        {112, "Charlotte", "Jl. MNO", 'B'}
    };

    DisplayPegawaiList(data, MAX_SIZE);

    int keyNIP;
    string keyNama;
    cout << "\nMasukkan NIP: ";
    cin >> keyNIP;
    cout << "Masukkan Nama: ";
    cin.ignore(); 
    getline(cin, keyNama);

    int sequentialIndex = SequentialSearch(data, MAX_SIZE, keyNIP, keyNama);
    if (sequentialIndex != -1) {
        cout << "Data ditemukan pada indeks " << sequentialIndex << " (Sequential Search)\n";
    } else {
        cout << "Data tidak ditemukan (Sequential Search)\n";
    }

    int binaryIndex = BinarySearch(data, MAX_SIZE, keyNIP, keyNama);
    if (binaryIndex != -1) {
        cout << "Data ditemukan pada indeks " << binaryIndex << " (Binary Search)\n";
    } else {
        cout << "Data tidak ditemukan (Binary Search)\n";
    }

    return 0;
}
