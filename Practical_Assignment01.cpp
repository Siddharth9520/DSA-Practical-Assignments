#include <iostream>
using namespace std;
int main()
{
    int marks[50];
    int n;
    int total = 0;
    int highest, lowest;
    float average;
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }
    highest = marks[0];
    lowest = marks[0];
    for (int i = 0; i < n; i++)
    {
        total = total + marks[i];
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }
    average = (float)total / n;
    cout << "\n--- Student Mark Analysis ---\n";
    cout << "Marks are: ";
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }
    cout << "\nTotal Marks = " << total;
    cout << "\nAverage Marks = " << average;
    cout << "\nHighest Marks = " << highest;
    cout << "\nLowest Marks = " << lowest;
    cout << "\n\nStudent Result:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        if (marks[i] >= 40)
        {
            cout << "Pass";
        }
        else
        {
            cout << "Fail";
        }
        cout << endl;
    }
    return 0;
}