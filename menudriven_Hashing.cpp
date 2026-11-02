#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

// Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

// Insert
void insert(int key)
{
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == startIndex)
        {
            cout << "Hash table is full!\n";
            return;
        }
    }

    hashTable[index] = key;
    cout << "Value inserted successfully.\n";
}

// Search
void search(int key)
{
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            cout << "Value found at index " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == startIndex)
            break;
    }

    cout << "Value not found.\n";
}

// Display
void display()
{
    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Index " << i << " : ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}

int main()
{
    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    int choice, key;

    do
    {
        cout << "\n===== HASH TABLE MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> key;
            insert(key);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> key;
            search(key);
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Program exited.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}