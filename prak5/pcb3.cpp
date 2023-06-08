#include <iostream>
using namespace std;

class Node {
public:
    int absen;
    string nama;
    Node *next;
};

class LinkedList {
public:
    Node *head;
    LinkedList() {
        head = NULL;
    }

    void addHead(int value, string Nama) {
        Node *baru = new Node();
        baru->absen = value;
        baru->nama = Nama;
        baru->next = head;
        head = baru;
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << "Nomor absen : " << current->absen << endl;
            cout << "Nama : " << current->nama << endl;
            current = current->next;
            cout << endl;
        }
    }

    void Find(int value) {
        Node *find = head;
        if (find->absen == value) {
            cout << "Nomor absen : " << find->absen << endl;
            cout << "Nama : " << find->nama;
            cout << "\nData di atas adalah data paling depan ";
            return;
        }
        while (find != NULL) {
            if (find->absen == value) {
                cout << "Nomor absen : " << find->absen << endl;
                cout << "Nama : " << find->nama;
            }
            find = find->next;
        }
    }
};

int main() {
    int absen;
    string nama;
    LinkedList myList;
    char lagi;

    while (true) {
        cout << "Masukkan nomor absen : ";
        cin >> absen;
        cout << "Masukkan nama : ";
        cin >> nama;
        myList.addHead(absen, nama);
        cout << "Tambah data lagi? (y/t) : ";
        cin >> lagi;
        cout << endl;
        if (lagi != 'y' && lagi != 'Y') {
            break;
        }
    }

    myList.display();

    cout << "Masukkan nomor absen yang ingin dicari : ";
    cin >> absen;
    myList.Find(absen);
}
