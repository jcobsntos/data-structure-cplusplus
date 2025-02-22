#include <iostream>
using namespace std;

void customerDetails(string name, string address, string phoneNumber){
	cout<<"\nEnter Customer's Name: ";
	getline(cin>>ws, name);
	cout<<"Enter Customer's Address: ";
	getline(cin>>ws, address);
	cout<<"Enter Customer's Phone Number: ";
	getline(cin>>ws, phoneNumber);
	cout<<"Customer Added Successfully... "<<endl<<endl;
	
	cout<<"Customer's Name: "<<name<<endl;
	cout<<"Customer's Address: "<<address<<endl;
	cout<<"Customer's Phone Number: "<<phoneNumber<<endl;
}
void checkOut(string name, string room,string bill){
	cout<<"Enter Customer's Name: ";
	getline(cin>>ws, name);
	cout<<"Enter Customer's Room: ";
	cin>>room;
	cout<<"Enter total Bill: ";
	cin>>bill;
	cout<<"\nAssigned Room Alphabet: "<<room<<endl;
	cout<<"Customer's Name: "<<name<<endl;
	cout<<"Total Amount: "<<bill<<endl<<endl;
}

int methodOfPayment(int payment){
	int method;
	do {
		cout<<"\t============================"<<endl;
		cout<<"\t||Select Method of Payment||"<<endl;
		cout<<"\t============================"<<endl;
		cout<<"[1] - Mastercard"<<endl;
		cout<<"[2] - Visa"<<endl;
		cout<<"[3] - E-wallet Gcash/Paymaya"<<endl;
		cout<<"[4] - Cash"<<endl;
		cout<<"SELECT: ";
		cin>>method;
	
		switch (method){
			case 1: {
				string name, card;
				cout<<"Enter Name on Card: ";
				getline(cin>>ws,name);
				cout<<"Card Number: ";
				getline(cin>>ws,card);
				cout<<"Success...\n"<<endl;
				break;
			}
			case 2: {
				string name, card;
				cout<<"Enter Name on Card: ";
				getline(cin>>ws,name);
				cout<<"Card Number: ";
				getline(cin>>ws,card);
				cout<<"Success...\n"<<endl;
				break;
			}
			case 3: {
				int recipient, downpayment;
				cout<<"Enter recipient number: ";
				cin>>recipient;
				cout<<"Advance downpayment / Full payment: ";
				while (true){
					cin>>downpayment;
					if (downpayment < 0){
					cout<<"Insufficient amount... ";
				}
				else {
					cout<<"Successfully sent to "<<recipient<<" amounting of Php "<<downpayment<<endl<<endl;
					break;
				}
				cout<<"Re-enter amount: ";
				}
				break;
			}
			case 4: {
				int downpayment;
				cout<<"Advance downpayment / Full payment: ";
				while (true){
					cin>>downpayment;
					if (downpayment < 0){
					cout<<"Insufficient amount... ";
				}
				else {
					cout<<"Successfully paid Php "<<downpayment<<endl<<endl;
					break;
				}
				cout<<"Re-enter amount: ";
				}
			break;	
			}
			default:
				cout<<"Invalid... Please re-enter\n"<<endl;
				continue;		
		}
		break;
	} while (true);
	
	return method;
}
int main(){
	string address, name, phoneNumber, reason, bill, room;
	int choice = 0;
	int payment, roomForTWo = 0, roomForThree = 0, roomForFour = 0;
	while (true){
		cout<<"\t========================"<<endl;
		cout<<"\t||Hotel Booking System||"<<endl;
		cout<<"\t========================"<<endl;
		cout<<"[1] - Booking for two persons"<<endl;
		cout<<"[2] - Booking for three persons"<<endl;
		cout<<"[3] - Booking for four persons"<<endl;
		cout<<"[4] - Cancel Booking"<<endl;
		cout<<"[5] - Checkout"<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;
		
		switch (choice){
			case 1: 
				cout<<"\nRoom costs for Php 10,000...\n";
				if(roomForTWo == 0){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: A"<<endl<<endl;
					methodOfPayment(payment);
					roomForTWo = 1;
				}
				else if (roomForTWo == 1){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: B"<<endl<<endl;
					methodOfPayment(payment);
					roomForTWo = 2;
				}
				else if (roomForTWo == 2){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: C"<<endl<<endl;
					methodOfPayment(payment);
					roomForTWo = 3;	
				}
				else if (roomForTWo == 3) {
					cout<<"Fully booked...\n\n";
				}
				continue;
			case 2: 
				cout<<"\nRoom costs for Php 12,500...\n";
				if(roomForThree == 0){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: D"<<endl<<endl;
					methodOfPayment(payment);
					roomForThree = 1;
				}
				else if (roomForThree == 1){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: E"<<endl<<endl;
					methodOfPayment(payment);
					roomForThree = 2;
				}
				else if (roomForThree == 2){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: F"<<endl<<endl;
					methodOfPayment(payment);
					roomForThree = 3;	
				}
				else if (roomForThree == 3) {
					cout<<"Fully booked...\n\n";
				}
				continue;
			case 3: 
				cout<<"\nRoom costs for Php 15,000...\n";
				if(roomForFour == 0){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: G"<<endl<<endl;
					methodOfPayment(payment);
					roomForFour = 1;
				}
				else if (roomForFour == 1){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: H"<<endl<<endl;
					methodOfPayment(payment);
					roomForFour = 2;
				}
				else if (roomForFour == 2){
					customerDetails(name, address, phoneNumber);
					cout<<"Assigned Room Alphabet: I"<<endl<<endl;
					methodOfPayment(payment);
					roomForFour = 3;	
				}
				else if (roomForFour == 3) {
					cout<<"Fully booked...\n\n";
				}
				continue;
			case 4 : 
				cout<<"Why did you cancel?: ";
				getline(cin>>ws,reason);
				cout<<"Successfully cancelled... Thank you!\n";
				break;			
			case 5: 
				checkOut(name, room, bill);
				methodOfPayment(payment);
				cout<<"Thank you for checking in with us...";
				break;	
			default: 
				cout<<"Invalid....Please re-enter: "<<endl<<endl;				
				continue;
			
		}
		break;
	}
	return 0;
}
