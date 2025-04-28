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

        if (root->data == new_node->data)
            cout << "No duplicates allowed";

        node *current = root;
        node *parent = NULL;

        while (current != NULL)
        {
            parent = current;
            if (new_node->data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if (new_node->data < parent->data)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
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

int main()
{
    binary_search_tree bst;
    binary_search_tree bst2;

    int values[14] = {30, -10, 3, 3, 9, 68, 50, 7, 6, 72, 98, -7, 56, 31};
    int values2[20] = {15, 3, 8, -2, -5, 5, 21, 9, 1, 77, 111, 24, 33, 22, 123, 234, 999};

    for (int i = 0; i < 14; i++)
    {
        bst.insert_node(values[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        bst2.insert_node(values2[i]);
    }

    cout << "Inorder Traversal: ";
    inorder(bst.root);
    cout << endl;
    inorder(bst2.root);
    cout << endl;

    return 0;
}
