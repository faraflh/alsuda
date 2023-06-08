#include <iostream>
#include <cstring>
#define MAXSTACK 100

using namespace std;

typedef char ItemType;
typedef struct {
    char item[MAXSTACK];
    int count;
} Stack;

Stack tumpukan;
void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(ItemType, Stack *);
ItemType Pop(Stack *);
int drjt(char);
void konversi_cetak(char[]);

int main() {
    char tampung[MAXSTACK], jawab;
    puts("MENGUBAH NOTASI INFIX MENJADI PSOTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK");
    do
    {
        InitializeStack(&tumpukan);
        fflush(stdin);
        puts("");
        cout << "Masukan ekspresi dalam notasi infix : ";
        fgets(tampung, sizeof(tampung), stdin);
        cout << "Ungkapan postfixnya = ";
        konversi_cetak(tampung);
        puts("");
        fflush(stdin);
        cout << "\nMau mencoba lagi (y/t) ? ";
        cin >> jawab;
    } while ((jawab == 'y') || (jawab == 'Y'));
}
void InitializeStack(Stack *S){
    S->count = 0;
}
int Empty(Stack *S){
    return (S->count == 0);
}
int Full(Stack *S){
    return (S->count == MAXSTACK);
}
void Push(ItemType x, Stack *S){
    if (Full(S))
        cout << "Stack penuh! Data tidak dapat masuk!";
    else {
        ++(S->count);
        S->item[S->count] = x;
    }
}
ItemType Pop(Stack *S){
    ItemType x;
    if (Empty(S)) {
        cout << "STACK KOSONG!";
        return 0;
    }
    else    {
        x = (S->item[S->count]);
        --(S->count);
        return x;
    }
}

int drjt(char x){
    if ((x == '(') || (x == '*') || (x == '/') || (x == '+') || (x == '-') || (x == '^'))
        return 0;
}

void konversi_cetak(char temp[]){
    int i, pjg, valid = 1;
    char kar, smtr;
    pjg = strlen(temp) - 1;
    for (i = 0; i < pjg; i++) {
        kar = temp[i];
        switch (kar)        {
        case '(':
            Push(kar, &tumpukan);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            cout << kar;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            if ((Empty(&tumpukan)) ||
                ((drjt(kar) > drjt(tumpukan.item[tumpukan.count]))))

                Push(kar, &tumpukan);

            else            {
                do                {
                    smtr = Pop(&tumpukan);
                    cout << smtr;
                } while (drjt(kar) <
                         drjt(tumpukan.item[tumpukan.count]));
                Push(kar, &tumpukan);
            }

        case ')':
            while (tumpukan.item[tumpukan.count] != '(')            {
                smtr = Pop(&tumpukan);
                cout << smtr;
            }
            Pop(&tumpukan);
            break;
        default:
            valid = 0;
            puts("INVALID STSTEMEN");
            break;
        }
    }
    if ((valid != 0) && (!Empty(&tumpukan))) {
        smtr = Pop(&tumpukan);
        cout << "%c", smtr;
    }
}