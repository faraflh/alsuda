#include <iostream>
#include <cstdlib>
#include <cctype>
#define MAX 40

using namespace std;

typedef struct {
    char kata[MAX];
    int top;
} My_Stack;

int kosong(My_Stack* s) {
    return(s->top == 0);
}
void push(My_Stack* s, char x) {
    s->top++;
	s->kata[s->top] = x;
}
void pop(My_Stack* s) {
    cout << s->kata[s->top--];
}

int main() {
    My_Stack st;
    char input[MAX];
    int i = 0;
    st.top = -1;

    cout <<"Masukkan Kalimat : ";
    gets(input);
    cout << "Hasil : ";

    while(input[i] != '\0') {
        if(isalpha(input[i]))
        push(&st, input[i]);
        else if(input[i] == '*')
        pop(&st);
        else {
            cout << "";
        }i++;
    } 
}
