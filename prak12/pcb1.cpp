#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#define MAX 20

using namespace std;

int Partition(int arr[], int p, int r) {
    int i, j;
    int pivot, temp;
    pivot = arr[p];
    i = p;
    j = r;
    while (i <= j) {
        while (pivot < arr[j])
            j--;
        while (pivot > arr[i])
            i++;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
            i++;
        }
        else
            return j;
    }
    return j;
}

void QuickSortAsc(int arr[], int p, int r) {
    int q;
    if (p < r) {
        q = Partition(arr, p, r);
        QuickSortAsc(arr, p, q);
        QuickSortAsc(arr, q + 1, r);
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
    cout << "\nSetelah pengurutan : \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    
    auto start = chrono::high_resolution_clock::now();
    QuickSortAsc(data_urut, 0, MAX - 1);
    auto end = chrono::high_resolution_clock::now();
    
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";
    cout << "\n";
    
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9; 
    
    cout << "Waktu = " << time_taken << " nanosekon\n";
    
    return 0;
}
