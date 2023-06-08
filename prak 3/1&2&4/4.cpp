#include <stdio.h>
#include <iostream>
#include<malloc.h>
using namespace std;

typedef struct node
{
	int Item;
	struct node *link;
} Node;

typedef struct {
	Node *Front;
	Node *Rear;
} Queue;

// Prosedur untuk menyisipkan data pada antrian
void Tambah(Queue *Q, int y)
{
	Node *ptr;
	ptr=(Node *) malloc(sizeof(Node));
	ptr->Item=y;
	ptr->link=NULL;
	if(Q->Front ==NULL)
	{
		Q->Front = Q->Rear = ptr;
	}
	else
	{
		Q->Rear->link=ptr;
		Q->Rear=ptr;
	}
}

// Prosedur untuk menghapus data dari antrian
int Hapus(Queue *Q)
{
	int num;
	if(Q->Front==NULL)
	{
		printf("\n\n\t\tAntrian Kosong\n\n");
		return(0);
	}
	else
	{
		num=Q->Front->Item;
		Q->Front = Q->Front->link;
		if(Q->Front == NULL)
			Q->Rear = NULL;
		return(num);
	}
}

void Tampil(Node *N)
{
	printf ("\nFront -> ");
	while (N != NULL)
	{
		if(N->link == NULL)
		{
			printf("%5d", N->Item);
			printf(" <- Rear\n");
		}
		else
			printf("%5d", N->Item);
		N = N->link;
	}
}

int Count(Node *N)
{
	int c=0;
	while (N != NULL)
	{
		N = N->link;
		c++;
	}
	return c;
}

void TampilVariable(Queue *q)
{
	cout<<"Font : "<<(q->Front)<<" | Count : "<<Count((q->Front))<<" | Rear : "<<(q->Rear)<<endl;
}

main()
{
	int item;
	Queue Q;
	Q.Front = Q.Rear = NULL;
	Tambah(&Q, 5);
	Tampil(Q.Front); TampilVariable(&Q);
	Tambah(&Q, 6);
	Tampil(Q.Front); TampilVariable(&Q);
	Tambah(&Q, 7);
	Tampil(Q.Front); TampilVariable(&Q);
	Hapus(&Q);
	Tambah(&Q, 8);
	Tampil(Q.Front); TampilVariable(&Q);
	Tambah(&Q, 9);
	Tampil(Q.Front); TampilVariable(&Q);
	Hapus(&Q);
	Tambah(&Q, 10);
	Tampil(Q.Front); TampilVariable(&Q);
	Tambah(&Q, 11);
	Tampil(Q.Front); TampilVariable(&Q);
	Tambah(&Q, 12);
	cout<<endl;

	Tampil(Q.Front); TampilVariable(&Q);
}
