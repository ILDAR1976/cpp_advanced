﻿#include <iostream>
#include <unordered_set>
using namespace std;

// Linked list node
struct Node
{
    int data;
    Node* next;
};

void push(Node*&, int);
bool detectCycle(Node*);
int detectCycle2(Node*);


int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        push(head, keys[i]);
    }

    // insert cycle
    head->next->next->next->next->next->next = head->next->next;

    if (detectCycle(head)) {
        cout << "scycle start point: "<< detectCycle2(head) << endl;
        cout << "Cycle Found";
    }
    else {
        cout << "No Cycle Found";
    }
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

// Function for loop detection in a linked list using hashing
bool detectCycle(Node* head)
{
    Node* curr = head;
    unordered_set<Node*> set;

    // list bypass
    while (curr)
    {
        cout << curr->data << " ";
        // returns false if we have already seen this node before
        if (set.find(curr) != set.end()) {
            cout << endl;
            return true;
        }

        // insert the current node into the set
        set.insert(curr);

        // move to the next node
        curr = curr->next;
    }

    cout << endl;
    // we reach this point if the list does not contain any cycles
    return false;
}

int detectCycle2(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            break;
        }
    }


    // cycle check
    if (fast == NULL || fast->next == NULL)
    {
        return -1;
    }

    // Place the slow pointer at the beginning of the list
    // Leave the quick pointer at the meeting point
    // run both pointers at the same speed
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // if there is a loop, the pointers will meet at the loop start point
    return slow->data;
}
