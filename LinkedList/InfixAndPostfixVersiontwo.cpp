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

    for (size_t i =0 ; i< infix.length(); ++i) {
        // If character is a whitespace, skip 
        if (infix[i] == ' ') continue;

        if(isdigit(infix[i])) {
            // multi digit support
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i];
                ++i;
            }
            postfix += ' '; // Add space after number for clarity
            --i; // Adjust index since the loop will increment it
        }
        // If operand, add to output
        else if (isalpha(infix[i])) { // Accepts numbers or letters
            postfix += infix[i];
            postfix += ' '; // Add space after operand for clarity
        }
        // If '(', push to stack
        else if (infix[i] == '(') {
            opStack.push(infix[i]);
        }
        // If ')', pop and output from the stack until '(' is found
        else if (infix[i] == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top(); opStack.pop();
                postfix += ' '; // Add space after operator for clarity
            }
            if (!opStack.empty()) opStack.pop(); // Pop '('
        }
        // If operator
        else if (isOperator(infix[i])) {
            // While top of stack has same or greater precedence, pop it
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(infix[i])) {
                postfix += opStack.top(); opStack.pop();
                postfix += ' '; // Add space after operator for clarity
            }
            opStack.push(infix[i]); // Push current operator
        }
    }

    // Pop any remaining operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top(); opStack.pop();
        postfix += ' '; // Add space after operator for clarity
        
    }
    
    return postfix;
}

std::string postfixToinfix(const std::string& postfix) {
    // Function to evaluate a postfix expression (assumes single-digit numbers)
    std::stack<std::string> inffixStack;
    std::stack<std::string> operatorStack;
    std::string Infix = ""; // Result string
    for(size_t i = 0; i< postfix.length(); i++){
        if(postfix[i] == ' ') 
        {
            continue; // skip whitespace
            i++;
        }
        if(isdigit(postfix[i]))
        { // if the character is a number, push it to the stack
            std::string num = "";
            while(i < postfix.length() && isdigit(postfix[i]))
            {   
                num+= postfix[i];
                i++;
            }
            inffixStack.push(num);
        }
        else if(isalpha(postfix[i]))
        {
             // For variable names (single char: A, x, y, etc.)
            inffixStack.push(std::string(1, postfix[i]));
            i++;
        }
        else if(isOperator(postfix[i]))
        {
            operatorStack.push(std::string(1, postfix[i]));
            std::string oprt = operatorStack.top() ; operatorStack.pop();
            std::string b = inffixStack.top(); inffixStack.pop();
            std::string a = inffixStack.top(); inffixStack.pop();
            std::string newinfix = "(" +   a  + oprt + b + ')';
            inffixStack.push(newinfix);
            i++;
        }
        else
        {
            i++;
        }
    }
    return inffixStack.top(); // The final result is on the top of the stack
}

int evaluatePostfix(const std::string& postfix) {
    std::stack<int> values;
    size_t i  = 0; // This variable is not used, but kept for consistency with the original request
    while(i < postfix.length()){
        if(postfix[i] == ' ') {
            i++; 
            continue; // Skip whitespace
        }
        if (isdigit(postfix[i])) {
            int num = 0;
            while(i < postfix.length() && isdigit(postfix[i])){
                num = num * 10 + postfix[i] - '0'; i++;
            }
            values.push(num); // Convert char to int
        }
        // If operator, pop two values, do operation, push result
        else if (isOperator(postfix[i])) {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            int res = 0;
            switch (postfix[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            values.push(res); i++;
        }    
        else{   
            // Skip any other chracter(shouldn't happen)
            i++;
        }
    }
    return values.top(); // The final result is on the top of the stack
}

int main() {
    // // Example: infix expression
    // std::string infix = "3+(4*5)-6/(1+1)";
    // std::cout << "Infix: " << infix << std::endl;
    
    // // 1. Convert infix to postfix
    // std::string postfix = infixToPostfix(infix);
    // std::cout << "Postfix: " << postfix << std::endl;
    // Note: for "3+(4*5)-6/(1+1)", output will be "345*+611+/−"
    
    // 2. Convert postfix to infix 
    // Example postfix expression 
    std::string postfix = "113 4 5 * + 6 1 1 + / -"; 
    std::cout << "Posfix: " << postfix << std::endl;
    std::string new_infix = postfixToinfix(postfix);
    std::cout << "Infix: " << new_infix << std::endl;
    // Note: for "345*+611+/−", output will be "3 + ( 4 * 5 ) - 6 / ( 1 + 1 )"
    
    // 3. Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    std::cout << "Evaluated Result: " << result << std::endl;
    

    // CODE NOTES:
    // - If the user inputs an infix expression, our program first converts it to postfix for easy evaluation.
    // - The postfix evaluation uses a stack, making the calculation very straightforward for the computer.
    // - This two-step process (convert, then evaluate) is used by many calculators, compilers, and interpreters!

    return 0;
}