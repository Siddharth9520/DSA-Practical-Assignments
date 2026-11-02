#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];
int hashFunction(int key)
{
    return key % SIZE;
}
void insert(int key)
{
    int index = hashFunction(key);

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}
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
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
    insert(10);
    insert(25);
    insert(35);
    insert(42);
    insert(52);
    display();
    return 0;
}