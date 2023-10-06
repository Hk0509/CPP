#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        // Memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // Insert at starting node
    if (position == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }

    // Creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // Memory free start node
        temp->next = NULL;
        delete temp;
    }

    // Deleting any middle node
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
            // cout<<prev->data<<" "<<curr -> data<<" "<<cnt<<endl;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

bool detectLoop(Node *&head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        // Cycle is present
        if (visited[temp] == true)
        {
            cout << "Loop at element : " << temp->data << endl;
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
}

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            cout << "Loop is present at element : " << slow->data << endl;
            return slow;
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{
    Node *fast = floydDetectLoop(head);
    Node *slow = head;

    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void removeLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *start = getStartingNode(head);
    Node *temp = start;

    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    // Created a node
    Node *node1 = new Node(10);
    // cout<< node1 -> data <<endl;
    // cout<< node1 -> next <<endl;

    // Head pointed to node1
    Node *head = node1;
    Node *tail = node1;

    // print(head);
    insertAtTail(tail, 12);
    // print(head);

    insertAtTail(tail, 15);
    // print(head);

    insertAtPosition(tail, head, 1, 30);
    print(head);

    tail->next = head->next;

    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    // deleteNode(4, head, tail);
    // print(head);

    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;

    if (floydDetectLoop(head) != NULL)
        cout << "Loop Detected" << endl;
    else
        cout << "No loop detected" << endl;

    cout << getStartingNode(head)->data << endl;

    removeLoop(head);
    if (floydDetectLoop(head) != NULL)
        cout << "Loop Detected" << endl;
    else
        cout << "No loop detected" << endl;
}