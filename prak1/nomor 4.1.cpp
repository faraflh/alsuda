#include <iostream>
#include <cstring>

using namespace std;

int a,b;
int main()
{
	int P1[11] = {15,0,0,1,0,5,0,8,6,0,0};
	int P2[11] = {10,0,2,2,3,0,0,4,0,3,0};
	int P3[11] = {5,0,1,0,0,0,0,0,0,0,0};
	int bilangan[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	
	cout << "Aritmatika Polinomial\n" << endl;
	cout << "Diketahui : " << endl;
	cout << "P1 = 6x^8 + 8x^7 + 5x^5 + x^3 + 15" << endl;
	cout << "P2 = 3x^9 + 4x^7 + 3x^4 + 2x^3 + 2x^2 + 10" << endl;
	cout << "P3 = x^2 + 5" << endl;
	
	cout << "\nHasil Operasi\t: " << endl;
	cout << endl << "Penjumlahan\t: ";
			for (a = 0; a < 10; a++) {
				bilangan[a]=* (P1+a) +* (P2+a);
			}
			for(a = 11; a >= 0; a--) {
				if(bilangan[a]==0) {
					cout << " ";
				}
				else {
					if (a > 1) 	{
						if (bilangan[a]>1)
						cout << " " << bilangan[a] << "x^" << a << " +";
						else if (bilangan[a])
						cout << " " << bilangan[a] << "x^" << a;
					}
					else if (a==1)
					cout << " " << bilangan[a] << "x^" << " ";
					else if (a>=0)
					cout << bilangan[a]; 
				}
			}
			
			cout << endl << "Pengurangan\t: ";
			for (a = 0; a < 10; a++) {
				bilangan[a]=* (P1+a) -* (P2+a);
			}
			for(a = 11; a >= 0; a--) {
				if(bilangan[a]==0)
				{
					cout << " ";
				}
				else 
				{
					if (a>1)
					{
						if (bilangan[a]>1)
						cout << " " << " + "<< bilangan[a] << "x^" << a ;
						else if (bilangan[a])
						cout << " " << bilangan[a] << "x^" << a ;
					}
					else if (a==1)
					cout << " " << bilangan[a] << "x^" << " ";
					else if (a>=0)
					cout << " + " << bilangan[a] ; 
				}
			}
			 	
			int bil2[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
			cout << endl << "Perkalian\t: ";
			for (a = 0; a < 10; a++)
			{
				for (b = 0; b < 4; b++)
				{
					bil2[a+b] += *(P1+a) * *(P3+b);
				}
			}
			
			for (a = 11; a >= 0; a--)
			{
				if (bil2[a]==0)
				{
					cout << " ";
				}
				else 
				{
					if (a>1)
					{
						cout << "  " << bil2[a] << "x^" << a << " +";
					}
					else if (a==1)
					{
						cout << " " << bil2[a] << "x^" << " +";
					} 
					else if (a==0)
					{
						cout << " " << bil2[a];	
					}
				}
			}
			
			cout << endl << "Turunan\t\t: ";
			for (a = 0; a < 10; a++)
			{
				bilangan[a] = P2[a+1]* (a+1);
			}
			for (a = 11; a >= 0; a--)
			{
				if (bilangan[a]==0)
				{
					cout << " ";
				}
				else
				{
					if (a>1)
					{
						cout << bilangan[a] << "x^"<< a << " + " ;
					}
					else if (a==1)
					cout << " " << bilangan[a] << "x" << " ";
				}
			}
}
