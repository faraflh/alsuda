#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int SequentialSearch(Node* head, int x) {
    Node* current = head;
    int pos = 0;
    while (current != nullptr) {
        if (current->data == x) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    srand(time(0));

    Node* head = nullptr;
    cout << "DATA: ";
    for (int i = 0; i < MAX; i++) {
        int value = rand() / 1000 + 1;
        insertNode(head, value);
        cout << value << " ";
    }

    int Kunci;
    cout << "\nKunci: ";
    cin >> Kunci;

    int ketemu = SequentialSearch(head, Kunci);
    if (ketemu >= 0)
        cout << "Data ditemukan pada posisi " << ketemu;
    else
        cout << "Data tidak ditemukan";

    // Dealokasi memori
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
