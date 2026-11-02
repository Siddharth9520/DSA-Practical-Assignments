#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string phone;
    string name;
    int duration;
    Node* next;
};

Node* head = NULL;

void addCall()
{
    Node* newNode = new Node();

    cout << "\nEnter Caller Name: ";
    cin >> newNode->name;

    cout << "Enter Phone Number: ";
    cin >> newNode->phone;

    cout << "Enter Call Duration (in minutes): ";
    cin >> newNode->duration;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nCall Added Successfully!\n";
}

void displayCalls()
{
    if (head == NULL)
    {
        cout << "\nCall Log is Empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== CALL LOG ==========\n";

    while (temp != NULL)
    {
        cout << "Caller Name   : " << temp->name << endl;
        cout << "Phone Number  : " << temp->phone << endl;
        cout << "Call Duration : " << temp->duration << " minutes" << endl;
        cout << "------------------------------\n";

        temp = temp->next;
    }
}

void searchCall()
{
    if (head == NULL)
    {
        cout << "\nCall Log is Empty.\n";
        return;
    }

    string searchNumber;

    cout << "\nEnter Phone Number to Search: ";
    cin >> searchNumber;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->phone == searchNumber)
        {
            cout << "\nCall Found!\n";
            cout << "Caller Name   : " << temp->name << endl;
            cout << "Phone Number  : " << temp->phone << endl;
            cout << "Call Duration : " << temp->duration << " minutes" << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nCall Not Found.\n";
}

void deleteCall()
{
    if (head == NULL)
    {
        cout << "\nCall Log is Empty.\n";
        return;
    }

    string searchNumber;

    cout << "\nEnter Phone Number to Delete: ";
    cin >> searchNumber;

    if (head->phone == searchNumber)
    {
        Node* temp = head;

        head = head->next;

        delete temp;

        cout << "\nCall Deleted Successfully!\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->phone == searchNumber)
        {
            Node* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;

            cout << "\nCall Deleted Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nCall Not Found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n================================";
        cout << "\n      CALL LOG MANAGEMENT";
        cout << "\n================================";
        cout << "\n1. Add Call";
        cout << "\n2. Display Calls";
        cout << "\n3. Search Call";
        cout << "\n4. Delete Call";
        cout << "\n5. Exit";
        cout << "\n================================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addCall();
        }
        else if (choice == 2)
        {
            displayCalls();
        }
        else if (choice == 3)
        {
            searchCall();
        }
        else if (choice == 4)
        {
            deleteCall();
        }
        else if (choice == 5)
        {
            cout << "\nProgram Ended.\n";
        }
        else
        {
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}