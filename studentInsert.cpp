#include <iostream>
using namespace std;

int main()
{
    int marks[100] = {70, 80, 90};
    int n = 3;
    int choice, pos, value;

    cout << "1. Insert\n";
    cout << "2. Update\n";
    cout << "3. Delete\n";
    cout << "4. Display\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter position: ";
        cin >> pos;
        cout << "Enter marks: ";
        cin >> value;

        for (int i = n; i > pos; i--)
            marks[i] = marks[i - 1];

        marks[pos] = value;
        n++;
    }

    else if (choice == 2)
    {
        cout << "Enter position: ";
        cin >> pos;
        cout << "Enter new marks: ";
        cin >> value;

        marks[pos] = value;
    }

    else if (choice == 3)
    {
        cout << "Enter position: ";
        cin >> pos;

        for (int i = pos; i < n - 1; i++)
            marks[i] = marks[i + 1];

        n--;
    }

    else if (choice == 4)
    {
        for (int i = 0; i < n; i++)
            cout << marks[i] << " ";
    }

    return 0;
}