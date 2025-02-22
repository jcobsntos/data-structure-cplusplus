#include <iostream>
using namespace std;

int main() {
	int numbers = 10;
    int nums[numbers];
    double sum, average;
    int largest = INT_MIN, smallest = INT_MAX;

    cout << "\tEnter 10 integers " << endl;
	
	// Read in 10 integers into the array
    for (int i = 0; i < numbers; i++) {
    	cout << "\nEnter integer #" << i + 1 << ": ";
        cin >> nums[i];
        sum += nums[i];
		
		// Find the largest and smallest numbers
        if (nums[i] > largest) {
            largest = nums[i];
        }

        if (nums[i] < smallest) {
            smallest = nums[i];
        }
	}
	// Compute the average
    average = sum / numbers;
    cout << "\nThe average is: " << average << endl;
    cout << "The largest number is: " << largest << endl;
    cout << "The smallest number is: " << smallest << endl;

    return 0;
}

