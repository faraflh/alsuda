#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char kata [20];
    int panjang_kata, i;
    cout << "Masukkan Kata : ";
    gets(kata);
    panjang_kata = strlen(kata);
    
    cout << "Kata dibalik : ";
    for (i = panjang_kata; i >= 1; i--) {
        char stack = kata[i-1];
        cout << stack;
    }
}
