#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Deleted element: " << s2.top() << endl;
        s2.pop();
    }

    void display() {
        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        cout << "Queue elements: ";

        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        stack<int> temp3;

        while (!temp1.empty()) {
            temp3.push(temp1.top());
            temp1.pop();
        }

        while (!temp3.empty()) {
            cout << temp3.top() << " ";
            temp3.pop();
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(35);

    q.display();
    q.dequeue();
    q.display();

    return 0;
}