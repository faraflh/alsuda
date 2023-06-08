#include <iostream>
#include <ctype.h>
#include <stack>
using namespace std;

string getPostfix(string str);
double evaluate(string str);
bool hasPrecedence(char a, char b);
int main() {
    string infixString;
    string postFixString;
    bool valid = false;
    cout << "Infix : ";
    getline(cin, infixString);
    postFixString = getPostfix(infixString);
    cout << "Postfix : " << postFixString << endl;
    cout << "Hasil : " << evaluate(postFixString) << endl;
    return 0;
}

string getPostfix(string str) {
    string postFixStr;
    stack<char> stack;
    for (int i = 0; i < str.length(); i++)     {
        if (isdigit(str[i]))
            postFixStr += str[i];
        else if (str[i] == '(')
            stack.push(str[i]);
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (stack.empty() || stack.top() == '(') {
                stack.push(str[i]);
            }
            else if (hasPrecedence(str[i], stack.top())) {
                stack.push(str[i]);
            }
            else {
                postFixStr += stack.top();
                stack.pop();
                stack.push(str[i]);
            }
        }
        else if (str[i] == ')') {
            while (stack.top() != '(')
            {
                postFixStr += stack.top();
                stack.pop();
            }
            if (stack.top() == '(')
                stack.pop();
        }
    }
    while (!stack.empty()) {
        postFixStr += stack.top();
        stack.pop();
    }
    return postFixStr;
}
double evaluate(string str) {
    int op1, op2;
    stack<int> stack;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]))
            stack.push(str[i] - 48);
        else if (str[i] == '+') {
            op1 = stack.top();
            stack.pop();
            op2 = stack.top();
            stack.pop();
            stack.push(op2 + op1);
        }
        else if (str[i] == '-') {
            op1 = stack.top();
            stack.pop();
            op2 = stack.top();
            stack.pop();
            stack.push(op2 - op1);
        }
        else if (str[i] == '*') {
            op1 = stack.top();
            stack.pop();
            op2 = stack.top();
            stack.pop();
            stack.push(op2 * op1);
        }
        else if (str[i] == '/') {
            op1 = stack.top();
            stack.pop();
            op2 = stack.top();
            stack.pop();
            stack.push(op2 / op1);
        }
    }
    return stack.top();
}

bool hasPrecedence(char a, char b) {
    int aWeight, bWeight = 2;
    if (a == '*' || a == '/')
        aWeight = 2;
    else
        aWeight = 1;
    return aWeight >= bWeight;
}
