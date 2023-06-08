// Watchlist sgli
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int tahunRilis;
    string judulFilm, genre, kode;
    Node *next;
};

class LinkedList {
public:
    Node *head, *tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addHead(string judul, string genre, int value, string code) {
        Node *temp = new Node();
        temp->tahunRilis = value;
        temp->judulFilm = judul;
        temp->genre = genre;
        temp->next = head;
        temp->kode = code;
        head = temp;
    }

    void addLast(string judul, string genre, int value, string code) {
        Node *temp = new Node();
        temp->tahunRilis = value;
        temp->judulFilm = judul;
        temp->genre = genre;
        temp->kode = code;
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

    void addAfter(string judul, string genre, int value, string code, string kode2) {
        Node *temp = new Node();
        Node *current = head;
        temp->tahunRilis = value;
        temp->genre = genre;
        temp->judulFilm = judul;
        temp->kode = code;
        temp->next = NULL;
        while (current->kode != kode2) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }

    void addBfr(string judul, string genre, int value, string code, string kode2) {
        Node *temp = new Node();
        Node *stl = new Node();
        Node *current = head;
        if (current->kode == kode2) {
            temp->next = head;
            head = temp;
        } else {

            while (current->kode != kode2) {
                stl = current;
                current = current->next;
            }
            temp->next = current;
        }

        temp->judulFilm = judul;
        temp->genre = genre;
        temp->tahunRilis = value;
        temp->kode = code;
        stl->next = temp;
    }

    void delPos(string code) {
        Node *temp = head;
        if (temp != NULL && temp->kode == code) {
            head = temp->next;
            free(temp);
            return;
        } else {
            Node *current;
            while (temp != NULL && temp->kode != code) {
                current = temp;
                temp = temp->next;
            }
            if (!temp) {
                cout << "Kode film yang anda masukkan salah." << endl;
                return;
            }
            current->next = temp->next;
            free(temp);
        }
    }

    void Find(string code) {
        Node *find = head;
        while (find != NULL) {
            if (find->kode == code) {
                cout << "Judul        : " << find->judulFilm << endl;
                cout << "Genre        : " << find->genre << endl;
                cout << "Tahun Rilis  : " << find->tahunRilis << endl;
                cout << "Kode         : " << find->kode << endl
                     << endl;
            }
            find = find->next;
        }
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << "Judul        : " << current->judulFilm << endl;
            cout << "Genre        : " << current->genre << endl;
            cout << "Tahun Rilis  : " << current->tahunRilis << endl;
            cout << "Kode         : " << current->kode << endl
                 << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int pilih, tahunRilis, posisi;
    string judulFilm, genre, kode, kode2;
    LinkedList myList;
    char lagi;

    while (true) {
        cout << "\tWATCHLIST\n"
             << endl;
        cout << "MENU : " << endl;
        cout << "1. Insert Awal" << endl;
        cout << "2. Insert Setelah" << endl;
        cout << "3. Insert Sebelum" << endl;
        cout << "4. Insert Akhir" << endl;
        cout << "5. Hapus" << endl;
        cout << "6. Cari Film" << endl;
        cout << "7. Tampilkan List" << endl;
        cout << "8. Exit";
        cout << "\nPilih Menu : ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            system("cls");
            cin.ignore();
            cout << "Masukkan Judul Film : ";
            getline(cin, judulFilm);
            cout << "Masukkan Genre Film : ";
            getline(cin, genre);
            cout << "Masukkan Tahun Rilis : ";
            cin >> tahunRilis;
            cout << "Masukkan Kode Film : ";
            cin >> kode;
            myList.addHead(judulFilm, genre, tahunRilis, kode);
            cout << endl;
            break;

        case 2:
            system("cls");
            cout << "Masukkan kode film yang ingin ditambah setelahnya : ";
            cin >> kode2;
            cin.ignore();
            cout << "Masukkan Judul Film : ";
            getline(cin, judulFilm);
            cout << "Masukkan Genre Film : ";
            getline(cin, genre);
            cout << "Masukkan Tahun Rilis : ";
            cin >> tahunRilis;
            cout << "Masukkan Kode Film : ";
            cin >> kode;
            myList.addAfter(judulFilm, genre, tahunRilis, kode, kode2);
            cout << endl;
            break;

        case 3:
            system("cls");
            cout << "Masukkan kode film yang ingin ditambah sebelumnya : ";
            cin >> kode2;
            cin.ignore();
            cout << "Masukkan Judul Film : ";
            getline(cin, judulFilm);
            cout << "Masukkan Genre Film : ";
            getline(cin, genre);
            cout << "Masukkan Tahun Rilis : ";
            cin >> tahunRilis;
            cout << "Masukkan Kode Film : ";
            cin >> kode;
            myList.addBfr(judulFilm, genre, tahunRilis, kode, kode2);
            cout << endl;
            break;

        case 4:
            system("cls");
            cin.ignore();
            cout << "Masukkan Judul Film : ";
            getline(cin, judulFilm);
            cout << "Masukkan Genre Film : ";
            getline(cin, genre);
            cout << "Masukkan Tahun Rilis : ";
            cin >> tahunRilis;
            cout << "Masukkan Kode Film : ";
            cin >> kode;
            myList.addLast(judulFilm, genre, tahunRilis, kode);
            cout << endl;
            break;

        case 5:
            system("cls");
            myList.display();
            cout << "Masukkan kode film yang sudah ditonton : ";
            cin >> kode;
            cout << "Menghapus film dari watchlist...\n\n";
            myList.delPos(kode);
            myList.display();
            break;

        case 6:
            system("cls");
            cout << "Masukkan kode film yang ingin dicari : ";
            cin >> kode;
            myList.Find(kode);
            cout << endl;
            break;

        case 7:
            system("cls");
            myList.display();
            break;

        case 8:
            exit(0);

        default:
            exit(0);
            break;
        }
    }
}
