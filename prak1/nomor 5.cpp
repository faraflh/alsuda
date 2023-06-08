#include <iostream>
#include <cmath>

using namespace std;

struct {
    int a,b,c,d;
}

bil;

void jumlah() {
    cout << "\nPenambahan Bilangan Kompleks \n";
    int hasil1 = (bil.a + bil.c);
    int hasil2 = (bil.b + bil.d);
    cout << "Hasil penambahan dari \n(" << bil.a << " + " << bil.b << "i) + (" << bil.c << " + " << bil.d << "i) = (" << bil.a << " + " << bil.c << ") + (" << bil.b << " + " << bil.d << ")i adalah " << hasil1 << " + " << hasil2 << "i";
}

void kurang() {
    cout << "\n\nPengurangan Bilangan Kompleks \n";
    int hasil1 = (bil.a - bil.c);
    int hasil2 = (bil.b - bil.d);
    cout << "Hasil pengulangan dari \n(" << bil.a << " + " << bil.b << "i) - (" << bil.c << " + " << bil.d << "i) = (" << bil.a << " - " << bil.c << ") + (" << bil.b << " - " << bil.d << ")i adalah " << hasil1 << " + " << hasil2 << "i";
}

void kali() {
    cout << "\n\nPerkalian Bilangan Kompleks \n";
    int hasil1 = (bil.a * bil.c) - (bil.b * bil.d);
    int hasil2 = (bil.a * bil.d) + (bil.b * bil.c);
    cout << "Hasil perkalian dari \n(" << bil.a << " + " << bil.b << "i) * (" << bil.c << " + " << bil.d << "i) = (" << bil.a << "." << bil.c << " - " << bil.b << "." << bil.d << ") + (" << bil.a << "." << bil.d << " + " << bil.b << "." << bil.c << ")i adalah " << hasil1 << " + " << hasil2 << "i";
}

void bagi() {
    cout << "\n\nPembagian Bilangan Kompleks \n";
    int hasil1 = (bil.a * bil.c) + (bil.b * bil.d);
    int hasil2 = (bil.a * bil.a) + (bil.b * bil.b);
    int hasil3 = ((bil.b * bil.c) - (bil.a * bil.d));
    int hasil4 = (bil.c * bil.c) + (bil.d * bil.d);
    cout << "Hasil pembagian dari \n(" << bil.a << " + " << bil.b << "i) / (" << bil.c << " + " << bil.d << "i) = [(" << bil.a << "." << bil.c << " + " << bil.b << "." << bil.d << ") / (" << bil.a << "² + " << bil.b << "²)] + [(" << bil.b << "." << bil.c << " - " << bil.a << "." << bil.d << ") / (" << bil.c << "² + " << bil.d <<  "²)]i adalah (" << hasil1 << "/" << hasil2 << ")+ (" << hasil3 << "/" <<  hasil4 << ")i";
}

int main()
{
    char op;
    cout << "Masukkan bilangan a : "; cin >> bil.a;
    cout << "Masukkan bilangan b : "; cin >> bil.b;
    cout << "Masukkan bilangan c : "; cin >> bil.c;
    cout << "Masukkan bilangan d : "; cin >> bil.d;
	cout << "\nMulai hitung? (y/t): "; cin >> op;
    
    if(op == 'y'){
        jumlah();
        kurang();
        kali();
        bagi();
    }
    else
    exit(1);
}

