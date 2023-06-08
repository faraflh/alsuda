#include <iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int MAXSTACK;
typedef int itemtype;

typedef struct {
	itemtype item[300];
	int count;
}stack;

void initializestack(stack *s) {
	s->count = 0;
}

int empty(stack *s) {
	return (s->count == 0);
}

int full(stack *s) {
	return (s->count == MAXSTACK);
}

void push(itemtype x, stack *s) {
	if(full(s))
 		cout << "stack penuh !\n";
 	else 	{
	 	s->item[s->count]=x;
		++(s->count);
	}
}

int pop(stack *s) {
 	if(empty(s))
 		cout << "stack kosong\n";
 	else {
	 	--(s->count);
	 	return (s->item[s->count]);
	}
 	return 0;
}

int i, n, m, o,p,pilih;
int input;
stack tumpukan;
void biner();
void oktal();
void heksa();

int main(){
	initializestack(&tumpukan);
	cout << "Masukkan bilangan desimal : ";
	cin >> input;
	cout << "\n---MENU---\n";
	cout << "1 untuk konversi ke biner\n";
	cout << "2 untuk konversi ke oktal\n";
 	cout << "3 untuk konversi ke heksa\n";
 	cout << "4 untuk keluar";
	while(pilih<4){
 		cout << "\n\npilih :  ";
 		cin >> pilih;
	switch(pilih){
 		case 1:
 			cout << "bilangan binernya\n";
 			biner();break;
 		case 2:
 			cout << "bilangan oktalnya\n";
 			oktal();break;
 		case 3:
 			cout << "bilangan heksadesimalnya\n";
 			heksa();break;
		case 4:
			break;
 		}
	}
 	return 0;
}

void oktal(){
	for(o=1,n=input;n>0;n=n/8,o++) 	{
		 MAXSTACK=o;
		 m=n%8;
		 push(m,&tumpukan);
 	}
	for(i=MAXSTACK;i>0;i--)	{
 		cout << pop(&tumpukan);
 	}
}

void biner(){
	for(o=1,n=input;n>0;n=n/2,o++){
		MAXSTACK=o;
 		m=n%2;
		push(m,&tumpukan);
	}
	for(i=MAXSTACK;i>0;i--){
		cout << pop(&tumpukan);
	}
}

void heksa(){
	for(o=1,n=input;n>0;n=n/16,o++){
		MAXSTACK=o;
		m=n%16;
		push(m,&tumpukan);
	}
	for(i=MAXSTACK;i>0;i--){
 		p=pop(&tumpukan);
 		if(p<=9)
 		cout << p;
 		else if(p==10) cout <<"A";
		else if(p==11) cout <<"B";
		else if(p==12) cout <<"C";
 		else if(p==13) cout <<"D";
 		else if(p==14) cout <<"E";
 		else if(p==15) cout <<"F";
	 }
}
