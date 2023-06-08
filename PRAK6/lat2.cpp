#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int k;
    char h;
    int pang;
    Node *next;
};
class poli {
public:
    Node *head;
    Node *tail;
    void addHead(int x, char y, int z) {
        Node *temp = new Node();
        head = temp;
        tail = temp;
        temp->k = x;
        temp->h = y;
        temp->pang = z;
        temp->next = NULL;
    }
    
    void insert(int x, char y, int z) {
        Node *temp = new Node();
        Node *find = new Node();
        Node *before = new Node();
        temp->k = x;
        temp->h = y;
        temp->pang = z;
        find = head;
        if (temp->pang > find->pang) {
            temp->next = find;
            head = temp;
        } else {
            while (find != NULL && temp->pang < find->pang) {
                before = find;
                find = find->next;
            }
            before->next = temp;
            temp->next = find;
        }
    }
    void hapus(int x, int y) {
        Node *hapus = new Node();
        Node *find = new Node();
        find = head;
        if (find->k == x && find->pang == y) {
            head = find->next;
            delete find;
        } else {
            while (find->k != x && find->pang != y) {
                hapus = find;
                find = find->next;
                if (find == NULL)
                    break;
            }
            if (find == NULL) {
            } else if (find->next == NULL) {
                hapus->next = NULL;
                delete find;
            } else {
                hapus->next = find->next;
                delete find;
            }
        }
    }
    void print() {
        Node *temp = new Node();
        temp = head;
        while (temp != NULL) {
            if (temp->pang != 0 && temp->k != 1) {
                cout << temp->k << temp->h << "^" << temp->pang;
            } else if (temp->k == 1) {
                cout << temp->h << "^" << temp->pang;
            } else
                cout << temp->k;
            if (temp->next != NULL) {
                cout << " + ";
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "";
        }
        cout << endl;
    }
};
poli p[3];
void ubah(int x) {
    int a, b, c;
    cout << "Pilih operasi : " << endl;
    cout << "1. Insert" << endl;
    cout << "2. Hapus" << endl;
    cout << "3. Exit" << endl;
    cout << "Pilihan : ";
    cin >> a;
    if (a == 1) {
        cout << "Masukkan Koefesien : ";
        cin >> b;
        cout << "Masukkan Pangkat : ";
        cin >> c;
        if (c == 0) {
            p[x].insert(b, '0', c);
        } else {
            p[x].insert(b, 'x', c);
        }
    } else if (a == 2) {
        cout << "Masukkan Koefesien : ";
        cin >> b;
        cout << "Masukkan Pangkat : ";
        cin >> c;
        p[x].hapus(b, c);
    } else if (a == 3) {
        exit(0);
    } else {
        cout << "Pilihan Tidak ada" << endl;
    }
}

int main() {
    int a, c, d;
    p[0].addHead(6, 'x', 8);
    p[0].insert(8, 'x', 7);
    p[0].insert(5, 'x', 5);
    p[0].insert(1, 'x', 3);
    p[0].insert(15, '0', 0);
    cout << "P1 = ";
    p[0].print();
    p[1].addHead(3, 'x', 9);
    p[1].insert(4, 'x', 7);
    p[1].insert(3, 'x', 4);
    p[1].insert(2, 'x', 3);
    p[1].insert(2, 'x', 2);
    p[1].insert(10, '0', 0);
    cout << "P2 = ";
    p[1].print();

    do {
        cout << "Pilih polinom : " << endl;
        cout << "1. P1" << endl;
        cout << "2. P2" << endl;
        cout << "Pilihan : ";
        cin >> a;

        ubah(a - 1);
        cout << endl;
        cout << "P1 = ";
        p[0].print();
        cout << "P2 = ";
        p[1].print();
        cout << endl;
    } while (a != 4);
}
