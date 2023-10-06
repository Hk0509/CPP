#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertToBST(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return;
    }

    if (d < root->data)
        insertToBST(root->left, d);
    else
        insertToBST(root->right, d);
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertToBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int minVal(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}

int maxVal(Node *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root->data;
}

Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root->right != NULL)
        {
            int maxi = maxVal(root->left);
            root->data = maxi;
            root->left = deleteNode(root->left, maxi);
            return root;
        }
    }

    else if (root->data > val)
    {
        root -> left = deleteNode(root->left, val);
        return root;
    }
    else
    {
        root -> right = deleteNode(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    // 50 20 70 10 30 90 110 -1
    cout << "Enter data to create BST: " << endl;
    takeInput(root);
    cout << "LevelOrder => " << endl;
    levelOrderTraversal(root);
    // cout << "InOrder => " << endl;
    // inOrder(root);

    // cout << "Min Value -> " << minVal(root) << endl;
    // cout << "Max Value -> " << maxVal(root) << endl;

    cout << "Deleted Node => " << deleteNode(root, 30) << endl;
    cout << "LevelOrder => " << endl;
    levelOrderTraversal(root);
    return 0;
}