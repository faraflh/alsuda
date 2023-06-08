#include <iostream>
#include <cstdlib>
#define MAX 10

using namespace std;

int Data[MAX];

void Tukar(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int L, int R) {
    int i, j, x;
    x = Data[(L + R) / 2];
    i = L;
    j = R;
    while (i <= j) {
        while (Data[i] < x)
            i++;
        while (Data[j] > x)
            j--;
        if (i <= j) {
            Tukar(&Data[i], &Data[j]);
            i++;
            j--;
        }
    }
    if (L < j)
        QuickSort(L, j);
    if (i < R)
        QuickSort(i, R);
}

int BinarySearch(int x) {
    int L = 0, R = MAX - 1, m;
    bool ketemu = false;
    while ((L <= R) && (!ketemu)) {
        m = (L + R) / 2;
        if (Data[m] == x)
            ketemu = true;
        else if (x < Data[m])
            R = m - 1;
        else
            L = m + 1;
    }
    if (ketemu)
        return m;
    else
        return -1;
}

int main() {
    int i;
    srand(0);
    cout << "DATA : ";
    for (i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << Data[i] << " ";
    }
    QuickSort(0, MAX - 1);
    int Kunci;
    cout << "\nKunci : ";
    cin >> Kunci;
    int ketemu = BinarySearch(Kunci);
    if (ketemu > 0)
        cout << "Data ditemukan pada posisi " << ketemu;
    else
        cout << "Data tidak ditemukan";
}
