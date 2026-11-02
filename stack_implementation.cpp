
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// 1. Infix to Postfix
int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string post = "";

    for (char c : s) {
        if (isalnum(c))
            post += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                post += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   priority(st.top()) >= priority(c)) {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        post += st.top();
        st.pop();
    }
    return post;
}

// 2. Postfix Evaluation (single-digit operands)
int evaluatePostfix(string s) {
    stack<int> st;

    for (char c : s) {
        if (isdigit(c))
            st.push(c - '0');
        else if (c != ' ') {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

// 3. Stack using Linked List
struct Node {
    int data;
    Node* next;
};

Node* topNode = NULL;

void push(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = topNode;
    topNode = n;
    cout << "Pushed: " << x << endl;
}

void pop() {
    if (topNode == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = topNode;
    cout << "Popped: " << temp->data << endl;
    topNode = topNode->next;
    delete temp;
}

void peek() {
    if (topNode == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Top: " << topNode->data << endl;
}

void display() {
    Node* temp = topNode;

    if (temp == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    string infix, postfix;
    int choice, x;

    do {
        cout << "\n1. Infix to Postfix";
        cout << "\n2. Evaluate Postfix";
        cout << "\n3. Push";
        cout << "\n4. Pop";
        cout << "\n5. Peek";
        cout << "\n6. Display Stack";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix (no spaces): ";
                cin >> infix;
                cout << "Infix: " << infix << endl;
                cout << "Postfix: " << infixToPostfix(infix) << endl;
                break;

            case 2:
                cout << "Enter postfix (single digits): ";
                cin >> postfix;
                cout << "Result: " << evaluatePostfix(postfix) << endl;
                break;

            case 3:
                cout << "Enter value: ";
                cin >> x;
                push(x);
                break;

            case 4:
                pop();
                break;

            case 5:
                peek();
                break;

            case 6:
                display();
                break;
        }
    } while (choice != 0);

    return 0;
}
