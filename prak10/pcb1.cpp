#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 20

using namespace std;

int main() {
    int data_awal[MAX], data_urut[MAX];
    int i;

    cout << "Sebelum pengurutan : \n";
    for (i = 0; i < MAX; i++) {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        cout << data_awal[i] << " ";
    }
    cout << endl;
    for (i = 0; i < MAX; i++)
        data_urut[i] = data_awal[i];
}