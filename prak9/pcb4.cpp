#include <cmath>
#include <iostream>
using namespace std;

int prime(int number, int index) {
    if (index == 1)
        return 1;
    else if (number % index == 0) {
        return 0;
    }

    else
        return prime(number, --index);
}

int main() {
    int num;
    cout << "Masukkan bilangan sampai dengan : ";
    cin >> num;
    cout << "Deret bilangan prima : ";
    for (int i = 1; i <= num; i++) {
        if (prime(i, (int)sqrt(i))) {
            cout << i << " ";
        }
    }
}