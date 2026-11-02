#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, pos, value;
    cout << "Enter the number of elements: ";  // Input number of elements
    cin >> n;
    cout << "Enter " << n << " elements:\n";  // Input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the position where you want to insert (1 to " << n + 1 << "): ";   // Input position and value
    cin >> pos;

    cout << "Enter the value to insert: ";
    cin >> value;
    if (pos < 1 || pos > n + 1)     // Check for valid position
    {
        cout << "Invalid Position!";
        return 0;
    }
    for (int i = n; i >= pos; i--)       // Shift elements to the right
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;   // Insert the value
    n++;                     // Increase array size
    cout << "\nArray after insertion:\n";         // Display updated array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}