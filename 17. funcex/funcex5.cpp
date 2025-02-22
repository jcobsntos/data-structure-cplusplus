#include<iostream>
#define PI 3.1415927
using namespace std;

double Area(double r);
double Circumference(double r);
double Area(double r)
{
return(PI*r*r);
}
double Circumference(double r)
{
return(2*PI*r);
}
int main()
{	double radius, a, c; 
	cout<<"Enter radius : ";
	cin>>radius;
	a=Area(radius);
	c=Circumference(radius);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout<<"The circumference of the circle is "<<c<<endl;
	cout<<"The area of the circle is "<<a<<endl;
	return 0;
}


