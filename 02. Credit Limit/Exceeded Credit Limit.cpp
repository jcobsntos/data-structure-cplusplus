#include<iostream>

#include<stdlib.h>

using namespace std;

int main(){

double accNo=0,begBal,totalCharges,credits,creditLimit,newBal;

while(accNo!=-1){

cout<<"\nEnter account number(or -1 to quit): ";

cin>>accNo;

if(accNo==-1)

exit(0);

cout<<"Enter beginning Balance: ";

cin>>begBal;

cout<<"Enter total charges: ";

cin>>totalCharges;

cout<<"Enter total credits: ";

cin>>credits;

cout<<"Enter credit limit: ";

cin>>creditLimit;

newBal=begBal-totalCharges+credits;

if(newBal>creditLimit){

cout<<"\nAccount number: "<<accNo<<endl;

cout<<"Credit limit: "<<creditLimit<<endl;

cout<<"New Balance: "<<newBal<<endl;

cout<<"Credit Limit Exceeded"<<endl;

}

else{

cout<<"New Balance is "<<newBal<<endl;

}

}

return 0;

}
