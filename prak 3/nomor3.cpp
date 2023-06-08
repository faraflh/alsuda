#include <conio.h>
#include <cstdlib>
#include <iostream>
#define MAX 500

using namespace std;

struct queue {
  int no_polisi[MAX];
  int front;
  int rear;
  int count;
};
struct stack {
  int no_polisi[MAX];
  int count;
};
void InisialisasiQueue(struct queue *q) {
  q->front = q->rear = 0;
  q->count = 0;
}
void InisialisasiStack(struct stack *s) {
  s->count = 0;
}
int pop(struct stack *s) {
  int npol;
  npol = s->no_polisi[s->count];
  s->count--;
  return (npol);
}
void normalisasi_queue(int x, struct queue *q, struct stack *s) {
  do {
    q->no_polisi[x] = q->no_polisi[x + 1];
    x++;
  } while (x < q->rear);
  q->rear--;
  q->count--;
  do {
    q->front--;
    q->no_polisi[q->front] = pop(s);
    q->count++;
  } while (s->count != 0);
}
void push(int npol, struct stack *s) {
  s->count++;
  s->no_polisi[s->count] = npol;
}
int cek_mobil(int npol, struct queue *q) {
  int i, hasil;
  for (i = q->front; i <= q->rear; i++) {
    if (q->no_polisi[i] == npol) {
      hasil = i;
      break;
    } else if ((q->no_polisi[i] != npol) && (i == q->rear)) {
      hasil = 0;
    }
  }
  return (hasil);
}
void masuk(int npol, struct queue *q) {
  if (q->rear == MAX) {
    cout << "\nAntrian Penuh !\n";
    return;
  } else if (q->count == 0) {
    q->rear++;
    q->no_polisi[q->rear] = npol;
    q->count++;
    q->front++;
  } else {
    q->rear++;
    q->no_polisi[q->rear] = npol;
    q->count++;
  }
}
void keluar(int npol, struct queue *q, struct stack *s) {
  int i, x;
  i = q->front;
  if (q->count == 0) {
    cout << "\nAntrian kosong !\n";
    getch();
    return;
  } else if (cek_mobil(npol, q) == 0) {
    cout << "\nNomor polisi mobil yang anda masukkan tidak ada dalam antrian!\n";
    getch();
    return;
  } else if ((cek_mobil(npol, q) == q->front) && (q->count > 1)) {
    q->front++;
    q->count--;
    return;
  } else if ((cek_mobil(npol, q) == q->front) && (q->count == 1))
    InisialisasiQueue(q);
  else {
    x = cek_mobil(npol, q);
    cout << "\nMobil yang keluar sementara : \n";
    for (i = q->front; i < x; i++) {
      cout << "- Mobil no_polisi nomor " << q->no_polisi[i] << endl;
      push(q->no_polisi[i], s);
      q->front++;
      q->count--;
    }
    normalisasi_queue(x, q, s);
    getch();
    return;
  }
}
void tampil(struct queue *q) {
  int i, x;
  x = q->front;
  cout << "\nData antrian mobil yang parkir : \n";
  if (q->count == 0)
    cout << "\nTidak ada mobil yang sedang parkir\n";
  else {
    for (i = 1; i <= q->count; i++) {
      cout << i << ". Mobil nomor polisi nomor " << q->no_polisi[x] << endl;
      x++;
    }
    cout << "\nJumlah mobil yang parkir : " << q->count << endl
         << endl;
  }
  getch();
  return;
}
int main() {
  struct queue q;
  struct stack s;
  int jawab;
  int npol;
  InisialisasiQueue(&q);
  InisialisasiStack(&s);
  do {
    cout << "PROGRAM ANTRIAN MOBIL\n\n";
    cout << "1. Masukkan mobil\n2. Keluarkan mobil\n3. Tampilkan antrian\n";
    cout << "4. Keluar\n\n";
    cout << "Pilih Menu : ";
    cin >> jawab;
    cout << endl;
    if (jawab == 1) {
      cout << "Masukkan nomor polisi mobil masuk (tanpa huruf) : ";
      cin >> npol;
      masuk(npol, &q);
      tampil(&q);
    } else if (jawab == 2) {
      cout << "Masukkan nomor polisi  mobil keluar (tanpa huruf): ";
      cin >> npol;
      keluar(npol, &q, &s);
      tampil(&q);
    } else if (jawab == 3) {
      tampil(&q);
    } else if (jawab == 4)
      cout << ".............";
    else {
      cout << "\n\nPilihan tidak valid. Silahkan ulangi!\n";
      getch();
    }
  } while (jawab != 4);
}