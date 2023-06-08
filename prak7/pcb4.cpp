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
    cout << "Data yang dimasukkan : " << endl;
    myList.display();
    cout << "\nMasukkan nomor absen yang ingin dihapus : ";
    cin >> absen;
    myList.delPos(absen);
    cout << endl;
    myList.display();
}
