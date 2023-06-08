#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

typedef struct {
    char kata[MAX];
    int top;
}My_Stack;

void push(My_Stack*, char);
void pop(My_Stack*);
int penuh(My_Stack*);
int kosong(My_Stack*);

int main() {
    My_Stack st;
    char input[MAX];
    int i = 0;
    st.top = -1;

    printf("Masukkan Kalimat : ");
    gets(input);
    printf("Hasil : ");

    while(input[i] != '\0') {
        if(isalpha(input[i]))
        push(&st, input[i]);
        else if(input[i] == '*')
        pop(& st);
        else {
            printf("");
        }i++;
    }
}

void push(My_Stack *s, char c) {
    
    s->top++;
    s->kata[s->top] = c;
}

void pop(My_Stack* s) {
    if(kosong(s)) {
        printf("ERROR!");
    }
    printf("%c", s->kata[s->top--]);
}
int penuh(My_Stack* s) {
    return(s->top == MAX);
}
int kosong(My_Stack* s) {
    return(s->top == 0);
}