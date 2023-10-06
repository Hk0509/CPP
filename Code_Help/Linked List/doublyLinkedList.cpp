#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Destructor was called for value: " << value << endl;
    }
};

// Traversing a linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Length of Linked List
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert at head
void insertAtHead(Node *&tail, Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }

    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(int position, Node *&tail, Node *&head, int d)
{
    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    // Creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteAtPosition(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete (temp);
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    int cnt = 1;

    while (cnt < position)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr->next == NULL)
    {
        tail = prev;
    }

    // Working
    //  curr->prev->next = curr->next;
    //  curr->next->prev = curr->prev;
    //  curr->next = NULL;
    //  curr->prev = NULL;

    // curr->next->prev = prev;
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    
    delete (curr);
}

int main()
{
    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;

    // print(head);
    // cout << getLength(head) << endl;

    insertAtHead(tail, head, 15);
    print(head);
    insertAtHead(tail, head, 13);
    print(head);
    insertAtHead(tail, head, 8);
    print(head);
    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(1, tail, head, 101);
    print(head);

    insertAtPosition(6, tail, head, 105);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteAtPosition(6, head, tail);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}