#include<iostream>
using namespace std;

void PassByReference(int &x, int &y, int &z)
{
	x++;
	y++;
	z++;
	cout<<"Value of x : "<<x<<endl;
	cout<<"Value of y : "<<y<<endl;
	cout<<"Value of z : "<<z<<endl;
}
int main()
{	
	int a=1,b=2,c=3;
	PassByReference(a,b,c);
	cout<<"Value of a : "<<a<<endl;
	cout<<"Value of b : "<<b<<endl;
	cout<<"Value of c : "<<c<<endl;
	return 0;
 }

