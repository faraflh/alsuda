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

    void addAfter(int value, string Nama, int absen2) {
        Node *temp = new Node();
        Node *current = head;
        while (current->absen != absen2) {
            current = current->next;
        }
        temp->absen = value;
        temp->nama = Nama;
        temp->next = NULL;
        temp->next = current->next;
        current->next = temp;
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
        cout << "5. Hapus Data Tertentu" << endl;
        cout << "6. Exit";
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
            system("cls");
            cout << "Masukkan nomor absen yang ingin dihapus : ";
            cin >> absen;
            myList.delPos(absen);
            cout << endl;
            myList.display();
            break;

        case 6:
            exit(0);

        default:
            exit(0);
            break;
        }
    }
}