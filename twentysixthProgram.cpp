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

class binary_search_tree
{

public:
    node *root;

    binary_search_tree()
    {
        root = NULL;
    }

    void insert(node *new_node)
    {

        if (root == NULL)
        {
            root = new_node;
            return;
        }
        node *current = root;
        node *parent = NULL;

        while (current != NULL)
        {
            parent = current;
            if (new_node->data < current->data)
            {
                current = current->left;
            }
            else if (new_node->data > current->data)
            {
                current = current->right;
            }
            else if (new_node->data == current->data)
            {
                return;
            }
        }

        if (new_node->data < parent->data)
        {
            parent->left = new_node;
        }
        else if (new_node->data > parent->data)
        {
            parent->right = new_node;
        }
        else if (new_node->data == parent->data)
        {
            return;
        }
    }

    node *search(int n)
    {
        return search(root, n);
    }

    node *search(node *root, int n)
    {
        if (root == NULL)
            return NULL;
        if (n == root->data)
            return root;
        if (n < root->data)
            return search(root->left, n);
        else
            return search(root->right, n);
    }

    void insert_node(int n)
    {
        node *new_node = new node(n);
        insert(new_node);
    }
};

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << " " << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void posorder(node *root)
{
    if (root == NULL)
        return;

    posorder(root->left);
    posorder(root->right);
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

int main()
{
    binary_search_tree bst;
    binary_search_tree bst2;

    int values[14] = {30, -10, 3, 3, 9, 68, 50, 7, 6, 72, 98, -7, 56, 31};
    int values2[20] = {15, 3, 8, -2, 80, 34, 500, -5, 5, 21, 9, 1, 77, 111, 24, 33, 22, 123, 234, 999};

    for (int i = 0; i < 14; i++)
    {
        bst.insert_node(values[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        bst2.insert_node(values2[i]);
    }

    cout << "Inorder traversal: ";
    inorder(bst.root);
    cout << endl;
    cout << "Preorder traversal: ";
    preorder(bst.root);
    cout << endl;
    cout << "Posorder traversal: ";
    posorder(bst.root);
    cout << endl;
    cout << "Level Order traversal: ";
    levelOrder(bst.root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inorder(bst2.root);
    cout << endl;

    cout << bst.search(30);

    return 0;
}
