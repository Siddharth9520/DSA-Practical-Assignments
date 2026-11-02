#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int songID;
    string songName;
    string artist;
    string duration;

    Node* next;
};

Node* head = NULL;
Node* current = NULL;
void addSong()
{
    Node* newNode = new Node();

    cout << "\nEnter Song ID: ";
    cin >> newNode->songID;

    cout << "Enter Song Name: ";
    cin >> newNode->songName;

    cout << "Enter Artist Name: ";
    cin >> newNode->artist;

    cout << "Enter Duration: ";
    cin >> newNode->duration;

    if (head == NULL)
    {
        head = newNode;

        newNode->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    cout << "\nSong Added Successfully!\n";
}
void displayPlaylist()
{
    if (head == NULL)
    {
        cout << "\nPlaylist Empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== MUSIC PLAYLIST ==========\n";

    do
    {
        cout << "Song ID   : " << temp->songID << endl;
        cout << "Song Name : " << temp->songName << endl;
        cout << "Artist    : " << temp->artist << endl;
        cout << "Duration  : " << temp->duration << endl;
        cout << "------------------------------------\n";

        temp = temp->next;

    } while (temp != head);
}

void playNext()
{
    if (head == NULL)
    {
        cout << "\nPlaylist Empty.\n";
        return;
    }

    if (current == NULL)
    {
        current = head;
    }
    else
    {
        current = current->next;
    }

    cout << "\n========== NOW PLAYING ==========\n";
    cout << "Song ID   : " << current->songID << endl;
    cout << "Song Name : " << current->songName << endl;
    cout << "Artist    : " << current->artist << endl;
    cout << "Duration  : " << current->duration << endl;
}

void searchSong()
{
    if (head == NULL)
    {
        cout << "\nPlaylist Empty.\n";
        return;
    }

    int searchID;

    cout << "\nEnter Song ID to Search: ";
    cin >> searchID;

    Node* temp = head;

    do
    {
        if (temp->songID == searchID)
        {
            cout << "\nSong Found!\n";
            cout << "Song ID   : " << temp->songID << endl;
            cout << "Song Name : " << temp->songName << endl;
            cout << "Artist    : " << temp->artist << endl;
            cout << "Duration  : " << temp->duration << endl;

            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "\nSong Not Found.\n";
}

void deleteSong()
{
    if (head == NULL)
    {
        cout << "\nPlaylist Empty.\n";
        return;
    }

    int searchID;

    cout << "\nEnter Song ID to Delete: ";
    cin >> searchID;

    if (head->songID == searchID)
    {
        if (head->next == head)
        {
            delete head;

            head = NULL;
            current = NULL;
        }
        else
        {
            Node* temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            Node* deleteNode = head;

            head = head->next;

            temp->next = head;

            delete deleteNode;
            current = NULL;
        }

        cout << "\nSong Deleted Successfully!\n";
        return;
    }
    Node* temp = head;

    while (temp->next != head)
    {
        if (temp->next->songID == searchID)
        {
            Node* deleteNode = temp->next;

            temp->next = deleteNode->next;

            if (current == deleteNode)
            {
                current = NULL;
            }

            delete deleteNode;

            cout << "\nSong Deleted Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nSong Not Found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n      MUSIC PLAYLIST MANAGEMENT";
        cout << "\n====================================";
        cout << "\n1. Add Song";
        cout << "\n2. Display Playlist";
        cout << "\n3. Play Next Song";
        cout << "\n4. Search Song";
        cout << "\n5. Delete Song";
        cout << "\n6. Exit";
        cout << "\n====================================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addSong();
        }
        else if (choice == 2)
        {
            displayPlaylist();
        }
        else if (choice == 3)
        {
            playNext();
        }
        else if (choice == 4)
        {
            searchSong();
        }
        else if (choice == 5)
        {
            deleteSong();
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