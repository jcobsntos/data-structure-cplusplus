#include <iostream> 
using namespace std;  
	 
double fahrenheitToCelsius(double fahrenheit){      
	double celsius;        
	celsius = (fahrenheit - 32.0) * 5.0 / 9.0;      
	return celsius;  
}   
double celsiusToFarenheit(double celsius) {     
	double farenheit;
	farenheit = ((celsius * 9.0 / 5.0) + 32.0); 
	return farenheit;
}      
int main(){      
double fahrenheit, celsius;     
int choice;   
string temp;    
	
	while(true){                          
	 cout<<"\nTemperature Converter"<<endl;                           
	 cout<<"1 - Celsius to Fahrenheit"<<endl;          
	 cout<<"2 - Fahrenheit to Celsius"<<endl;                                    
	 cout<<"Enter your choice: ";          
	 cin>>choice; 
	
	 switch (choice){                 
		case 1:      
			cout<<"Enter temperature in Celsius: ";              
			cin>>celsius;              
			cout<<celsius<<" degree/s Celsius is "<<celsiusToFarenheit(celsius)<<" degree/s fahrenheit"<<endl;                        
			break;       
		case 2:   
			cout<<"Enter temperature in fahrenheit: ";              
			cin>>fahrenheit;              
			cout<<fahrenheit<<" degree/s Fahrenheit is "<<fahrenheitToCelsius(fahrenheit)<<" degree/s Celsius"<<endl;          
			break;
		default:
			cout<<"Invalid... Please re-enter\n";
			continue;
		}                    
		cout<<"\nContinue? [yes/no]: ";          
		cin>>temp;          
		if(temp == "yes")     
		continue;
			if(temp == "no")
			break;  
	}
	return 0; 
}      




