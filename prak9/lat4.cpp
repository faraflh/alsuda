#include <iostream>
using namespace std;

void menara(int disk, char pasak1, char pasak2, char tujuan) {
    if (disk == 0)
        return;
    else
        menara(disk-1, pasak1, tujuan, pasak2);
        cout << "Pindahkan disk " << disk << " dari pasak " << pasak1 << " ke pasak " << pasak2 << endl;
        menara(disk-1, tujuan, pasak2, pasak1);
}

int main() {
    int N;
    cout << "Jumlah disk : ";
    cin >> N;
    menara(N,'A', 'C', 'B');
}