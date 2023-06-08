#include <iostream>
#define N 5
#define M 1000
using namespace std;

void Tampil(int data[N][N], const string& judul) {
    cout << judul << " = \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (data[i][j] >= M)
                cout << "M ";
            else
                cout << data[i][j] << " ";
        }
        cout << "\n";
    }
}

void Warshall(int Q[N][N], int P[N][N], int R[N][N]) {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
                if ((Q[i][k] + Q[k][j]) < Q[i][j]) {
                    Q[i][j] = Q[i][k] + Q[k][j];
                    if (R[k][j] == 0)
                        R[i][j] = k + 1;
                    else
                        R[i][j] = R[k][j];
                }
            }
}

int main() {
    int Beban[N][N] = {{M, 1, 3, M, M},
                       {M, M, 1, M, 5},
                       {3, M, M, 2, M},
                       {M, M, M, M, 1},
                       {M, M, M, M, M}};

    int Jalur[N][N] = {{0, 1, 1, 0, 0},
                       {0, 0, 1, 0, 1},
                       {1, 0, 0, 1, 0},
                       {0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0}};

    int Rute[N][N] = {{M, 0, 0, M, M},
                      {M, M, 0, M, 0},
                      {0, M, M, 0, M},
                      {M, M, M, M, 0},
                      {M, M, M, M, M}};

    Tampil(Beban, "Beban");
    Tampil(Jalur, "Jalur");
    Tampil(Rute, "Rute");

    Warshall(Beban, Jalur, Rute);

    cout << "Matriks setelah Algoritma Warshall : \n";
    Tampil(Beban, "Beban");
    Tampil(Jalur, "Jalur");
    Tampil(Rute, "Rute");
}
