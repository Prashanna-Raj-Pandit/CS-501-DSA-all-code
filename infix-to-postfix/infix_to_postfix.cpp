/*
Author Name: Prashanna Raj Pandit
--------------------------------------------------------------------------------------------------------
Program Information: a C++ program that (a) read infix expressions from keyboard and print the infix, 
(b) convert each expression to postfix notation print each postfix, and 
(c) evaluate each postfix expression to determine its value and print each value.
---------------------------------------------------------------------------------------------------------
Submitted on: September 22, 2024
---------------------------------------------------------------------------------------------------------
Deadline: September 25, 2024, 10:10 PM
---------------------------------------------------------------------------------------------------------
Instruction for grader: My code also has an error checking for input of infix expression. For future 
enhancement, i have also included code for operator '^' with highest precedence but, it's not functional 
here. Only +, -, *, /  are accepted according to the question.
*/

#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

#define SIZE 100

using namespace std;

bool is_operator(char symbol) {  // return true if the symbol is an operator.
    return (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;  // exponent operator, highest precedence
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;  // lowest precedence
    } else {
        return 0;
    }
}

map<char, int> fileHandling() {   // this function deals with opening symbol.dat file and returning a map<char, int>
    map<char, int> symbolMap;  // char maps to the value associated with a variable defined in symbol.dat file.
    vector<char> symbols;  // created a vector to store only the allowed variables in the expression (not necessary, just experimental).
    ifstream datafile("symbol.dat");  // opening file
    if (!datafile) {
        cout << "Unable to open symbol.dat file";
        exit(1);
    }

    char symbol;
    string line;
    while (getline(datafile, line)) {  // extracting each line of the file and assigning it to the string variable `line`.
        istringstream iss(line);
        char key;
        int value;
        if (iss >> key >> value) {
            symbolMap[tolower(key)] = value;  // storing keys as lowercase
            symbols.push_back(key);
        }
    }

    datafile.close();
    // Uncomment if you want to display allowed symbols
    // cout << "The expression should be from the following symbols" << endl;
    // for (char syl : symbols) {
    //     cout << syl << " ";
    // }
    // cout << endl;

    return symbolMap;
}

bool checkErrors(const string& infix_exp, const map<char, int>& symbolMap) { // checking errors in the infix expression
    stack<char> parentheses;
    bool lastWasOperator = false;
    bool lastWasOperand = false;

    for (size_t i = 0; i < infix_exp.length(); ++i) {
        char current = tolower(infix_exp[i]);  // convert to lowercase

        if (isspace(current)) {  // checking for white space in infix expression
            cout << "Error: No white space is allowed in infix expression." << endl << endl;
            return false;
            // continue;    // if white space is acceptable just ignore it.
        }

        if (current == '^') {  // throwing error if the input has the '^' operator
            cout << "Error: Invalid Operator '" << current << "' :Only '+', '-', '*', '/' operators are allowed." << endl << endl;
            return false;
        }

        if (isalpha(current)) {
            // Check if the operand exists in symbolMap
            if (symbolMap.find(current) == symbolMap.end()) {
                cout << "Error: Operand '" << current << "' has no entry in the file." << endl << endl;
                return false;
            }

            if (lastWasOperand) { // throw error if two consecutive operands occur in expression
                cout << "Error: Incorrect variable form or two consecutive operands." << endl << endl;
                return false;
            }

            lastWasOperand = true;
            lastWasOperator = false;
        } else if (is_operator(current)) {
            if (lastWasOperator) {  // throw error if the expression has two consecutive operators.
                cout << "Error: Two consecutive operators '" << infix_exp[i - 1] << current << "'." << endl << endl;
                return false;
            }

            if (i == 0 || i == infix_exp.length() - 1) {
                cout << "Error: Operator at the beginning or end of the expression." << endl << endl;
                return false;
            }

            lastWasOperator = true;
            lastWasOperand = false;
        } else if (current == '(') {
            parentheses.push(current);
            lastWasOperator = false;
        } else if (current == ')') {
            if (parentheses.empty()) {  // throw error if the expression has a closing parenthesis without an opening parenthesis.
                cout << "Error: Unmatched ')' in expression." << endl << endl;
                return false;
            }
            parentheses.pop();
            lastWasOperator = false;
        } else {  // throw error if the expression has any invalid character.
            cout << "Error: Invalid character '" << current << "' in expression." << endl << endl;
            return false;
        }
    }

    if (!parentheses.empty()) {
        cout << "Error: Mismatched parentheses in expression." << endl << endl;
        return false;
    }

    if (lastWasOperator) {
        cout << "Error: Expression ends with an operator." << endl << endl;
        return false;
    }

    return true;
}

void InfixToPostfix(const string& infix_exp, string& postfix_exp) {
    stack<char> s;
    s.push('(');  // push '(' onto stack

    string infix;
    for (char item : infix_exp) {
        infix += tolower(item);  // convert each character to lowercase
    }
    infix += ")";  // add ')' to infix expression

    for (char item : infix) {  // range-based for loop
        if (item == '(') {
            s.push(item);
        } else if (isalpha(item)) {  // check if item is operand
            postfix_exp += item;  // add operand symbol to postfix expression
        } else if (is_operator(item)) {  // if symbol is operator
            while (!s.empty() && is_operator(s.top()) && precedence(s.top()) >= precedence(item)) {
                postfix_exp += s.top();
                s.pop();
            }
            s.push(item);  // push current operator symbol onto stack
        } else if (item == ')') {  // if current symbol is ')'
            while (!s.empty() && s.top() != '(') {
                postfix_exp += s.top();
                s.pop();
            }
            s.pop();  // pop the '('
        } else {
            cout << "\nInvalid infix Expression.\n";  // illegal symbol
            exit(1);
        }
    }

    if (!s.empty()) {
        cout << "\nInvalid infix Expression.\n";  // mismatched parentheses
        exit(1);
    }
}

int evaluatePostFixExpression(const string& postfix, map<char, int>& symbolMap) {
    stack<int> stack;
    for (char symbol : postfix) {
        symbol = tolower(symbol);  // convert each character to lowercase
        if (symbolMap.find(symbol) != symbolMap.end()) {
            // If the symbol is an operand, push its value onto the stack
            stack.push(symbolMap.at(symbol));
        } else {
            // If the symbol is an operator, pop operands from the stack and perform operation
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();

            switch (symbol) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': stack.push(operand1 / operand2); break;
                default: throw invalid_argument("Invalid operator");
            }
        }
    }
    return stack.top();
}

int main() {
    map<char, int> symbolMap = fileHandling();

    while (true) {
        string infix, postfix;
        cout << "Please enter an Infix expression. Enter E to stop." << endl;
        getline(cin, infix);  // get infix expression
        if (infix.find('E') != string::npos) {  // handle both 'E' and 'e'
            break;
        }

        if (infix.empty()) {
            cout << "Error: Empty infix expression. Please try again." << endl << endl;
            continue;
        }

        if (!checkErrors(infix, symbolMap)) {
            continue;
        }

        cout << "\nInfix expression is:\t" << infix << endl;
        InfixToPostfix(infix, postfix);  // Convert to postfix
        cout << "Postfix Expression is:\t" << postfix << endl;

        int result = evaluatePostFixExpression(postfix, symbolMap);  // call for evaluating postfix expression
        cout << "Expression Evaluates to:\t" << result << endl << endl;
    }

    return 0;
}


