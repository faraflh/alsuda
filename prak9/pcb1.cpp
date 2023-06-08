#include <iostream>
using namespace std;

int faktorial(int x) {
    if (x == 1)
        return x;
    else
        return x * faktorial(x - 1);
}

int main() {
    int N;
    cout << "Masukkan N = ";
    cin >> N;
    cout << "Hasil " << N << "! = " << faktorial(N) << endl;
}