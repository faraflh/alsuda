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

int main() {
    srand(time(0));
    int arr[MAX];

    cout << "DATA : ";
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % 100; 
        cout << arr[i] << " ";
    }

    int key;
    cout << "\nKunci : ";
    cin >> key;

    int sequentialIndex = SequentialSearch(arr, MAX, key);
    if (sequentialIndex != -1) {
        cout << "Data ditemukan pada posisi " << sequentialIndex << " (Sequential Search)\n";
    } else {
        cout << "Data tidak ditemukan (Sequential Search)\n";
    }
    int binaryIndex = BinarySearch(arr, MAX, key);
    if (binaryIndex != -1) {
        cout << "Data ditemukan pada posisi " << binaryIndex << " (Binary Search)\n";
    } else {
        cout << "Data tidak ditemukan (Binary Search)\n";
    }
}
