#include <iostream>
#include <cstdlib>
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

    void add(int value, string Nama) {
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

    void delHead() {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << current->absen << ". " << current->nama << endl;
            current = current->next;
        }
        cout << endl;
    }

};

int main() {
    int pilih, absen;
    string nama;
    LinkedList myList;
    char lagi;

    while (true) {
        cout << "MENU : " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Hapus" << endl;
        cout << "3. Tampilkan Data" << endl;
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
            myList.add(absen, nama);
            cout << endl;
            break;

        case 2:
            system("cls");
            myList.display();
            cout << "Menghapus data...\n";
            myList.delHead();
            myList.display();
            break;

        case 3:
            system("cls");
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

//how to read string input with white space c++?