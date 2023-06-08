#include <cstdlib>
#include <ctime>
#include <iostream>
#define MAX 10

using namespace std;

int SequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int BinarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; 
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}

void InsertElement(int arr[], int &size, int key, int position) {
    if (position < 0 || position > size) {
        cout << "Posisi penyisipan tidak valid.\n";
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1]; 
    }

    arr[position] = key;
    size++;
}

void DeleteElement(int arr[], int &size, int key) {
    int position = SequentialSearch(arr, size, key);
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
    srand(time(0));
    int arr[MAX];
    int size = 0; 

    cout << "DATA : ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100; 
        cout << arr[i] << " ";
        size++; 
    }

    int key;
    cout << "\nKunci : ";
    cin >> key;

    int sequentialIndex = SequentialSearch(arr, size, key);
    if (sequentialIndex != -1) {
        cout << "Data ditemukan pada posisi " << sequentialIndex << " (Sequential Search)\n";
    } else {
        cout << "Data tidak ditemukan (Sequential Search)\n";
    }

    int binaryIndex = BinarySearch(arr, size, key);
    if (binaryIndex != -1) {
        cout << "Data ditemukan pada posisi " << binaryIndex << " (Binary Search)\n";
    } else {
        cout << "Data tidak ditemukan (Binary Search)\n";
    }

    int insertKey, insertPosition;
    cout << "\nData yang ingin disisipkan : ";
    cin >> insertKey;
    cout << "Posisi penyisipan : ";
    cin >> insertPosition;
    InsertElement(arr, size, insertKey, insertPosition);

    cout << "DATA setelah penyisipan : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int deleteKey;
    cout << "\nData yang ingin dihapus : ";
    cin >> deleteKey;
    DeleteElement(arr, size, deleteKey);

    cout << "DATA setelah penghapusan : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
