#include <iostream>
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

void preorder(node *n)
{
    if (n == NULL)
        return;
    cout << n->data << " ";
    preorder(n->left);
    preorder(n->right);
}

void inorder(node *n)
{
    if (n == NULL)
        return;

    inorder(n->left);
    cout << n->data << " ";
    inorder(n->right);
}

void posorder(node *n)
{
    if (n == NULL)
        return;

    inorder(n->left);
    inorder(n->right);
    cout << n->data << " ";
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
}