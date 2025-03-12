#include <iostream>
using namespace std;
/*
static: arrays
dynamic: pointers
*/

class node
{
public:
    int data;
    node *link;
};

class linked_list
{
private:
    node *header;

public:
    linked_list()
    {
        header = NULL;
    }

    void print()
    {
        if (header != NULL)
        {
            node *aux = header;
            do
            {
                cout << aux->data << " ";
                aux = aux->link;
            } while (aux != NULL);
        }
        else
        {
            cout << "Empty list\n";
        }
    }

    void push()
    {
        node *n = new node;
        cout << "Enter data: ";
        cin >> n->data;
        n->link = header;
        header = n;
    }

    void push_back()
    {
        node *n = new node;
        cout << "Enter new data: ";
        cin >> n->data;
        n->link = NULL;
        if (header == NULL)
        {
            header = n;
        }
        else
        {
            node *aux = header;
            while (aux->link != NULL)
                aux = aux->link;
            aux->link = n;
        }
    }

    void delete_first()
    {
        if (header != NULL)
        {
            node *aux = header;
            header = header->link;
            cout << "Deleting: " << aux->data << endl;
            delete aux;
        }
        else
        {
            cout << "Empty List\n";
        }
    }
};
// Linked lists
int main()
{

    linked_list l;

    l.delete_first();

    l.push();
    l.push();
    l.push();

    l.print();

    l.push_back();

    l.print();

    l.delete_first();

    l.print();
    return 0;
}