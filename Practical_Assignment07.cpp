#include <iostream>
#include <string>
using namespace std;

struct Node {
    int roll;
    string name, course;
    Node *left, *right;
};

Node* createNode(int roll, string name, string course) {
    Node* temp = new Node;
    temp->roll = roll;
    temp->name = name;
    temp->course = course;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int roll, string name, string course) {
    if (root == NULL)
        return createNode(roll, name, course);

    if (roll < root->roll)
        root->left = insert(root->left, roll, name, course);
    else if (roll > root->roll)
        root->right = insert(root->right, roll, name, course);
    else
        cout << "Roll number already exists.\n";

    return root;
}

void displayStudent(Node* root) {
    if (root == NULL)
        return;

    cout << "Roll Number: " << root->roll << endl;
    cout << "Name: " << root->name << endl;
    cout << "Course: " << root->course << endl;
}

Node* search(Node* root, int roll) {
    if (root == NULL || root->roll == roll)
        return root;

    if (roll < root->roll)
        return search(root->left, roll);

    return search(root->right, roll);
}

Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

Node* predecessor(Node* root, int roll) {
    Node* current = search(root, roll);

    if (current == NULL)
        return NULL;

    if (current->left != NULL)
        return findMax(current->left);

    Node* pred = NULL;

    while (root != NULL) {
        if (roll > root->roll) {
            pred = root;
            root = root->right;
        } else if (roll < root->roll) {
            root = root->left;
        } else {
            break;
        }
    }

    return pred;
}

Node* successor(Node* root, int roll) {
    Node* current = search(root, roll);

    if (current == NULL)
        return NULL;

    if (current->right != NULL)
        return findMin(current->right);

    Node* succ = NULL;

    while (root != NULL) {
        if (roll < root->roll) {
            succ = root;
            root = root->left;
        } else if (roll > root->roll) {
            root = root->right;
        } else {
            break;
        }
    }

    return succ;
}

Node* deleteNode(Node* root, int roll) {
    if (root == NULL)
        return NULL;

    if (roll < root->roll)
        root->left = deleteNode(root->left, roll);
    else if (roll > root->roll)
        root->right = deleteNode(root->right, roll);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);

        root->roll = temp->roll;
        root->name = temp->name;
        root->course = temp->course;

        root->right = deleteNode(root->right, temp->roll);
    }

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        displayStudent(root);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        displayStudent(root);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        displayStudent(root);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = NULL;
    int choice, roll;
    string name, course;
    Node* temp;

    do {
        cout << "\n--- STUDENT RECORD BST ---\n";
        cout << "1. Insert Record\n";
        cout << "2. Find Minimum Roll Number\n";
        cout << "3. Find Maximum Roll Number\n";
        cout << "4. Search Student\n";
        cout << "5. Find Predecessor\n";
        cout << "6. Find Successor\n";
        cout << "7. Delete Record\n";
        cout << "8. Display BST Traversals\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter roll number: ";
                cin >> roll;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter course: ";
                cin >> course;
                root = insert(root, roll, name, course);
                break;

            case 2:
                temp = findMin(root);
                if (temp != NULL)
                    displayStudent(temp);
                else
                    cout << "BST is empty.\n";
                break;

            case 3:
                temp = findMax(root);
                if (temp != NULL)
                    displayStudent(temp);
                else
                    cout << "BST is empty.\n";
                break;

            case 4:
                cout << "Enter roll number to search: ";
                cin >> roll;
                temp = search(root, roll);
                if (temp != NULL)
                    displayStudent(temp);
                else
                    cout << "Student not found.\n";
                break;

            case 5:
                cout << "Enter roll number: ";
                cin >> roll;
                temp = predecessor(root, roll);
                if (temp != NULL)
                    displayStudent(temp);
                else
                    cout << "No predecessor found.\n";
                break;

            case 6:
                cout << "Enter roll number: ";
                cin >> roll;
                temp = successor(root, roll);
                if (temp != NULL)
                    displayStudent(temp);
                else
                    cout << "No successor found.\n";
                break;

            case 7:
                cout << "Enter roll number to delete: ";
                cin >> roll;
                if (search(root, roll) == NULL)
                    cout << "Student not found.\n";
                else {
                    root = deleteNode(root, roll);
                    cout << "Record deleted successfully.\n";
                }
                break;

            case 8:
                cout << "\n--- INORDER ---\n";
                inorder(root);
                cout << "\n--- PREORDER ---\n";
                preorder(root);
                cout << "\n--- POSTORDER ---\n";
                postorder(root);
                break;

            case 9:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 9);

    freeTree(root);
    return 0;
}
