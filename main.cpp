#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
 * This function takes a string and returns true if and only if it contains any whitespace characters
 */
bool stringContainsSpace(string input);

/*
 * This function prompts a user for input until a valid single character is entered.
 */
char get_char_from_user();

/*
 * This function prompts a user for input until a valid word is entered.
 */
string get_word_from_user();

/*
 * This function prompts a user for input until a valid sentence is entered.
 */
string get_sentence_from_user();

/*
 * This function prompts a user for input until a valid integer is entered.
 */
int get_int_from_user();

/*
 * This function prompts a user for input until a valid floating-point number is entered.
 */
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

    // Re-prompts user for input if more or less than 1 character is entered
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

    // Re-prompts user for input if it contains any whitespace characters
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

    // Re-prompts user for input if none is provided
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

    // Checks whether the string stream could properly read from the whole string to an integer
    while (input.length() < 1 || ss.fail() || ss.peek() != EOF) {
        if (input.length() < 1) {
            cout << "No input. ";
        } else cout << "Invalid input. ";
        ss.clear();
        excess = "";

        // Re-prompts user for input
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
    string prompt = "Enter a floating-point number: ";
    stringstream ss;
    float num;

    // Uses a string stream to process input into num
    cout << prompt;
    getline(cin, input);
    ss.str(input);
    ss >> num;

    // Checks whether the string stream could properly read from the whole string to a float
    while (input.length() < 1 || ss.fail() || ss.peek() != EOF) {
        if (input.length() < 1) {
            cout << "No input. ";
        } else cout << "Invalid input. ";
        ss.clear();
        excess = "";

        // Re-prompts user for input
        cout << prompt;
        getline(cin, input);
        ss.str(input);
        ss >> num;
    }
    return num;
}