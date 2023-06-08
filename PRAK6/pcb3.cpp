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

    void addBfr(int value, string Nama, int absen2) {
        Node *temp = new Node();
        Node *stl = new Node();
        Node *current = head;
        while (current->absen != absen2) {
            stl = current;
            current = current->next;
        }
        temp->next = current;
        temp->absen = value;
        temp->nama = Nama;
        stl->next = temp;
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << current->absen << ". " << current->nama << endl;
            current = current->next;
        }
    }
};

int main() {
    int absen, absen2;
    string nama;
    LinkedList myList;
    char lagi;

    while (true) {
        cout << "Masukkan nomor absen : ";
        cin >> absen;
        cout << "Masukkan nama : ";
        cin >> nama;
        myList.add(absen, nama);
        cout << "Tambah data lagi? (y/t) : ";
        cin >> lagi;
        cout << endl;
        if (lagi != 'y' && lagi != 'Y') {
            break;
        }
    }
    cout << "Data yang dimasukkan : " << endl;
    myList.display();
    cout << "\nMasukkan nomor absen yang ingin ditambah sebelumnya : ";
    cin >> absen2;
    cout << "Masukkan nomor absen : ";
    cin >> absen;
    cout << "Masukkan nama : ";
    cin >> nama;
    myList.addBfr(absen, nama, absen2);
    cout << endl;
    myList.display();
}
