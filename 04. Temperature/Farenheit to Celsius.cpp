#include<iostream>
using namespace std;
int main() {
   float f, c;
   for(int i=0;i<=5;i++){
		cout << "Enter temperature in Fahrenheit: ";
   		cin >> f;
   		c = (5.0/9.0)*(f-32);
   		cout << "Equivalent Celsius temperature is: " <<c<<endl;
    }
	return 0;
}
