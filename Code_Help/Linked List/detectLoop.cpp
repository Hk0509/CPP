#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Destructor was called for " << value << endl;
    }
};

void insertNode(Node *&tail, int d, int element)
{
    // Empty list
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        temp->next = temp;
        tail = temp;
    }
    // List is non-empty
    // Assuming element is present in list
    else
    {
        Node *temp = new Node(d);
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

// Traversal
void print(Node *&tail)
{
    Node *temp = tail;
    // cout<<"Tail: "<<tail->data<<endl;

    // If list is empty
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    // Empty list
    if (tail == NULL)
    {
        cout << "List is already empty!!" << endl;
        return;
    }
    // List is not empty
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        // One node linked list
        if (curr == prev)
        {
            tail = NULL;
        }

        // Greater than 1 node linked list
        if (curr == tail)
        {
            tail = curr->next;
        }

        // Now curr is at node to del
        prev->next = curr->next;
        curr->next = NULL;

        delete (curr);
    }
}

bool detectLoop(Node* &head)
{
    if(head == NULL)
    return false;

    map<Node*, bool>visited;
    Node* temp = head;

    while(temp!=NULL)
    {
        //Cycle is present
        if(visited[temp] ==  true)
        return 1;

        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 3, 5);
    insertNode(tail, 5, 3);
    insertNode(tail, 2, 5);

    print(tail);
}
