#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class graph
{
private:
    list<int> *ady;
    int vertices;

public:
    graph(int v)
    {
        vertices = v;
        ady = new list<int>[v];
        cout << "Building graph of " << v << " vertices" << endl;
    }

    ~graph()
    {
        delete[] ady;
        cout << "Destroying graph...." << endl;
    }

    void add_edge(int u, int v)
    {
        ady[u].push_back(v);
        ady[v].push_back(u);
    }

    void breadth(int origin)
    {
        queue<int> q;
        vector<bool> visited(vertices, false);

        q.push(origin);
        visited[origin] = true;

        cout << origin << " : ";

        while (!q.empty())
        {
            int w = q.front();
            q.pop();

            cout << w << ' ';

            for (int x : ady[w])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }

    void depth(int origin)
    {
        stack<int> s;
        vector<bool> visited(vertices, false);

        s.push(origin);

        cout << origin << " : ";

        while (!s.empty())
        {
            int w = s.top();
            s.pop();

            if (visited[w])
                return;

            cout << w << ' ';
            visited[w] = true;

            for (auto it = ady[w].rbegin(); it != ady[w].rend(); it++)
            {
                if (!visited[*it])
                    s.push(*it);
            }
        }
        cout << endl;
    }

    void print()
    {
        cout << "Listas de adyacencia " << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << "[" << i << "]: ";
            for (auto it = ady[i].begin(); it != ady[i].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    graph g2(5);

    g2.add_edge(0, 1);
    g2.add_edge(0, 4);
    g2.add_edge(1, 2);
    g2.add_edge(1, 3);
    g2.add_edge(1, 4);
    g2.add_edge(2, 3);
    g2.add_edge(3, 4);

    graph g3(10);
    g3.add_edge(0, 1);
    g3.add_edge(1, 2);
    g3.add_edge(1, 3);
    g3.add_edge(1, 5);
    g3.add_edge(2, 3);
    g3.add_edge(2, 8);
    g3.add_edge(3, 5);
    g3.add_edge(3, 9);
    g3.add_edge(4, 5);
    g3.add_edge(4, 3);
    g3.add_edge(5, 2);
    g3.add_edge(6, 1);
    g3.add_edge(7, 5);
    g3.add_edge(8, 9);
    g3.add_edge(9, 3);

    cout << "Breadth First Search (g)" << endl;
    for (int i = 0; i < 5; i++)
    {
        g.breadth(i);
    }
    cout <<  endl;
    cout << "Breadth First Search (g3)" << endl;
    for (int i = 0; i < 10; i++)
    {
        g3.breadth(i);
    }
    cout <<  endl;
    cout << "Depth First Search (g2)" << endl;
    for (int i = 0; i < 5; i++)
    {
        g2.depth(i);
        cout << endl;
    }
    cout <<  endl;
    cout << "Depth First Search (g3)" << endl;
    for (int i = 0; i < 10; i++)
    {
        g3.depth(i);
        cout << endl;
    }

    return 0;
}