#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    string str;
    deque<char> dq;

    cout << "Enter a string: ";
    cin >> str;

    for (char ch : str) {
        dq.push_back(ch);
    }

    bool palindrome = true;

    while (dq.size() > 1) {
        char front = dq.front();
        char rear = dq.back();

        dq.pop_front();
        dq.pop_back();

        if (front != rear) {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
        cout << str << " is a palindrome.";
    else
        cout << str << " is not a palindrome.";

    return 0;
}