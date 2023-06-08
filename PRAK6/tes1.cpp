#include <iostream>

using namespace std;

struct Buku{
	
	//komponen atau member
	string judul, pengarang;
	int tahunTerbit;
	
	Buku *next;
};

Buku *head, *tail, *current, *newNode, *hapus, *before;

// create single linked list
void createSingleLinkedList(string judul, string pengarang, int tahunTerbit){
	head = new Buku();
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahunTerbit = tahunTerbit;
	head->next = NULL;
	tail = head; //yang pertama akan menjadi yang terakhir
}

//TAMBAHAN
//count single linked list
//void countSingleLinkedList(){
//	current = head;
//	int total = 0;
//	while(current != NULL){
//		total++;
//		current = current->next;
//	}
//}

//menambah di awal single linked list
void addFirst(string judul, string pengarang, int tahunTerbit){
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tahunTerbit;
	newNode->next = head;
	head = newNode;
}

//menambah di akhir single linked list
void addLast(string judul, string pengarang, int tahunTerbit){
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tahunTerbit;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}

//TAMBAHAN
//menambah data ditengah
void addMiddle(string judul, string pengarang, int tahunTerbit, int posisi){
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahunTerbit = tahunTerbit;
	
	//melakukan transfersing
	current = head;
	int nomor = 1;
	while( nomor < posisi - 1){
		current = current -> next;
		nomor++;
	}
	
	newNode->next = current->next;
	current->next = newNode;
}

//menghapus data di awal
void hapusAwal(){
	hapus = head;
	head = head->next;
	delete hapus;
}

//menghapus data di akhir
void hapusAkhir(){
	hapus = tail;
	current = head;
	while(current->next != tail){
		current = current -> next;
	}
	tail = current;
	tail->next = NULL;
	delete hapus;
}

//TAMBAHAN
//hapus data tengah
void hapusMiddle(int posisi){
	int nomor = 1;
	current = head;
	while( nomor <= posisi ){
		if( nomor == posisi-1){
			before = current;
		}
		if( nomor == posisi){
			hapus = current;
		}
		current = current->next;
		nomor++;
	}
	before->next = current;
	delete hapus;	
}

//TAMBAHAN
//mengubah data diawal single linked list
void ubahAwal(string judul, string pengarang, int tahunTerbit){
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahunTerbit = tahunTerbit;
}

//TAMBAHAN
//mengubah data diakhir single linked list
void ubahAkhir(string judul, string pengarang, int tahunTerbit){
	tail->judul = judul;
	tail->pengarang = pengarang;
	tail->tahunTerbit = tahunTerbit;
}

//TAMBAHAN
//mengubah data tengah
void ubahMiddle(string judul, string pengarang, int tahunTerbit, int posisi){
//	if(posisi < 1 || posisi > countSingleLinkedList()){
//		cout<<"Posisi diluar jangkauan"<<endl;
//	}else if(posisi==1 || posisi==countSingleLinkedList()){
//		cout<<"Posisi bukan posisi tengah"<<endl;
//	}else{
	int nomor = 1;
	current = head;
	while( nomor <= posisi ){
		if( nomor == posisi-1){
			before = current;
		}
		if( nomor == posisi){
			hapus = current;
		}
		current = current->next;
		nomor++;
	}
	current->judul = judul;
	current->pengarang = pengarang;
	current->tahunTerbit = tahunTerbit;	
}


//print single linked list
void printSingleLinkedList(){
//	cout<<"Jumlah data : "<<countSingleLinkedList()<<endl;
	current = head;
	while(current != NULL){
		cout<<"\nJudul Buku : "<<current->judul<<endl;
		cout<<"Pengarang Buku : "<<current->pengarang<<endl;
		cout<<"Tahun Terbit Buku : "<<current->tahunTerbit<<endl;
		
		current = current->next;
	}
}

int main(){
	
	createSingleLinkedList("Kata", "Geez & Ann", 2018);
	printSingleLinkedList();
	cout<<"\n=== Ini Setelah Menambah Single Linked List pada Head ==="<<endl;
	
	addFirst("Dia adalah kakakku", "Tere liye", 2009);
	printSingleLinkedList();
	
	cout<<"\n=== Ini Setelah Menambah Single Linked List pada Tail ==="<<endl;
	
	addLast("Aroma Karsa", "Dee Lestari", 2018);
	printSingleLinkedList();
	
	cout<<"\n=== Menghapus data di awal ==="<<endl;
	
	hapusAwal();
	
	printSingleLinkedList();
	
	cout<<"\n=== Menghapus data di akhir ==="<<endl;
	
	hapusAkhir();
	
	printSingleLinkedList();
	
	cout<<"\n=== Mengubah data di awal ==="<<endl;
	
	ubahAwal("Berhenti dikamu","Gia pratama", 2018);
	
	printSingleLinkedList();
	
	cout<<"\n=== Menambah data di tengah ==="<<endl;
	
	addMiddle("Bumi manusia","Pramoedya Anata Toer", 2005, 2);
	
	printSingleLinkedList();
	
	cout<<"\n=== Menambah data di tengah ==="<<endl;
	
	addMiddle("Negeri 5 Menara","Ahmad Fuadi", 2009, 3);
	
	printSingleLinkedList();
	
	cout<<"\n=== Menghapus data di tengah ==="<<endl;
	
	hapusMiddle(3); 
	
	printSingleLinkedList();
	
	cout<<"\n=== Mengubah data di tengah ==="<<endl;
	
	ubahMiddle("Sang Pemimpi","Andrea Hirata", 2006, 2);
	
	printSingleLinkedList();
}