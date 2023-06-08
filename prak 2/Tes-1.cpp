#include <iostream>
#include <cctype>
using namespace std;
#define maks 40

int p = 0;
typedef char tipe;
typedef struct {
  char item[maks];
  int count;
} Stack;

void insialisasi (Stack * S) {
  S->count = 0;
}

int penuh (Stack * S) {
  return (S->count == maks);
}

int kosong (Stack * S) {
  return (S->count == 0);
}

void push (tipe x, Stack * S) {
  if (penuh (S)) {
  	cout << "Stack tidak dapat masuk karena sudah penuh\n";
  }
  	else {
      S->item[S->count] = x;
      cout << "Stack berada di diindex ke " << S->count << endl;
      ++(S->count);
	}
}

int pop (Stack * S, char cetak[maks]) {
	if (kosong (S)) {
	cout << "Stack masih kosong\n";
	}
	else {
      --(S->count);
      cetak[p] = S->item[S->count];
      cout << S->item[S->count] << " telah keluar dari stack\n";
    }
  return p;
}

void isi (Stack * S)
{
  	int a = 0;
  	cout << "Inputkan Stack ";
  	while (a < S->count) {
  		cout << S->item[a++];
	} cout << endl;
}

int main () {
  Stack tumpukan;
  char cetak[maks];
  char input;
  int a, b, c;
  insialisasi (&tumpukan);

  cout << "Masukkan input\n";
  for (a = 0; a != maks; a++)
    {
      cout << "Isi :";
      gets(input);
      fflush (stdin);
      if (input[a] == '*') {
	      c = pop (&tumpukan, cetak);
	      isi (&tumpukan);
	      cout << endl;
	      b = 0;
	      while (b < p)
	        cout << "tes" << cetak[b++] << endl;
	    }
	    else
	    push(input[a], &tumpukan);
  }
  for (a = 0; a < c; a++) {
      cout << "ini apa" << cetak[a];
  }
}

