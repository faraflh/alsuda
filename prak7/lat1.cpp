#include <cstdlib>
#include <iostream>
using namespace std;

class Node {
public:
    int absen;
    string nama;
    Node *next;
    Node *prev;
};

class LinkedList {
public:
    Node *head;
    Node *tail;
    LinkedList() {
        head = NULL;
    }

    void addHead(int value, string Nama) {
        Node *temp = new Node();
        temp->absen = value;
        temp->nama = Nama;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }

    void delHead() {
        Node *del = head;
        head = head->next;
        head->prev = NULL;
        free(del);
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << current->absen << ". " << current->nama << endl;
            current = current->next;
        }
        cout << endl;
    }

    void Find(int value) {
        Node *find = head;
        if (find->absen == value) {
            cout << "Nomor absen : " << find->absen << endl;
            cout << "Nama : " << find->nama << endl;
            cout << "\nData di atas adalah data paling depan " << endl;
            return;
        }
        while (find != NULL) {
            if (find->absen == value) {
                cout << "Nomor absen : " << find->absen << endl;
                cout << "Nama : " << find->nama << endl;
            }
            find = find->next;
        }
    }
};

int main() {
    int pilih, absen;
    string nama;
    LinkedList myList;
    char lagi;

    while (true) {
        cout << "MENU : " << endl;
        cout << "1. Insert " << endl;
        cout << "2. Cari Data" << endl;
        cout << "3. Hapus" << endl;
        cout << "4. Exit";
        cout << "\nPilih Menu : ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            system("cls");
            cout << "Masukkan nomor absen : ";
            cin >> absen;
            cout << "Masukkan nama : ";
            cin >> nama;
            myList.addHead(absen, nama);
            cout << endl;
            break;

        case 2:
            system("cls");
            cout << "Masukkan nomor absen yang ingin dicari : ";
            cin >> absen;
            myList.Find(absen);
            cout << endl;
            break;

        case 3:
            system("cls");
            myList.display();
            cout << "Menghapus data...\n";
            myList.delHead();
            myList.display();
            break;

        case 4:
            exit(0);

        default:
            exit(0);
            break;
        }
    }
}
