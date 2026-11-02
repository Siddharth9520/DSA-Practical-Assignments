#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, pos;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nEnter the position to delete (1 to " << n << "): ";
    cin >> pos;

    if (pos < 1 || pos > n)
    {
        cout << "Invalid Position!";
        return 0;
    }
    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "\nArray after deletion:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}