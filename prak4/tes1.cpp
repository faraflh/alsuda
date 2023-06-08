#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int *ptr, n, i;
    cout << "Masukkan jumlah nilai : ";
    cin >> n;
    ptr = (int *) malloc(n* sizeof(int));

    if(ptr == NULL){
        cout << "Error on malloc\n";
        exit(0);
    } else {
        for (int i = 0; i < n; i++) {
            cout << "Masukkan Bilangan ke " << i+1 << " :";
            cin >> n;
        }
        for (int i = 0; i < n; i++){
            cout << "Bilangan: \n" << i+1 << " " << n << endl;
        }
    }
    free(ptr);
}