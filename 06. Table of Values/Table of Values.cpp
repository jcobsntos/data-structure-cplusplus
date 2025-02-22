#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	cout<<"Loop and tab escape to print the Table of Values\n\n";
	cout<<"N\tN^2\tN^3\tN^4"<<endl; 
	for(int N=1;N<=5;N++){
		cout<<N<<"\t"<<pow(N,2)<<"\t"<<pow(N,3)<<"\t"<<pow(N,4)<<endl; 
	}
	return 0;
}


