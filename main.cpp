#include <iostream>
using namespace std;

// ================= LINKED LIST =================
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning - O(1)
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;

        cout << value << " inserted into Linked List.\n";
    }

    // Search - O(n)
    void search(int value) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << value << " found in Linked List.\n";
                return;
            }
            temp = temp->next;
        }

        cout << value << " not found.\n";
    }

    // Delete - O(n)
    void deleteNode(int value) {
        Node *temp = head, *prev = NULL;

        if (temp != NULL && temp->data == value) {
            head = temp->next;
            delete temp;
            cout << value << " deleted.\n";
            return;
        }

        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << value << " not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << value << " deleted.\n";
    }

    void display() {
        Node* temp = head;

        cout << "Linked List: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

// ================= BINARY SEARCH TREE =================
class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    bool search(Node* node, int value) {
        if (node == NULL)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return search(node->left, value);

        return search(node->right, value);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == NULL)
            return node;

        if (value < node->data)
            node->left = deleteNode(node->left, value);

        else if (value > node->data)
            node->right = deleteNode(node->right, value);

        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    // Insert - O(log n)
    void insert(int value) {
        root = insert(root, value);
        cout << value << " inserted into BST.\n";
    }

    // Search - O(log n)
    void search(int value) {
        if (search(root, value))
            cout << value << " found in BST.\n";
        else
            cout << value << " not found.\n";
    }

    // Delete - O(log n)
    void deleteValue(int value) {
        root = deleteNode(root, value);
        cout << value << " deleted from BST.\n";
    }

    void display() {
        cout << "BST (Inorder): ";
        inorder(root);
        cout << endl;
    }
};

// ================= MAIN MENU =================
int main() {
    LinkedList list;
    BST tree;

    int choice, dsChoice, value;

    while (true) {
        cout << "\n===== DATA STRUCTURE MENU =====\n";
        cout << "1. Linked List\n";
        cout << "2. Binary Search Tree\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> dsChoice;

        if (dsChoice == 3)
            break;

        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n";
        cout << "Enter operation: ";
        cin >> choice;

        switch (dsChoice) {
            case 1:
                if (choice == 1) {
                    cout << "Enter value: ";
                    cin >> value;
                    list.insert(value);
                }
                else if (choice == 2) {
                    cout << "Enter value: ";
                    cin >> value;
                    list.deleteNode(value);
                }
                else if (choice == 3) {
                    cout << "Enter value: ";
                    cin >> value;
                    list.search(value);
                }
                else if (choice == 4) {
                    list.display();
                }
                break;

            case 2:
                if (choice == 1) {
                    cout << "Enter value: ";
                    cin >> value;
                    tree.insert(value);
                }
                else if (choice == 2) {
                    cout << "Enter value: ";
                    cin >> value;
                    tree.deleteValue(value);
                }
                else if (choice == 3) {
                    cout << "Enter value: ";
                    cin >> value;
                    tree.search(value);
                }
                else if (choice == 4) {
                    tree.display();
                }
                break;
        }
    }

    cout << "Program Ended.\n";

    return 0;
}
