#include <iostream>

using namespace std;

int main () {
    int i, j, k, m, n, m1[10][10], m2[10][10], hasil[10][10]; 
    cout << "Masukkan jumlah baris matriks: ";
    cin >> m;
    cout << "Masukkan jumlah kolom matriks: ";
    cin >> n;
    
    cout << "Masukkan elemen matrix pertama: \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
	       cin >> m1[i][j];
	    }
    }
    
    cout << "Masukkan elemen matrix kedua: \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
	        cin >> m2[i][j];
	    }
    }
    
    cout << "\nHasil Penjumlahan: \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
	       hasil[i][j] = m1[i][j] + m2[i][j];
	       cout << hasil[i][j] << "\t";
	    } cout << endl;
    }
    
    cout << "\nHasil Pengurangan: \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
	       hasil[i][j] = m1[i][j] - m2[i][j];
	       cout << hasil[i][j] << "\t";
	    } cout << endl;
    } 
    
    cout << "\nHasil Perkalian: \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
	       hasil[i][j] = 0;
	       for(k = 0; k < n; k++) {
	           hasil[i][j] += m1[i][k]*m2[k][j];
	       }    
	       cout << hasil[i][j] << "\t";
	    } cout << endl;
    } 
}

