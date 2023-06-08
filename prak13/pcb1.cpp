#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

using namespace std;

int Data[MAX];

int SequentialSearch(int x) {
    int i = 0;
    bool ketemu = false;
    while ((!ketemu) && (i < MAX)) {
        if (Data[i] == x)
            ketemu = true;
        else
            i++;
    }
    if (ketemu)
        return i;
    else
        return -1;
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

    int ketemu = SequentialSearch(Kunci);
    if (ketemu >= 0)
        cout << "Data ditemukan pada posisi " << ketemu;
    else
        cout << "Data tidak ditemukan";
}
