#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, choice, pos, value;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (true)
    {
        cout << "\n========== ARRAY OPERATIONS ==========\n";
        cout << "1. Insert Element\n";
        cout << "2. Update Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Display Array\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;

            if (pos < 1 || pos > n + 1)
            {
                cout << "Invalid Position!\n";
                break;
            }

            cout << "Enter value to insert: ";
            cin >> value;
            for (int i = n; i >= pos; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[pos - 1] = value;
            n++;

            cout << "Element Inserted Successfully.\n";
            break;
        }

        case 2:
        {
            cout << "Enter position to update (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n)
            {
                cout << "Invalid Position!\n";
                break;
            }

            cout << "Enter new value: ";
            cin >> value;

            arr[pos - 1] = value;

            cout << "Element Updated Successfully.\n";
            break;
        }

        case 3:
        {
            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n)
            {
                cout << "Invalid Position!\n";
                break;
            }
            for (int i = pos - 1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            n--;

            cout << "Element Deleted Successfully.\n";
            break;
        }

        case 4:
        {
            if (n == 0)
            {
                cout << "Array is Empty.\n";
            }
            else
            {
                cout << "Array Elements: ";
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;
        }

        case 5:
        {
            cout << "Program Terminated.\n";
            return 0;
        }

        default:
            cout << "Invalid Choice! Please Try Again.\n";
        }
    }

    return 0;
}