#include <iostream>
#include <string>
using namespace std;

string encrypt(string input) {
    string output = "";
    for (char c : input) {
        if (isalpha(c)) {
            char shifted_char;
            if (islower(c)) {
                shifted_char = ((c - 'a' + 1) % 26) + 'a';
            } else {
                shifted_char = ((c - 'A' + 1) % 26) + 'A';
            }
            output += shifted_char;
        } else {
            output += c;
        }
    }
    return output;
}

int main() {
	string plaintext;
	bool valid_input = false;
	while (!valid_input) {
        cout << "Enter a line of text: ";
        getline(cin, plaintext);
        // Input validation
        valid_input = true;
        for (char c : plaintext) {
            if (!isalpha(c) && !isspace(c) && c != ',' && c != '.') {
                cerr << "Invalid characters..." << endl;
                valid_input = false;
                break;
            }
        }
    }
    string ciphertext = encrypt(plaintext);
    cout << "Original text: " << plaintext << endl;
    cout << "Encrypted text: " << ciphertext << endl; 
    return 0;
}


