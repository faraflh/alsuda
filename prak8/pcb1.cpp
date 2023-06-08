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
        tail = NULL;
    }

    void addHead(int value, string Nama) {
        Node *temp = new Node();
        temp->absen = value;
        temp->nama = Nama;
        if (tail == NULL)
            head = tail = temp;
        tail->next = NULL;
        tail->prev = temp;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
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
        while (current != NULL) {
            cout << current->absen << ". " << current->nama << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int absen, absen2;
    string nama;
    LinkedList myList;
    char lagi;

    cout << "INSERT DATA SEBELUM SIMPUL TERTENTU\n";

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
    cout << "Data yang dimasukkan : " << endl;
    myList.display();
    cout << "Masukkan nomor absen yang ingin ditambah sebelumnya : ";
    cin >> absen2;
    cout << "Masukkan nomor absen : ";
    cin >> absen;
    cout << "Masukkan nama : ";
    cin >> nama;
    myList.addBfr(absen, nama, absen2);
    cout << endl;
    myList.display();
}
