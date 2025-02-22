#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	string name;
	double quizzes,recitation,board_works,assignments,major_exam,others;
	double cra,prelim_grade;
	int total_cra = 500;
	cout<<"Computation of grades for the preliminary period"<<endl;
	cout<<"Enter student's name: ";
	getline(cin,name);
	cout<<"Enter grade of quizzes = ";
	cin>>quizzes;
	cout<<"Enter grade of recitation = ";
	cin>>recitation;
	cout<<"Enter grade of boardworks = ";
	cin>>board_works;
	cout<<"Enter grade of assignments = ";
	cin>>assignments;
	cout<<"Enter grade of other requirements = ";
	cin>>others;
	cout<<"Enter grade of major exam = ";
	cin>>major_exam;
	cra = quizzes+recitation+board_works+assignments+others;
	prelim_grade = (((cra*2+major_exam)*60)/(total_cra*2+major_exam))+40;
	
	cout<<"----------------------------------------"<<endl;
	cout<<"Student's' Name: "<<name<<endl;
	cout<<"Prelim Grade: "<<prelim_grade<<endl;
	cout<<"Obtained Letter Grade: ";
	
	if(prelim_grade == 100){
		cout<<"A = 100";
	}
	else if (prelim_grade >= 90 && prelim_grade <= 99){
		cout<<"B = 90-99";
	}
	else if (prelim_grade >= 80 && prelim_grade <= 89){
		cout<<"C = 80-89";
	}
	else if (prelim_grade >= 75 && prelim_grade <= 79){
		cout<<"D = 75-79";
	}
	else if (prelim_grade < 75){
		cout<<"F = Below 75";
	}
	
	return 0;
}






