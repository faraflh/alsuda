#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include<limits>
#define N 10

using namespace std;

float Penambahan(int A[], int B[], int x) {
    float hasil = 0;
    for(int i = 0; i < N; i++)
    hasil += (A[i] + B[i]) * pow(x,i);
    return hasil;
}

float Pengurangan(int A[],int B[],int x){
    float hasil = 0;
    for(int i = 0; i < N; i++)
    hasil += (A[i] - B[i]) * pow(x,i);
    return hasil;
}

float Perkalian(int A[],int B[],int x) {
    float hasil=0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
        hasil += A[i] * B[j] * (float) pow(x,(i+j));
    }
    return hasil;
}

float Penurunan(int A[],int x) {
    float hasil=0;
    for(int i = 0; i < N; i++)
    hasil += A[i] * i * (float) pow(x,i-1);
    return hasil;
}

int main() {
    int P1[N]={15,0,0,1,0,5,0,8,6,0};
    int P2[N]={10,0,2,2,3,0,0,4,0,3};
    int P3[N]={5,0,1,0,0,0,0,0,0,0};
    int hasiltambah, hasilkurang , hasilkali, hasilturunan;
    char pilih;
    int x;
    
    do{  
        system("cls");
        cout << "Masukkan nilai x : "; cin >> x;
        while(1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Hanya masukkan angka : "; cin >> x;
            }
            if(!cin.fail())
            break;
        }
        cout << endl;
		hasiltambah = Penambahan(P1,P2,x);
            cout <<"Hasil tambah: " <<  hasiltambah << endl;
            
        hasilkurang = Pengurangan(P1,P2,x);
            cout << "Hasil kurang: " << hasilkurang << endl;
            
        hasilkali = Perkalian(P1,P3,x);
            cout << "Hasil kali: " << hasilkali << endl;
            
        hasilturunan = Penurunan(P2,x);
            cout << "Hasil turunan: " << hasilturunan << endl;
            
        cout << "\nLanjutkan operasi? (y/t) : ";
        cin >> pilih;
    } while (pilih == 'y' || pilih == 'Y');
}

