#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int maximumStudents = 50;
	int maximumQuizzes = 10;
    string studentNames[maximumStudents];
    double quizScores[maximumStudents][maximumQuizzes];
    double studentAverages[maximumStudents];
    double quizAverages[maximumQuizzes];
    double totalAverage = 0;
    int numOfStudents, numOfQuizzes;
   
	cout <<"\t Overview of Class Grades"<< endl<< endl;
    cout << "Enter the number of students: ";
    cin >> numOfStudents;
    cout << "Enter the number of quizzes: ";
    cin >> numOfQuizzes;

    // Read in data for each student
    for (int i = 0; i < numOfStudents; i++)
    {
        cout << "\nEnter student name: ";
        cin.ignore(); 
        getline(cin, studentNames[i]);
        cout << "Enter quiz scores for " << studentNames[i] << ": ";
        for (int j = 0; j < numOfQuizzes; j++)
        {
            cin >> quizScores[i][j];
        }
    }
    // Compute averages for each student
    for (int i = 0; i < numOfStudents; i++)
    {
        double sum = 0;
        for (int j = 0; j < numOfQuizzes; j++)
        {
            sum += quizScores[i][j];
        }
        studentAverages[i] = sum / numOfQuizzes;
    }
    // Compute averages for each quiz
    for (int j = 0; j < numOfQuizzes; j++)
    {
        double sum = 0;
        for (int i = 0; i < numOfStudents; i++)
        {
            sum += quizScores[i][j];
        }
        quizAverages[j] = sum / numOfStudents;
    }
    // Output data for each student
    cout << endl;
    cout << "Student Name\t";
    for (int j = 0; j < numOfQuizzes; j++)
    {
        cout << "Quiz " << j + 1 << "\t";
    }
    cout << "Average" << endl;

    for (int i = 0; i < numOfStudents; i++)
    {
        cout << setw(15) << left << studentNames[i] << "\t";
        for (int j = 0; j < numOfQuizzes; j++)
        {
            cout << setw(5) << right << quizScores[i][j] << "\t";
        }
        cout << setw(6) << fixed << setprecision(1) << studentAverages[i] << endl;
    }
    // Output averages for each quiz
    cout<< "Quiz Averages\t";
    for (int j = 0; j < numOfQuizzes; j++)
    {
        cout << setw(5) << fixed << setprecision(1) << quizAverages[j] << "\t";
        totalAverage += quizAverages[j];
    }
    totalAverage /= numOfQuizzes;
    cout<< setw(6) << fixed << setprecision(1) << totalAverage;
   
    return 0;
}




