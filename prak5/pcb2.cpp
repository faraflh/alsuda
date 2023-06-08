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
        Node *head, *tail;
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

        void display() {
            Node *current = head;
                while (current != NULL) {
                    cout << "Nomor absen : " << current->absen << endl;
                    cout << "Nama : " << current->nama << endl;
                    current = current->next;
                }
        }
};

int main() {
    int absen;
    string nama;
    LinkedList myList;
    char lagi;

    while(true) {
        cout << "Masukkan nomor absen : "; cin >> absen;
        cout << "Masukkan nama : "; cin >> nama;
        myList.addHead(absen, nama);
        cout << "Tambah data lagi? (y/t) : "; cin >> lagi;
        cout << endl;
        if (lagi != 'y' && lagi != 'Y') {
            break;
        }
    }
    cout << "Data yang dimasukkan : " << endl;
    myList.display();
}
