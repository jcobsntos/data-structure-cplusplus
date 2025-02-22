#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randNumFnum(){
  	int num;
	srand((unsigned)time(0));
    num = rand() % 9;
    return num;
}
int randNumSnum(){
    int num;
	srand((unsigned)time(0));
    num = rand() % 10;
    return num;
}
int main(){
    int num, firstNumber, secondNumber, product;
    const int END = -1;
    cout<<"Random Multiplication Generator\n";
    while (num != END)
    {
        firstNumber = randNumFnum();
        secondNumber = randNumSnum();
        while (true)
        {
            cout<<"How much is "<<firstNumber<<" times "<<secondNumber<<" ? ";
            cin>>product;
            if (product == firstNumber * secondNumber){
            	cout<<"Very Good!";
                break;
            }
            else{
            	cout<<"No. Please try again...\n";
                continue;
            }
        }
        cout<<"\nTo proceed in the next question enter any number, To end enter -1: ";
        cin>>num;
    }
    return 0;
}





