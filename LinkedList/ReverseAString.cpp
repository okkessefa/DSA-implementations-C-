#include <iostream>  // for input/output
#include <stack>     // for std::stack
#include <cstring>   // for strlen



// Reverse function that takes a char array (string) and its length
void Reverse(char* C, int n) {
    std::stack<char> S;  // Create an empty stack of chars

    // 🔄 Push each character of the string onto the stack
    for (int i = 0; i < n; i++) {
        S.push(C[i]);  // put character into the stack
    }

    // 🔄 Pop each character off the stack and put it back into the string
    for (int i = 0; i < n; i++) {
        C[i] = S.top();  // top() gives the last pushed character
        S.pop();         // remove that character from the stack
    }
}

// 🏁 Main function
int main() {
    char C[51];  // array to hold the string (maximum length = 50 chars)
    std::cout << "Enter a string: ";
    std::cin.getline(C, 51);  // read the string including spaces (up to 50 chars)

    Reverse(C, strlen(C));  // call the Reverse function

    std::cout << "Output = " << C << std::endl;  // print the reversed string
    return 0;
}
