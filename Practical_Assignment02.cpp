#include <iostream>
using namespace std;

int main()
{
    int parking[10];
    int choice, carNo, index;
    for (int i = 0; i < 10; i++)
    {
        parking[i] = -1;
    }
    while (true)
    {
        cout << "\n--- Parking Lot System ---\n";
        cout << "1. Park Car\n";
        cout << "2. Search Car\n";
        cout << "3. Display Parking Slots\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter car registration number: ";
            cin >> carNo;
            index = carNo % 10;
            int start = index;
            while (parking[index] != -1)
            {
                index = (index + 1) % 10;
                if (index == start)
                {
                    cout << "Parking lot is full.\n";
                    break;
                }
            }
            if (parking[index] == -1)
            {
                parking[index] = carNo;
                cout << "Car parked at slot " << index << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Enter car registration number to search: ";
            cin >> carNo;
            index = carNo % 10;
            int start = index;
            bool found = false;
            while (parking[index] != -1)
            {
                if (parking[index] == carNo)
                {
                    cout << "Car found at slot " << index << endl;
                    found = true;
                    break;
                }
                index = (index + 1) % 10;
                if (index == start)
                {
                    break;
                }
            }
            if (found == false)
            {
                cout << "Car not found.\n";
            }
        }
        else if (choice == 3)
        {
            cout << "\nParking Slots:\n";
            for (int i = 0; i < 10; i++)
            {
                if (parking[i] == -1)
                {
                    cout << "Slot " << i << " : Empty\n";
                }
                else
                {
                    cout << "Slot " << i << " : Car " << parking[i] << endl;
                }
            }
        }
        else if (choice == 4)
        {
            cout << "Program ended.\n";
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}