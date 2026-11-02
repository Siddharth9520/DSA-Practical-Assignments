#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name[50], mobile[50];
    int n;

    cout << "Enter number of friends: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin >> name[i];

        cout << "Enter mobile number: ";
        cin >> mobile[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(name[i] > name[j])
            {
                swap(name[i], name[j]);
                swap(mobile[i], mobile[j]);
            }
        }
    }

    cout << "\nPhone Book:\n";

    for(int i = 0; i < n; i++)
    {
        cout << name[i] << " - " << mobile[i] << endl;
    }
    string searchName;

    cout << "\nEnter friend name to search: ";
    cin >> searchName;
    name[n] = searchName;

    int i = 0;

    while(name[i] != searchName)
    {
        i++;
    }
    if(i < n)
    {
        cout << "\nFriend found!\n";
        cout << "Name: " << name[i] << endl;
        cout << "Mobile: " << mobile[i] << endl;
    }
    else
    {
        cout << "\nFriend not found.\n";

        char choice;
        cout << "Do you want to insert friend? (y/n): ";
        cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            string newMobile;

            cout << "Enter mobile number: ";
            cin >> newMobile;
            i = n;

            while(i > 0 && name[i - 1] > searchName)
            {
                name[i] = name[i - 1];
                mobile[i] = mobile[i - 1];
                i--;
            }

            name[i] = searchName;
            mobile[i] = newMobile;

            n++;

            cout << "Friend inserted successfully.\n";
        }
    }
    cout << "\nFinal Phone Book:\n";

    for(int i = 0; i < n; i++)
    {
        cout << name[i] << " - " << mobile[i] << endl;
    }

    return 0;
}