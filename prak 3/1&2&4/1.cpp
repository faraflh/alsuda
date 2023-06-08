#include <queue>
#include <iostream>
#define MAX 5
using namespace std;

queue<int> q;

// Prosedur untuk menyisipkan data pada antrian
void Tambah(int item) {
	if (q.size() == MAX)
	{
		cout << "\nAntrian Penuh\n";
		return;
	}
	q.push(item);
}

// Prosedur untuk menghapus data dari antrian
int Hapus() {
	int data = 0;
	if (q.size() <= 0) {
		cout << "\nAntrian Kosong";
	}
	else {
		data = q.front();
		q.pop();
	}
	return data;
}

void Tampil(queue<int> q1) {
	queue<int> q = q1;
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout<<endl;
}

void TampilVariable() {
	cout<< "Front : " << q.front() << " Rear : " << q.back() << " Count : " << q.size() << endl;
}

main() {
	Tambah(5);
	Tampil(q); TampilVariable();
	Tambah(6);
	Tampil(q); TampilVariable();
	Tambah(7);
	Tampil(q); TampilVariable();
	Hapus();
	Tampil(q); TampilVariable();
	Tambah(8);
	Tampil(q); TampilVariable();
	Tambah(9);
	Hapus();
	Tampil(q); TampilVariable();
	Tambah(10);
	Tampil(q); TampilVariable();
	Tambah(11);
	Tampil(q); TampilVariable();
	cout << "\nPushing 12"; Tambah(12);
	cout<<endl;

	Tampil(q); TampilVariable();
}
