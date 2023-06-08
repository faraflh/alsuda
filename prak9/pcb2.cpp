#include <iostream>
using namespace std;

int faktorial(int x, int a) {
    if (x == 1)
        return a;
    else
        return faktorial(x - 1, x*a);
}

int main() {
    int N;
    cout << "Masukkan N = ";
    cin >> N;
    cout << "Hasil " << N << "! = " << faktorial(N,1) << endl;
}