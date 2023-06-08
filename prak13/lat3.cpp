#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

using namespace std;

int Data[MAX];

int SequentialSearchRecursive(int x, int i) {
    if (i >= MAX)
        return -1;
    if (Data[i] == x)
        return i;
    return SequentialSearchRecursive(x, i + 1);
}

int main() {
    srand(time(0));
    cout << "DATA: ";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() / 1000 + 1;
        cout << Data[i] << " ";
    }

    int Kunci;
    cout << "\nKunci: ";
    cin >> Kunci;

    int ketemu = SequentialSearchRecursive(Kunci, 0);
    if (ketemu >= 0)
        cout << "Data ditemukan pada posisi " << ketemu;
    else
        cout << "Data tidak ditemukan";
}
