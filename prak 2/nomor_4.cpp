#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

void push(char);
char pop();

char stack[100];
int top = -1;

int main() {
    char str[100];
    int i, count = 0, len;
    
    cout << "Masukkan sebuah string : ";
    cin >> str;
    
    len = strlen(str);
    
    for (i = 0; i < len; i++) {
        push(str[i]);
    }
    for (i = 0; i < len; i++) {
        if (str[i] == pop())
        count++;
    }
    
    if (count == len) {
       cout << "Kata " << str << " adalah kata palindrom";
    }
    else {
        cout << "Kata " << str << " bukan kata palindrom";
        getch();
    }
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return(stack[top--]);
}
