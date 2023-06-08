#include <iostream>
using namespace std;

int fibo(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        cout << n << " ";
        return(fibo(n-1) + fibo(n-2));
    }
}

int main() {
    int n, i, j = 0;
    cout << "Batas Deret : ";
    cin >> n;
    cout << "Deret Fibonacci : \n";
    for (i = 1; i <= n; i++)
    {
        cout << endl;
        cout << "f_" << i << " -> ";
        cout << fibo(j);
        cout << "\nnilai fibonacci : " << fibo(j);
        j++;
    }
    
    return 0;
}