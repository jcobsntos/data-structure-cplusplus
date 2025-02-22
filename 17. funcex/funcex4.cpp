#include<iostream>
using namespace std;

void Exchange(int &num1, int &num2)
{	int value1, value2;
	cout<<"Enter first value: ";
	cin>>value1;
	cout<<"Enter second value: ";
	cin>>value2;
	cout<<"\nValue before exchange"<<endl;
	cout<<"First Value : "<<value1<<endl;
	cout<<"Second Value : "<<value2<<endl;
}
int main()
{	int value1, value2;
	Exchange(value1, value2); //exchange values
	cout<<"\nValue after exchange"<<endl;
	cout<<"First Value : "<<value1<<endl;
	cout<<"Second Value : "<<value2<<endl;
	return 0;
}


