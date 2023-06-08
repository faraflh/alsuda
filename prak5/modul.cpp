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
        Node *temp = new Node();
        temp->absen = value;
        temp->nama = Nama;
        temp->next = head;
        head = temp;
    }

    void addLast(int value, string Nama) {
        Node *temp = new Node();
        temp->absen = value;
        temp->nama = Nama;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << "Nomor absen : " << current->absen << endl;
            cout << "Nama : " << current->nama << endl;
            current = current->next;
        }
        cout << endl;
    }

    void Find(int value) {
        Node *find = head;
        if (find->absen == value) {
            cout << "Nomor absen : " << find->absen << endl;
            cout << "Nama : " << find->nama;
            cout << "\nData di atas adalah data paling depan " << endl;
            return;
        }
        while (find != NULL) {
            if (find->absen == value) {
                cout << "Nomor absen : " << find->absen << endl;
                cout << "Nama : " << find->nama << endl;
            }
            find = find->next;
            cout << endl;
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
        cout << "1. Insert awal " << endl;
        cout << "2. Insert akhir " << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Cari Data" << endl;
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
            cout << "Masukkan nomor absen : ";
            cin >> absen;
            cout << "Masukkan nama : ";
            cin >> nama;
            myList.addLast(absen, nama);
            cout << endl;
            break;

        case 3:
            system("cls");
            myList.display();
            break;

        case 4:
            system("cls");
            cout << "Masukkan nomor absen yang ingin dicari : ";
            cin >> absen;
            myList.Find(absen);
            cout << endl;
            break;

        case 5:
            exit(0);

        default:
            exit(0);
            break;
        }
    }
}