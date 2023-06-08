#include <iostream>
#include <queue>
using namespace std;

#define max 5
int top = 0;
string data[max];

bool isFull() {
    if (top >= max){
        return true;
    }else{
        return false;
    }
}
bool isEmpty() {
    if (top == 0)
        return true;
    else
        return false;
}
void display(){
    if(!isEmpty()){
        cout << "Data antrian : " << endl;
        for(int a = top-1; a >= 0; a--){
            cout << a+1 << "." << data[a] << endl;
        } 
    }
        else {
            cout << "Antrian Tidak Ada" << endl;
        }
}

void enqueue(){
    if(!isFull()){
        cout << "Masukkan Data : ";
        cin >> data[top];
        top++;
    }
}
void dequeue(){
    if(!isEmpty()){
        for (int a=0; a<top-1; a++){
            data[a] = data[a+1];
        }
        top--;
    }
}
int main (){
    int pilihan;
    string isi;

    queue :
        system("cls");
        display();
        cout << "Menu Utama\n1.EnQueue\n2. DeQueue\nPilih : ";
        cin >> pilihan;

        if(pilihan == 1){
            cout << "EnQueue";
            system("cls");
            enqueue();
            goto queue;
        }
        else if(pilihan == 2){
            cout << "DeQueue";
            dequeue();
            goto queue;
        }
}