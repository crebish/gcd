#include <iostream>
#include <fstream>

using namespace std;

void gcd(int num1, int num2, int counter, ofstream &output);

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        cerr << "Usage: ./a.out outputFile" << endl;
        exit(EXIT_FAILURE);
    }

    ofstream output;
    output.open(argv[1]);

    int num1, num2;
    cout << "Input two positive integers to calculate the GCD: ";
    cin >> num1 >> num2;

    if (num1 < 0 or num2 < 0) {
        output << "Cannot operate on negative integers" << endl;
    } else {
        gcd(max(num1, num2), min(num1, num2), 1, output);
    }

    return 0;
}

void gcd(int num1, int num2, int counter, ofstream &output) {
    int result = num1 % num2; 

    if (result == 0) {
        output << "The GCD is " << abs(num2) << " and was found in " << counter 
            << " calculations." << endl;
        return;
    } else {
        gcd(num2, result, counter + 1, output);
    }
}