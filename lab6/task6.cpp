#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 100

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix;

    for (char ch : infix) {
        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            postfix += ch;
            postfix += ' ';
        } 
        else if (ch == '(') {
            st.push(ch);
        } 
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
                postfix += ' ';
            }
            st.pop(); 
        } 
        else { 
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                postfix += st.pop();
                postfix += ' ';
            }
            st.push(ch);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
        postfix += ' ';
    }

    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    for (char &ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int evaluatePrefix(string prefix) {
    int numStack[MAX];
    int top = -1;

    for (int i = prefix.size() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            numStack[++top] = ch - '0';
        } 
        else {
            int val1 = numStack[top--];
            int val2 = numStack[top--];
            int result = 0;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
            }

            numStack[++top] = result;
        }
    }
    return numStack[top];
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    bool numeric = true;
    for (char c : infix) {
        if (!isdigit(c) && !isspace(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != '(' && c != ')') {
            numeric = false;
            break;
        }
    }

    if (numeric) {
        int result = evaluatePrefix(prefix);
        cout << "Evaluated Result: " << result << endl;
    } else {
        cout << "(Evaluation skipped expression contains variables.)" << endl;
    }

    return 0;
}
