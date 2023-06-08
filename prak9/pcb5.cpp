#include <iostream>
using namespace std;

int pangkat(int x, int y) {
    if (y == 0)
        return 1;
    else
        return x*pangkat(x,y - 1);
}

int main() {
    int x, y;
    cout << "Bilangan x pangkat y : ";
    cin >> x >> y;
    cout << x << " pangkat " << y << " = " << pangkat(x,y);
}