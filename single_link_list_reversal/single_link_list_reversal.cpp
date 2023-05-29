#include <iostream>
#include <unordered_set>
using namespace std;

// Linked list node
struct Node
{
    int data;
    Node* next;
};

void push(Node*&, int);
void reverse_list(Node*&);
void print(Node*&);

int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        push(head, keys[i]);
    }

    print(head);
    reverse_list(head);
    print(head);

    return 0;
}



// Auxiliary function to create a new node with the specified data and
// places it at the top of the list
void push(Node*& headRef, int data)
{
    // Create a new node of the linked list from the heap
    Node* newNode = new Node;

    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}

void reverse_list(Node*& head)
{
    Node* new_head = 0;
    // Read the items in the old list
    for (Node* pos = head; pos;)
    {
        // Shove it to the beginning of a new list
        Node* save_next = pos->next;
        pos->next = new_head;
        new_head = pos;
        pos = save_next;
    }
    
    head = new_head;
}

void print(Node*& head)
{
    Node* print = head;
    while (print != NULL)
    {
        cout << print->data << " ";
        print = print->next;
    }
    cout << endl;
}