#include <cstdlib>
#include <ctime>
#include <iostream>
#define MAX 20
using namespace std;

void BubbleSortAsc(int arr[]) {
    int i = 0, j, temp;
    bool did_swap = true;
    while (i < MAX - 1 && did_swap) {
        for (j = 0; j < MAX - i - 1; j++) {
            did_swap = false;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                did_swap = true;
            }
        }
        i++;
    }
}

void BubbleSortDesc(int arr[]) {
    int i = 0, j, temp;
    bool did_swap = true;
    while (i < MAX - 1 && did_swap) {
        did_swap = false;  
        for (j = 0; j < MAX - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                did_swap = true;
            }
        }
        i++;
    }
}


int main() {
    int data_awal[MAX], data_urut[MAX];
    int i;
    time_t k1, k2;

    cout << "BUBBLE SORT FLAG ASCENDING\n";
    cout << "Sebelum pengurutan : \n";
    for (i = 0; i < MAX; i++) {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        cout << data_awal[i] << " ";
    }
    cout << "\nSetelah pengurutan : \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    time(&k1);
    BubbleSortAsc(data_urut);
    time(&k2);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";
    cout << "\nWaktu = " << k2 - k1 << endl;
    
    cout << "\nBUBBLE SORT FLAG DESCENDING\n";
    cout << "Sebelum pengurutan : \n";
    for (i = 0; i < MAX; i++) {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        cout << data_awal[i] << " ";
    }
    cout << "\nSetelah pengurutan : \n";
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
    time(&k1);
    BubbleSortDesc(data_urut);
    time(&k2);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";
    cout << "\nWaktu = " << k2 - k1 << endl;
}
