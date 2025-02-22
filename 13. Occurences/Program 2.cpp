#include <iostream>
using namespace std;

void printOccuranceLetters(string sentence){
    int arr[26] = {0};
    int words = 1;
    for (int i=0; i < sentence.length(); i++){
        int x = tolower(sentence[i]);
        if (x >= 97 && x <=122){
            int index = x - (int)'a';
            arr[index]++;
        }
        if (sentence[i] == ' '){
            words++;
        }
    }
    printf("%-7d%s\n",words,"words");
    for (int i=0;i<26;i++){
        if (arr[i]>0){
            printf("%-7d%c\n",arr[i],(char)(i+97));
        }
    }
}

void printEncryptedOccuranceLetters(string sentence){
    int arr[26] = {0};
    int words = 1;
    for (int i=0; i < sentence.length(); i++){
        int x = tolower(sentence[i]);
        if (x >= 97 && x <=122){
            int index = x - (int)'a';
            arr[index]++;
        }
        if (sentence[i] == ' '){
            words++;
        }
    }
    printf("%-7d%s\n",words,"words");
    for (int i=0;i<26;i++){
        if (arr[i]>0){
            printf("%-7d%c\n",arr[i],(char)(((i+97)+1)));
        }
    }
}

int main(){
    string sentence;
    cout<<"Enter line of text: ";
    getline(cin, sentence);
    
    cout << "\nOriginal Occurrence of Letters: " << endl;
    printOccuranceLetters(sentence);

    cout << "\nEncrypted Occurrence of Letters (Caesar Cipher with shift 1): " << endl;
    printEncryptedOccuranceLetters(sentence);

    return 0;
}
