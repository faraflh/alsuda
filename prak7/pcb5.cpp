#include <iostream>
#include <cstdlib>
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

    void delPos(int value) {
        Node *del = head;
        Node *rear = tail;
        Node *current;
        if (del->absen == value) {
            head = del->next;
            head->prev = NULL;
            cout << "Data yang dihapus adalah data pertama.";
            free(del);
        } else {
            while (del->absen != value) {
                current = del;
                del = del->next;
            }
            current->next = del->next;
            current->prev = del->prev;
            free(del);
        }
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
        cout << "1. Insert Depan" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Cari Data" << endl;
        cout << "4. Hapus" << endl;
        cout << "5. Exit";
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
            myList.display();
            break;

        case 3:
            system("cls");
            cout << "Masukkan nomor absen yang ingin dicari : ";
            cin >> absen;
            myList.Find(absen);
            cout << endl;
            break;

        case 4:
            system("cls");
            myList.display();
            cout << "\nMasukkan nomor absen yang ingin dihapus : ";
            cin >> absen;
            cout << "Menghapus data...\n";
            myList.delPos(absen);
            myList.display();
            break;

        case 5:
            exit(0);

        default:
            exit(0);
            break;
        }
    }
}
