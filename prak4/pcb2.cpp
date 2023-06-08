#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int *prima, n, m, i, x = 0, temp, f;
    cout << "Masukkan banyak bilangan prima : ";
    cin >> n;
    prima = (int *)malloc(n * sizeof(int));
    if (prima == NULL) {
        cout << "Pengalokasian Memori Gagal\n";
        exit(0);
    } else {
        for (temp = 1; x < n; temp++) {
            f = 0;
            i = 1;
            while (i <= temp) {
                if (temp % i == 0) {
                    f++;
                }
                i++;
            }
            if (f == 2) {
                *(prima + x) = temp;
                cout << *(prima + x) << " ";
                x++;
            }
        }
    }
    cout << "\nMasukkan banyak bilangan prima baru : ";
    cin >> m;
    prima = (int *)realloc(prima, m * sizeof(int));
    x = 0;
    for (temp = 1; x < m; temp++) {
        f = 0;
        i = 1;
        while (i <= temp) {
            if (temp % i == 0) {
                f++;
            }
            i++;
        }
        if (f == 2) {
            *(prima + x) = temp;
            cout << *(prima + x) << " ";
            x++;
        }
    }
    free(prima);
}
