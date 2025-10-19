#include <iostream>
#include <string>
#include <cctype>
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

int evaluatePostfix(string postfix) {
    int numStack[MAX];
    int top = -1;

    for (int i = 0; i < postfix.size(); i++) {
        char ch = postfix[i];
        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            numStack[++top] = ch - '0';
        } else {
            int val2 = numStack[top--];
            int val1 = numStack[top--];

            switch (ch) {
                case '+': numStack[++top] = val1 + val2; break;
                case '-': numStack[++top] = val1 - val2; break;
                case '*': numStack[++top] = val1 * val2; break;
                case '/': numStack[++top] = val1 / val2; break;
                case '^': numStack[++top] = val1 ^ val2; break; 
            }
        }
    }
    return numStack[top];
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    bool numeric = true;
    for (char c : infix) {
        if (!isdigit(c) && !isspace(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')') {
            numeric = false;
            break;
        }
    }

    if (numeric) {
        int result = evaluatePostfix(postfix);
        cout << "Evaluated Result: " << result << endl;
    } else {
        cout << "(Evaluation skipped expression contains variables.)" << endl;
    }

    return 0;
}
