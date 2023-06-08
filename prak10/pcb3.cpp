#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 20
using namespace std;

void SelectionSort(int arr[]) {
    int i, j, temp, min, min_id;
    i = 0;
    while (i < MAX - 1) {
        min_id = i;
        min = arr[i];
        for (j = i + 1; j < MAX; j++)
            if (arr[j] < min) {
                min = arr[j];
                min_id = j;
            }
        temp = arr[min_id];
        arr[min_id] = arr[i];
        arr[i] = temp;
        i++;
    }
}
int main() {
    int data_awal[MAX], data_urut[MAX];
    int i;
    time_t k1, k2;
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
    SelectionSort(data_urut);
    time(&k2);
    for (i = 0; i < MAX; i++)
        cout << data_urut[i] << " ";
    cout << "\nWaktu = " << k2 - k1 << endl;
}
