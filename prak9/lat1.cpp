#include <iostream>
using namespace std;

int pascal(int x, int y) {
    if (y == 0 || y == x)
        return 1;
    else
        return pascal(x - 1, y - 1) + pascal(x - 1, y);
}

int main() {
    int x, y, batas = 6;
    int spasi = batas;
    for (int i = 0; i < batas; i++) {
        cout << "F" << i + 1;
        for (int j = 0; j <= spasi; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << pascal(i,j) << " ";
        }
        cout << endl;
        spasi--;
    }
}