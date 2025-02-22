 #include <iostream>  
 using namespace std;  
   
int main() 
{  
    int n, f=1;    
    cout << "Enter a value: ";    
	cin >> n; 
	if (n<0) {         
	 cout << "Can't be negative" <<endl;        
	  } 
	else if (n>=1){   
		while(n>=1){
		  f=f*n;
		  n--;
     	}
		cout << "Factorial of " << n << " is " << f << endl;         
	}     
	else {
		cout << "Invalid data type entered" << endl;  
	}
	return 0; 
} 
