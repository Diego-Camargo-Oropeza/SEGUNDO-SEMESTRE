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
            visited[w] = true;

            for (int x : ady[w])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }

    void dfs(int origin)
    {
        stack<int> s;
        s.push(origin);
        vector<bool> visited(vertices, false);
        visited[origin] = true;
        cout << origin << " : ";
        while(!s.empty()){
            int w = s.top();
            s.pop();
            if(visited[w]){
                cout << w << ' ';
                visited[w] = true;
            }
            for(int x : ady[w]){
                if(!visited[x]){
                    visited[x] = true;
                    s.push(x);
                }
            }
        }
    }
};

int main(){
    graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);

    cout << "Breadth First Search: ";
    g.breadth(0);
    cout << endl;

    cout << "Depth First Search: ";
    g.dfs(0);
    cout << endl;

    return 0;
}