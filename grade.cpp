#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e;

    cout << "Enter marks for a: ";
    cin >> a;

    cout << "Enter marks for b: ";
    cin >> b;

    cout << "Enter marks for c: ";
    cin >> c;

    cout << "Enter marks for  d : ";
    cin >> d;

    cout << "Enter marks for e : ";
    cin >> e;

    int total = a + b + c + d + e;
    float percentage = (total / 500.0) * 100;

    if(percentage >= 90) {
        cout << "Grade: A" << endl;
    } else if (percentage >= 80) {
        cout << "Grade: B" << endl;
    } else if (percentage >= 70) {
        cout << "Grade: C" << endl;
    } else if (percentage >= 60) {
        cout << "Grade: D" << endl;
    } else {
        cout << "Grade: F" << endl;
    }
}
