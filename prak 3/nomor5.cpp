#include <iostream>
using namespace std;

string dataNama[10], resultNama[10];
int dataNilai[10], resultNilai[10];
int i = 0, totalHasil = 0;

void insert(string nama, int nilai) {
    dataNama[i] = nama;
    dataNilai[i] = nilai;
    i++;
}
void pop() {
    int temp = dataNilai[0];
    int x;
    for (int j = 1; j < i; j++) {
        if (temp < dataNilai[j]) {
            temp = dataNilai[j];
            x = j;
        }
    }
    resultNama[totalHasil] = dataNama[x];
    resultNilai[totalHasil] = dataNilai[x];
    dataNama[x] = "Null";
    dataNilai[x] = -1;
    totalHasil++;
}
void print() {
    for (int j = 0; j < totalHasil; j++) {
        cout <<resultNama[j] << "\t: " << resultNilai[j] << endl;
    }
}
int main() {
    insert("Andi", 70);
    insert("Budi", 85);
    insert("Candra", 80);
    pop();
    insert("Didik", 90);
    insert("Edi", 85);
    pop();
    pop();
    insert("Fanda", 75);
    pop();
    print();
}