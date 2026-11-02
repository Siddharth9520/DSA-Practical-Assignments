#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int PNR;
    string name;
    int age;
    int trainNumber;
    int seatNumber;

    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void addReservation()
{
    Node* newNode = new Node();

    cout << "\nEnter PNR: ";
    cin >> newNode->PNR;

    cout << "Enter Passenger Name: ";
    cin >> newNode->name;

    cout << "Enter Age: ";
    cin >> newNode->age;

    cout << "Enter Train Number: ";
    cin >> newNode->trainNumber;

    cout << "Enter Seat Number: ";
    cin >> newNode->seatNumber;

    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "\nReservation Added Successfully!\n";
}

void displayForward()
{
    if (head == NULL)
    {
        cout << "\nNo Reservations.\n";
        return;
    }

    Node* temp = head;

    cout << "\n====== RESERVATIONS (FORWARD) ======\n";

    while (temp != NULL)
    {
        cout << "PNR          : " << temp->PNR << endl;
        cout << "Passenger    : " << temp->name << endl;
        cout << "Age          : " << temp->age << endl;
        cout << "Train Number : " << temp->trainNumber << endl;
        cout << "Seat Number  : " << temp->seatNumber << endl;
        cout << "------------------------------------\n";

        temp = temp->next;
    }
}

void displayBackward()
{
    if (tail == NULL)
    {
        cout << "\nNo Reservations.\n";
        return;
    }

    Node* temp = tail;

    cout << "\n====== RESERVATIONS (BACKWARD) ======\n";

    while (temp != NULL)
    {
        cout << "PNR          : " << temp->PNR << endl;
        cout << "Passenger    : " << temp->name << endl;
        cout << "Age          : " << temp->age << endl;
        cout << "Train Number : " << temp->trainNumber << endl;
        cout << "Seat Number  : " << temp->seatNumber << endl;
        cout << "-------------------------------------\n";

        temp = temp->prev;
    }
}

void searchReservation()
{
    if (head == NULL)
    {
        cout << "\nNo Reservations.\n";
        return;
    }

    int searchPNR;

    cout << "\nEnter PNR to Search: ";
    cin >> searchPNR;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->PNR == searchPNR)
        {
            cout << "\nReservation Found!\n";
            cout << "PNR          : " << temp->PNR << endl;
            cout << "Passenger    : " << temp->name << endl;
            cout << "Age          : " << temp->age << endl;
            cout << "Train Number : " << temp->trainNumber << endl;
            cout << "Seat Number  : " << temp->seatNumber << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nReservation Not Found.\n";
}

void cancelReservation()
{
    if (head == NULL)
    {
        cout << "\nNo Reservations.\n";
        return;
    }

    int searchPNR;

    cout << "\nEnter PNR to Cancel: ";
    cin >> searchPNR;

    Node* temp = head;

    while (temp != NULL && temp->PNR != searchPNR)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "\nReservation Not Found.\n";
        return;
    }

    if (temp == head && temp == tail)
    {
        head = NULL;
        tail = NULL;
    }

    else if (temp == head)
    {
        head = head->next;
        head->prev = NULL;
    }

    else if (temp == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << "\nReservation Cancelled Successfully!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n       TRAIN RESERVATION SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Add Reservation";
        cout << "\n2. Display Forward";
        cout << "\n3. Display Backward";
        cout << "\n4. Search Reservation";
        cout << "\n5. Cancel Reservation";
        cout << "\n6. Exit";
        cout << "\n====================================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addReservation();
        }
        else if (choice == 2)
        {
            displayForward();
        }
        else if (choice == 3)
        {
            displayBackward();
        }
        else if (choice == 4)
        {
            searchReservation();
        }
        else if (choice == 5)
        {
            cancelReservation();
        }
        else if (choice == 6)
        {
            cout << "\nProgram Ended.\n";
        }
        else
        {
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}