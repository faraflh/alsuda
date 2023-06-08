#include <iostream>
#include <stack>
#define N 6
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

void FindRoute(int start, int end, int R[N][N]) {
    stack<int> routeStack;
    routeStack.push(end);

    while (start != end) {
        end = R[start - 1][end - 1];
        routeStack.push(end);
    }

    cout << "Route " << start << "-" << routeStack.top() << "?\n";
    while (!routeStack.empty()) {
        cout << routeStack.top();
        routeStack.pop();
        if (!routeStack.empty())
            cout << "-";
    }
    cout << " with a minimum cost of " << R[start - 1][end - 1] << endl;
}

int main() {
    int Beban[N][N] = {{M, 4, 2, M, M, M},
                       {4, M, 1, 5, M, M},
                       {2, 1, M, 8, 10, M},
                       {M, 5, 8, M, 2, 6},
                       {M, M, 10, 2, M, 3},
                       {M, M, M, 6, 3, M}};

    int Jalur[N][N] = {{0, 1, 1, 0, 0, 0},
                       {1, 0, 1, 1, 0, 0},
                       {1, 1, 0, 1, 1, 0},
                       {0, 1, 1, 0, 1, 1},
                       {0, 0, 1, 1, 0, 1},
                       {0, 0, 0, 1, 1, 0}};

    int Rute[N][N] = {{M, 0, 0, M, M, M},
                      {0, M, 0, 0, M, M},
                      {0, 0, M, 0, 0, M},
                      {M, 0, 0, M, 0, 0},
                      {M, M, 0, 0, M, 0},
                      {M, M, M, 0, 0, M}};

    Tampil(Beban, "Beban");
    Tampil(Jalur, "Jalur");
    Tampil(Rute, "Rute");

    Warshall(Beban, Jalur, Rute);

    cout << "Matriks setelah Algoritma Warshall : \n";
    Tampil(Beban, "Beban");
    Tampil(Jalur, "Jalur");
    Tampil(Rute, "Rute");

    FindRoute(1, 5, Rute);
}
