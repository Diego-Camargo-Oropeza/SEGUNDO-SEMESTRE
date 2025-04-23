#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void posorder(node *root)
{
    if (root == NULL)
        return;

    posorder(root->left);
    posorder(root-s>right);
    cout << root->data << " ";
}

void levelOrder(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }

        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}

void levelOrder(node* n) {
    if (n == NULL) return;

    queue<node*> q;
    q.push(n);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}


int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    cout << "Posorder traversal: ";
    posorder(root);
    cout << endl;
    cout << "Level Order traversal: ";
    levelOrder(root);
    cout << endl;
}