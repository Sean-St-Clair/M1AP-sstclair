#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>

// TODO: More comments?

using namespace std;

bool stringContainsSpace(string input);

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

bool stringContainsSpace(string input) {
    for (int i = 0; i < input.length(); i++)
        if (isspace(input[i]))
            return true;
    return false;
}

char get_char_from_user() {
    string input;
    string prompt = "Enter a single character: ";
    cout << prompt;
    getline(cin, input);
    while (input.length() != 1) {
        if (input.length() < 1)
            cout << "No input. ";
        else cout << "Invalid input. ";
        cout << prompt;
        getline(cin, input);
    }
    return input[0];
}

string get_word_from_user() {
    string input;
    string prompt = "Enter a single word: ";
    cout << prompt;
    getline(cin, input);
    while (input.length() < 1 || stringContainsSpace(input)) {
        if (input.length() < 1)
            cout << "No input. ";
        else cout << "Invalid input. ";
        cout << prompt;
        getline(cin, input);
    }
    return input;
}

string get_sentence_from_user() {
    string input;
    string prompt = "Enter a sentence: ";
    cout << prompt;
    getline(cin, input);
    while (input.length() < 1) {
        cout << "No input. " << prompt;
        getline(cin, input);
    }
    return input;
}

int get_int_from_user() {
    string input;
    string excess;
    string prompt = "Enter a number: ";
    stringstream ss;
    int num;

    // Uses a string stream to process input into num
    cout << prompt;
    getline(cin, input);
    ss.str(input);
    ss >> num;

    while (input.length() < 1 || ss.fail() || ss.peek() != EOF) {
        if (input.length() < 1) {
            cout << "No input. ";
        } else cout << "Invalid input. ";
        ss.clear();
        excess = "";

        cout << prompt;
        getline(cin, input);
        ss.str(input);
        ss >> num;
    }
    return num;
}

double get_float_from_user() {
    string input;
    string excess;
    string prompt = "Enter a number: ";
    stringstream ss;
    double num;

    // Uses a string stream to process input into num
    cout << prompt;
    getline(cin, input);
    ss.str(input);
    ss >> num;

    while (input.length() < 1 || ss.fail() || ss.peek() != EOF) {
        if (input.length() < 1) {
            cout << "No input. ";
        } else cout << "Invalid input. ";
        ss.clear();
        excess = "";

        cout << prompt;
        getline(cin, input);
        ss.str(input);
        ss >> num;
    }
    return num;
}