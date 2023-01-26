#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

char get_char_from_user();
string get_word_from_user();
string get_sentence_from_user();
int get_int_from_user();
double get_float_from_user();

int main() {
    char letter = get_char_from_user();
    cout << "You entered the character " << letter << endl;
    string word = get_word_from_user();
    cout << "You entered the word " << word << endl;
    string sentence = get_sentence_from_user();
    cout << "You entered the sentence: " << sentence << endl;
    int num = get_int_from_user();
    cout << "You entered the number " << num << endl;
    double flo = get_float_from_user();
    cout << "You entered the floating-point number " << flo << endl;
    return 0;
}

char get_char_from_user() {
    // TODO: Complete the function
    return '?';
}

string get_word_from_user() {
    // TODO: Complete the function
    return "?";
}

string get_sentence_from_user() {
    // TODO: Complete the function
    return "?";
}

int get_int_from_user() {
    // TODO: Complete the function
    return -1;
}

double get_float_from_user() {
    // TODO: Complete the function
    return -1.0;
}