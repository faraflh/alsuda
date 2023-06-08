#include <iostream>
#include <cstdlib>
#define size 12
using namespace std;

int biner(int a[], int x, int low, int high) {
    int mid;
    if (low > high)
        return -1;
    mid = (low+high)/2;
    if (x == a[mid])
        return (mid);
    else if (x < a[mid])
        biner(a, x, low, mid-1);
    else    
        biner(a, x, mid+1, high);
}

int main() {
    int num, i, key, pos, low, high, list[size];
    cout << "Masukkan Batas Data : ";
    cin >> num;
    cout << "Masukkan data : ";
    for (i = 0; i < num; i++)
        cin >> list[i];
    low = 0;
    high = num-1;
    cout << "Data yang dicari  : ";
    cin >> key;
    pos = biner(list, key, low, high);
    if (pos != -1)
        cout << "Data " << key << " berada pada index ke-" << pos;
    else    cout << "Data tidak ditemukan";
}