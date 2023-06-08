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
        cout << "\n";
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
    int absen;
    string nama;
    LinkedList myList;
    char lagi;

    cout << "INSERT DATA DI AWAL\n";

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
