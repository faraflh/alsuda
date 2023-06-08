#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define MAX 20

using namespace std;

void Merge(int arr[], int left, int median, int right, bool ascending) {
    int temp[MAX];
    int kiri1, kanan1, kiri2, kanan2, i, j;
    kiri1 = left;
    kanan1 = median;
    kiri2 = median + 1;
    kanan2 = right;
    i = left;

    if (ascending) {
        while ((kiri1 <= kanan1) && (kiri2 <= kanan2)) {
            if (arr[kiri1] <= arr[kiri2]) {
                temp[i] = arr[kiri1];
                kiri1++;
            }
            else {
                temp[i] = arr[kiri2];
                kiri2++;
            }
            i++;
        }
    }
    else {
        while ((kiri1 <= kanan1) && (kiri2 <= kanan2)) {
            if (arr[kiri1] >= arr[kiri2]) {
                temp[i] = arr[kiri1];
                kiri1++;
            }
            else {
                temp[i] = arr[kiri2];
                kiri2++;
            }
            i++;
        }
    }

    while (kiri1 <= kanan1) {
        temp[i] = arr[kiri1];
        kiri1++;
        i++;
    }
    while (kiri2 <= kanan2) {
        temp[i] = arr[kiri2];
        kiri2++;
        i++;
    }
    j = left;
    while (j <= right) {
        arr[j] = temp[j];
        j++;
    }
}

void MergeSort(int arr[], int l, int r, bool ascending) {
    int med;
    if (l < r) {
        med = (l + r) / 2;
        MergeSort(arr, l, med, ascending);
        MergeSort(arr, med + 1, r, ascending);
        Merge(arr, l, med, r, ascending);
    }
}

int main() {
    int data_awal[MAX], data_urut[MAX];
    int i;

    cout << "Sebelum pengurutan : \n";
    for (i = 0; i < MAX; i++) {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        cout << data_awal[i] << " ";
    }
    cout << "\n\nSetelah pengurutan (Ascending): \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];

    auto start = chrono::high_resolution_clock::now();
    MergeSort(data_urut, 0, MAX - 1, true);
    auto end = chrono::high_resolution_clock::now();

    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";
    cout << "\n";

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9; 

    cout << "Waktu = " << time_taken << " nanosekon\n";

    cout << "\nSetelah pengurutan (Descending): \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];

    start = chrono::high_resolution_clock::now();
    MergeSort(data_urut, 0, MAX - 1, false);
    end = chrono::high_resolution_clock::now();

    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";
    cout << "\n";

    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9; 
    cout << "Waktu = " << time_taken << " nanosekon\n";

    return 0;
}
