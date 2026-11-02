#include <iostream>
#include <queue>
#include <stdexcept>
#include <utility>
using namespace std;

class Stack {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) {
            throw underflow_error("Stack is empty");
        }

        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        if (q1.empty()) {
            throw underflow_error("Stack is empty");
        }

        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

    int size() {
        return q1.size();
    }
};

int main() {
    Stack s;

    s.push(15);
    s.push(25);
    s.push(35);

    cout << "Top element: " << s.top() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Popped element: " << s.pop() << endl;

    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    return 0;
}