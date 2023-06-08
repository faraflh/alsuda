#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int *n;
    cout << "Masukkan jumlah bilangan fibonacci : ";
    cin >> *n;
    int *fibo = (int *)malloc(sizeof(int) * *n);
    if (fibo == NULL) {
        cout << "Error on malloc\n";
        exit(0);
    } else {
        fibo[0] = 0;
        fibo[1] = 1;
        for (int i = 2; i < *n; i++) {
          fibo[i] = fibo[i - 2] + fibo[i - 1];
        }
        cout << *n << " bilangan fibonacci pertama adalah : \n";
        for (int i = 0; i < *n; i++) {
          cout << fibo[i] << " ";
        }
        cout << endl;
    }
    free(fibo);
}
