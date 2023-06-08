#include <iostream>
#include <string.h> //librari yang digunakan untuk memproses string

using namespace std;

int main()
{
    char str[7] = {'p','e','n','s','i','t'};
    
    cout << "Ketik char : "; cin.getline(str,7);
    
    int jml = strlen(str); //menghitung jumlah char/string
    
    cout << "Hasil char dibalik : ";
    
    //loop untuk membalik array
    for (int i = jml-1; i>=0; i--)
    {
        cout << str[i];
    }
}
