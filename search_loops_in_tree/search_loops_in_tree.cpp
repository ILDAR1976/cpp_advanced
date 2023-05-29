#include <iostream>
#include <unordered_set>
using namespace std;

void push(Node*&, int);
bool detectCycle(Node*);


int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        push(head, keys[i]);
    }

    // insert cycle
    head->next->next->next->next->next = head->next->next;

    if (detectCycle(head)) {
        cout << "Cycle Found";
    }
    else {
        cout << "No Cycle Found";
    }

    return 0;
}

// Linked list node
struct Node
{
    int data;
    Node* next;
};

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

// Function for loop detection in a linked list using hashing
bool detectCycle(Node* head)
{
    Node* curr = head;
    unordered_set<Node*> set;

    // list bypass
    while (curr)
    {
        // returns false if we have already seen this node before
        if (set.find(curr) != set.end()) {
            return true;
        }

        // insert the current node into the set
        set.insert(curr);

        // move to the next node
        curr = curr->next;
    }

    // we reach this point if the list does not contain any cycles
    return false;
}