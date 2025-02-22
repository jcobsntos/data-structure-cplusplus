#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a,b,c;
	cout<<"Finding the hypotenuse of a right triangle using the Pythagorean Theorem"<<endl;
	cout<<"Enter Opposite: a = ";
	cin>>a;
	cout<<"Enter Adjacent: b = ";
	cin>>b;
	c=sqrt((a*a) + (b*b));
	
	cout<<"Hypotenuse: c = "<<c;
	
	return 0;
}








