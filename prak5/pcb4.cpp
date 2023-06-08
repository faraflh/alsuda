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
        myList.addLast(absen, nama);
        cout << "Tambah data lagi? (y/t) : "; cin >> lagi;
        cout << endl;
        if (lagi != 'y' && lagi != 'Y') {
            break;
        }
    }
    cout << "Data yang dimasukkan : " << endl;
    myList.display();
}
