#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Helper function: returns precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Helper function: checks if the character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix to postfix
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> opStack; // For storing operators and parentheses
    std::string postfix = ""; // Result string

    for (char ch : infix) {
        // If character is a whitespace, skip
        if (ch == ' ') continue;

        // If operand, add to output
        if (isalnum(ch)) { // Accepts numbers or letters
            postfix += ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            opStack.push(ch);
        }
        // If ')', pop and output from the stack until '(' is found
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop(); // Pop '('
        }
        // If operator
        else if (isOperator(ch)) {
            // While top of stack has same or greater precedence, pop it
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(ch); // Push current operator
        }
    }

    // Pop any remaining operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression (assumes single-digit numbers)
int evaluatePostfix(const std::string& postfix) {

    std::stack<int> values;
    
    for (char ch : postfix) {
        // If operand, push to stack
        if (isdigit(ch)) {
            // int num =0;
            // num = num * 10 + (ch - '0');
            // values.push(num);
            values.push(ch - '0'); // Convert char to int
        }
        // If operator, pop two values, do operation, push result
        else if (isOperator(ch)) {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            int res = 0;
            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            values.push(res);
        }
    }
    return values.top();
}

int main() {
    // Example: infix expression
std::string infix = "3+(4*5)-6/(1+1)";
    std::cout << "Infix: " << infix << std::endl;

    // 1. Convert infix to postfix
    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix: " << postfix << std::endl;
    // Note: for "3+(4*5)-6/(1+1)", output will be "345*+611+/−"

    // 2. Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    std::cout << "Evaluated Result: " << result << std::endl;

    // CODE NOTES:
    // - If the user inputs an infix expression, our program first converts it to postfix for easy evaluation.
    // - The postfix evaluation uses a stack, making the calculation very straightforward for the computer.
    // - This two-step process (convert, then evaluate) is used by many calculators, compilers, and interpreters!

    return 0;
}