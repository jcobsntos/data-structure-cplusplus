#include<iostream>
#include<conio.h>
using namespace std;

void DisplayValue(int w, int &x, int &y, int &z)
{
	w++;
	x--;
	y++;
	z--;
	cout<<"Value of w : "<<w<<endl;
	cout<<"Value of x : "<<x<<endl;
	cout<<"Value of y : "<<y<<endl;
	cout<<"Value of z : "<<z<<endl;
}
int main()
{	int a=1,b=1,c=1,d=1;
	system("cls");
	DisplayValue(a,b,c,d);
	cout<<"\nValue of a : "<<a<<endl;
	cout<<"Value of b : "<<b<<endl;
	cout<<"Value of c : "<<c<<endl;
	cout<<"Value of d : "<<d<<endl;
	getch();
}


