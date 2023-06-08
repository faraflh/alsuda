#include <iostream>
using namespace std;

class Node {
public:
    int absen;
    string nama;
    Node *next, *prev;
};

class LinkedList {
public:
    Node *head, *tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    int isEmpty() {
        if (tail == NULL)
            return 1;
        else
            return 0;
    }

    void add(int value, string Nama) {
        Node *temp = new Node();
        temp->absen = value;
        temp->nama = Nama;
        if (isEmpty() == 1) {
            head = tail = temp;
            tail->next = NULL;
            tail->prev = temp;
        } else {
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    void addAfter(int value, string Nama, int absen2) {
        Node *temp = new Node();
        Node *current = head;
        temp->absen = value;
        temp->nama = Nama;
        while (current->absen != absen2) {
            current = current->next;
            if (current == NULL) {
                break;
            }
        }
        temp->next = current->next;
        temp->prev = current;
        current->next = temp;
    }

    void addBfr(int value, string Nama, int absen2) {
        Node *temp = new Node();
        Node *stl = new Node();
        Node *current = head;
        temp->absen = value;
        temp->nama = Nama;
        if (current->absen == absen2) {
            head = temp;
            temp->next = current;
            temp->prev = temp;
        } else {
            while (current->absen != absen2) {
                stl = current;
                current = current->next;
                if (current == NULL) {
                    break;
                }
            }
            stl->next = temp;
            current->prev = temp;
            temp->next = current;
        }
    }

    void display() {
        Node *current = head;
        if (isEmpty() == 0) {
            while (current != NULL) {
                cout << current->absen << ". " << current->nama << endl;
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int pilih, absen, absen2;
    string nama;
    LinkedList myList;
    char lagi;

    while (true) {
        cout << "MENU : " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Insert Setelah " << endl;
        cout << "3. Insert Sebelum " << endl;
        cout << "4. Tampilkan Data" << endl;
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
            myList.add(absen, nama);
            cout << endl;
            break;

        case 2:
            system("cls");
            cout << "Masukkan nomor absen yang ingin ditambah setelahnya : ";
            cin >> absen2;
            cout << "Masukkan nomor absen : ";
            cin >> absen;
            cout << "Masukkan nama : ";
            cin >> nama;
            myList.addAfter(absen, nama, absen2);
            cout << endl;
            break;

        case 3:
            system("cls");
            cout << "Masukkan nomor absen yang ingin ditambah sebelumnya : ";
            cin >> absen2;
            cout << "Masukkan nomor absen : ";
            cin >> absen;
            cout << "Masukkan nama : ";
            cin >> nama;
            myList.addBfr(absen, nama, absen2);
            cout << endl;
            break;

        case 4:
            system("cls");
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