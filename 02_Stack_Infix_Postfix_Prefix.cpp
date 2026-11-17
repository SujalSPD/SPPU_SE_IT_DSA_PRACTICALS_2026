
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    char data;
    Node *next;
};

Node *top = NULL;

// Insert element into stack
void push(char x) {
    Node *n = new Node{x, top};
    top = n;
}

// Remove element from stack
char pop() {
    if (top == NULL) return '\0';

    char x = top->data;
    Node *t = top;
    top = top->next;
    delete t;
    return x;
}

int prec(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

// Infix to Postfix
string postfix(string in) {
    string out = "";

    for (char c : in) {
        if (isalnum(c))
            out += c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (top && top->data != '(')
                out += pop();
            if (top) pop();
        }
        else {
            while (top && top->data != '(' &&
                  (prec(top->data) > prec(c) ||
                  (prec(top->data) == prec(c) && c != '^')))
                out += pop();
            push(c);
        }
    }

    while (top) out += pop();
    return out;
}

// Infix to Prefix
string prefix(string in) {
    reverse(in.begin(), in.end());

    for (char &c : in) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string out = "";
    for (char c : in) {
        if (isalnum(c))
            out += c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (top && top->data != '(')
                out += pop();
            if (top) pop();
        }
        else {
            while (top && top->data != '(' &&
                  (prec(top->data) > prec(c) ||
                  (prec(top->data) == prec(c) && c == '^')))
                out += pop();
            push(c);
        }
    }

    while (top) out += pop();

    reverse(out.begin(), out.end());
    return out;
}

int main() {
    string exp;

    cout << "Enter Infix Expression: ";
    cin >> exp;

    cout << "Postfix: " << postfix(exp) << endl;
    cout << "Prefix: " << prefix(exp) << endl;

    return 0;
}
