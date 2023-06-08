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
    i = L;
    j = R;
    x = Data[(L + R) / 2];

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


int BinarySearchRecursive(int x, int L, int R) {
    if (L > R)
        return -1;
    int m = (L + R) / 2;
    if (Data[m] == x)
        return m;
    else if (x < Data[m])
        return BinarySearchRecursive(x, L, m - 1);
    else
        return BinarySearchRecursive(x, m + 1, R);
}


int BinarySearch(int x) {
    return BinarySearchRecursive(x, 0, MAX - 1);
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
    if (ketemu >= 0)
        cout << "Data ditemukan pada posisi " << ketemu;
    else
        cout << "Data tidak ditemukan";
}
