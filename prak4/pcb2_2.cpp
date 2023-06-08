#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int i, a, n, m, f = 1;
    int *prima;
    int count = 0;
    cout << "Batas bilangan prima ? ";
    cin >> n;
    prima = (int *)malloc(n * sizeof(int));
    if (prima == NULL) {
        cout << "Pengalokasian Memori Gagal\n";
        return 0;
    } else {
        int pos = 0;
        for (a = 2; a < n; a++) {
            f = 1;
            for (i = 2; i <= a / 2; i++) {
                if (a % i == 0) {
                    f = 0;
                    break;
                }
            }
            if (f == 1) {
                prima[count] = a;
                count++;
            }
            for (int a = 0; a < count; a++) {
                cout << prima[a] << " ";
            }
        }
        cout << "\nMasukkan jumlah bilangan baru : ";
        cin >> m;
        prima = (int *)realloc(prima, m * sizeof(int));
        a = 0;
        for (a = 1; a < m; a++) {
            f = 0;
            i = 1;
            while (i <= a) {
                if (a % i == 0) {
                    f++;
                }
                i++;
            }
            if (f == 2) {
                *(prima + i) = a;
                cout << *(prima + i)<< " ";
                i++;
            }
        }
        free(prima);
    }
}