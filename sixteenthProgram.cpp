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

    void delete_last()
    {
        if (header != NULL)
        {

            if (header->link == NULL)
            {
                delete_first();
            }
            else
            {
                node *aux = header;
                node *aux2 = new node;
                while (aux->link != NULL)
                    aux = aux->link;
                aux2->link = NULL;
                cout << "Deleting: " << aux->data << endl;
                delete aux2;
            }
        }
        else
        {
            cout << "Empty list\n";
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

    l.delete_last();
    l.delete_last();

    l.print();
    return 0;
}