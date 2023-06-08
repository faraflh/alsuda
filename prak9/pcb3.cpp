#include <iostream>
using namespace std;

int fibo(int x) {
    if (x <= 0 || x <= 1)
        return x;
    else
        return fibo(x - 2) + fibo(x - 1);
}

int main() {
    int N;
    cout << "Masukkan jumlah deret = ";
    cin >> N;
    cout << "Deret fibonacci dari " << N << " = ";
    for (int i = 0; i < N; i++) {
        cout << fibo(i) << " ";
    }
}