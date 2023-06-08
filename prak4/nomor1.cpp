#include <cstdlib>
#include <iostream>
using namespace std;

void deret1(int *n) {
    int *C = (int *)malloc(sizeof(int) * *n);
    cout << "\nDeret C : ";
    for (int i = 0; i < *n; i++) {
        if (i == 0) {
            C[i] = 1;
        } else {
            C[i] = 2 * C[i - 1] + 1;
        }
        cout << C[i] << " ";
    }
    free(C);
}
void deret2(int *n) {
    int *S = (int *)malloc(sizeof(int) * *n);
    cout << "\n\nDeret S : ";
    for (int i = 1; i < *n; i++) {
        if (i == 1) {
            S[i] = 0;
        } else {
            S[i] = S[i - 1] + i - 1;
        }
        cout << S[i] << " ";
    }
    free(S);
}
int main() {
    int n;
    cout << "Masukkan n : ";
    cin >> n;
    deret1(&n);
    deret2(&n);
    cout << endl;
}