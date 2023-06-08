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

main() {
    char tampung[MAXSTACK], jawab;
    puts("Cek Notasi Infiks Benar atau Salah Dengan Memanfaatkan Struktur Stack");
    do {
        InitializeStack(&tumpukan);
        fflush(stdin);
        puts("");
        cout << "Infix : ";
        fgets(tampung, sizeof(tampung), stdin);
        cout << "Output : ";
        konversi_cetak(tampung);
        puts("");
        fflush(stdin);
        cout << "\nMau mencoba lagi (y/t) ? ";
        cin >> jawab;
    } while ((jawab == 'y') || (jawab == 'Y'));
}
void InitializeStack(Stack *S) {
    S->count = 0;
}
int Empty(Stack *S) {
    return (S->count == 0);
}
int Full(Stack *S) {
    return (S->count == MAXSTACK);
}
void Push(ItemType x, Stack *S) {
    if (Full(S)) 
        cout << "Stack penuh! Data tidak dapat masuk!";
    else {
        ++(S->count);
        S->item[S->count] = x;
    }
}
ItemType Pop(Stack *S) {
    ItemType x;
    if (Empty(S)) { 
        cout << "STACK KOSONG!";
        return 0;
    }
    else {
        x = (S->item[S->count]);
        --(S->count);
        return x;
    }
}
void konversi_cetak(char temp[]) {
    int i, h = 0, j = 0, l = 0, m = 0, pjg, valid = 1;
    char kar;
    pjg = strlen(temp) - 1;
    for (i = 0; i < pjg; i++) {
        kar = temp[i];
        switch (kar) {
        case '(':
            h++;
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
            j++;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            l++;
            break;
        case ')':
            m++;
            break;
        default:
            valid = 0;
            puts("INVALID STSTEMEN");
            break;
        }
    }
    if (h != m) {
        cout << "Notasi infix salah, kurung tidak lengkap";
    }
    else if (j == l) {
        cout << "Notasi infix salah, operand tidak lengkap";
    }
    else if (j - 2 >= l) {
        cout << "Notasi infix salah, operator tidak lengkap";
    }
    else {
        cout << "Tidak Ada Kesalahan";
    }
}
