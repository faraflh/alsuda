#include <iostream>
#include <string>
using namespace std;

struct Pegawai {
    int NIP;
    string Nama;
    string Alamat;
    char Golongan;
};
const int MAX_SIZE = 10;

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
        cout << arr[i].NIP << "\t" << arr[i].Nama << "\t\t" << arr[i].Alamat << "\t  " << arr[i].Golongan << endl;
    }
}

void InsertElement(Pegawai arr[], int& size, Pegawai data, int position) {
    if (size >= MAX_SIZE) {
        cout << "Array sudah penuh. Tidak dapat menyisipkan elemen baru.\n";
        return;
    }

    if (position < 0 || position > size) {
        cout << "Posisi penyisipan tidak valid.\n";
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1]; 
    }

    arr[position] = data;
    size++;
}

void DeleteElement(Pegawai arr[], int& size, int keyNIP, string keyNama) {
    int position = SequentialSearch(arr, size, keyNIP, keyNama);
    if (position == -1) {
        cout << "Data tidak ditemukan. Tidak dapat menghapus.\n";
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1]; 
    }

    size--;
}

int main() {
    const int MAX_SIZE = 10;
    Pegawai data[MAX_SIZE] = {
        {123, "Lily", "Jl. ABC", 'A'},
        {456, "ALycia", "Jl. DEF", 'B'},
        {789, "Moira", "Jl. GHI", 'C'},
        {101, "Kara", "Jl. JKL", 'A'},
        {112, "Billy", "Jl. MNO", 'B'}
    };

    int size = 5;

    DisplayPegawaiList(data, size);

    int searchOption;
    cout << "\nPilih metode pencarian:\n";
    cout << "1. Sequential Search\n";
    cout << "2. Binary Search\n";
    cout << "Pilihan: ";
    cin >> searchOption;

    int keyNIP;
    string keyNama;
    cout << "\nMasukkan NIP: ";
    cin >> keyNIP;
    cout << "Masukkan Nama: ";
    cin.ignore(); 
    getline(cin, keyNama);

    int searchIndex;
    if (searchOption == 1) {
        searchIndex = SequentialSearch(data, size, keyNIP, keyNama);
    } else if (searchOption == 2) {
        searchIndex = BinarySearch(data, size, keyNIP, keyNama);
    } else {
        cout << "Metode pencarian tidak valid.\n";
        return 0;
    }

    if (searchIndex != -1) {
        cout << "Data ditemukan pada indeks " << searchIndex << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    int insertOption;
    cout << "\nPilih opsi penyisipan:\n";
    cout << "1. Sebelum data kunci\n";
    cout << "2. Sesudah data kunci\n";
    cout << "3. Tidak melakukan penyisipan\n";
    cout << "Pilihan: ";
    cin >> insertOption;

    if (insertOption == 1 || insertOption == 2) {
        Pegawai insertData;
        cout << "Masukkan data yang ingin disisipkan:\n";
        cout << "NIP: ";
        cin >> insertData.NIP;
        cout << "Nama: ";
        cin.ignore(); 
        getline(cin, insertData.Nama);
        cout << "Alamat: ";
        getline(cin, insertData.Alamat);
        cout << "Golongan: ";
        cin >> insertData.Golongan;

        if (insertOption == 1) {
            InsertElement(data, size, insertData, searchIndex);
        } else {
            InsertElement(data, size, insertData, searchIndex + 1);
        }
    }

    int deleteOption;
    cout << "\nPilih opsi penghapusan:\n";
    cout << "1. Hapus data kunci\n";
    cout << "2. Tidak melakukan penghapusan\n";
    cout << "Pilihan: ";
    cin >> deleteOption;

    if (deleteOption == 1) {
        DeleteElement(data, size, keyNIP, keyNama);
    }

    cout << "\nData setelah proses penyisipan dan penghapusan:\n";
    DisplayPegawaiList(data, size);

    return 0;
}
