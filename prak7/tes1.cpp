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

    void delPos(int value) {
        Node *temp = head;
        if (temp != NULL && temp->absen == value) {
            head = temp->next;
            cout << "Data yang dihapus adalah data pertama.";
            free(temp);
            return;
        } else {
            Node *current;
            while (temp != NULL && temp->absen != value) {
                current = temp;
                temp = temp->next;
            }
            if (!temp) {
                cout << "Nomor absen salah" << endl;
                return;
            }
            current->next = temp->next;
            free(temp);
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
    cout << "\nMasukkan nomor absen yang ingin dihapus : ";
    cin >> absen;
    myList.delPos(absen);
    cout << endl;
    myList.display();
}
