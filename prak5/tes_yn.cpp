#include <iostream>
using namespace std;

class Node {
public:
    int umur;
    string nama;
    Node *next;
};

class LinkedList {
public:
    Node *head;
    Node *tail;

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

    void insertDepan(string NAMA, int UMUR) {
        Node *temp = new Node();
        temp->nama = NAMA;
        temp->umur = UMUR;
        temp->next = head;
        temp->next = NULL;
        if (isEmpty() == 1) {
            head = tail = temp;
            tail->next = NULL;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void insertBelakang(int UMUR, string NAMA) {
        Node *temp = new Node();
        temp->umur = UMUR;
        temp->nama = NAMA;
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

    bool cari(string NAMA) {
        Node *current = head;
        while (current != NULL) {
            if (current->nama == NAMA) {
                cout << "\nNama yang dicari : " << current->nama << endl;
                cout << "Umur dari nama yang dicari : " << current->umur << endl;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << "nama \t:" << current->nama << endl;
            cout << "umur \t:" << current->umur << endl
                 << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int pil, umur;
    string nama;
    Node *current;
    LinkedList myList;
    system("cls");
    while (true) {
        cout << endl;
        cout << " 1. Insert Depan : " << endl;
        cout << " 2. Insert Akhir : " << endl;
        cout << " 3. Cari Data : " << endl;
        cout << " 4. Tampil Data : " << endl;
        cout << " 5. Exit " << endl;
        cout << endl;
        cout << " Masukan Pilihan : ";
        cin >> pil;
        switch (pil) {
        case 1:
            system("cls");
            {
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan umur : ";
                cin >> umur;
                myList.insertDepan(nama, umur);
                break;
            }
        case 2:
            system("cls");
            {
                cout << "Masukkan nama : ";
                cin >> nama;
                cout << "Masukkan umur : ";
                cin >> umur;
                myList.insertBelakang(umur, nama);
                break;
            }
        case 3:
            system("cls");
            {
                cout << "Masukkan nama : ";
                cin >> nama;
                myList.cari(nama);
                break;
            }
        case 4:
            system("cls");
            {
                cout << "Tampilkan semua data : \n";
                myList.display();
                break;
            }
        default:
            cout << "\n Terima Kasih!\n";
            exit(0);
            break;
        }
    }
}
