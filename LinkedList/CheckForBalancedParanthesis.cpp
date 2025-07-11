#include <iostream>
#include <cstring>
#include <stack>   // we need stack to store opening brackets

// 🧠 Function to check if all brackets in the string are balanced
bool Check(char* C, int n);

int main() {
    char Expample[101];  // buffer for the input string
    std::cout << "Enter your statement: ";
    std::cin.getline(Expample, 101); // read a full line (max 100 chars)

    // ✅ Check if the expression is balanced
    if (Check(Expample, strlen(Expample))) {
        std::cout << "Result: balanced\n";
    } else {
        std::cout << "Result: NOT balanced\n";
    }

    return 0;
}

bool Check(char* C, int n) {
    std::stack<char> S; // 🧠 Stack to hold the opening brackets

    // 🔄 Loop through each character in the string
    for (int i = 0; i < n; i++) {

        // 🎯 If it's an opening bracket, push it onto the stack
        if (C[i] == '(' || C[i] == '{' || C[i] == '[') {
            S.push(C[i]); 
        }
        // 🎯 If it's a closing bracket...
        else if (C[i] == ')' || C[i] == '}' || C[i] == ']') {

            // ❌ If there's no matching opening bracket on the stack
            if (S.empty()) {
                return false; // unbalanced
            }

            // 🧠 Check the top of the stack
            char top = S.top();

            // ❌ If the closing bracket doesn't match the last opening bracket
            if ((C[i] == ')' && top != '(') ||
                (C[i] == '}' && top != '{') ||
                (C[i] == ']' && top != '[')) {
                return false; // mismatch found
            } else {
                S.pop(); // ✅ Matching pair found, pop the top
            }
        }
    }

    // ✅ Finally, the stack must be empty for the expression to be balanced
    return S.empty();
}
