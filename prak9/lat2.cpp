#include <iostream>
#include <cstring>
using namespace std;

void kombi(string x, int a, int b) {
    if (a == 0)
        cout << x << " ";
    else
        for (int i = 97; i < 97 + b; i++) {
            kombi(x+(char) i, a - 1, b);
        }
}

int main() {
    int N;
    cout << "Masukkan jumlah karakter : ";
    cin >> N;
    kombi("", N, N);
}