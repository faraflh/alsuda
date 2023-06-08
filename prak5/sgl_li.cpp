#include <iostream>
using namespace std;

struct Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    public:
        Node *head;
        LinkedList() {
            head = NULL;
        }

        void insert(int value) {
            Node *temp = new Node();
            temp->data = value;
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
                    cout << current->data << " ";
                    current = current->next;
                }
               cout << endl;
        }
};

int main() {
    LinkedList myList;

    myList.insert(1);
    myList.insert(5);
    myList.insert(10);
    myList.insert(15);

    myList.display();
}