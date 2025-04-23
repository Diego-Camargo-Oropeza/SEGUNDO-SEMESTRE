#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class grafo{
private:
    list <int> *ady;
    int vertices;
public:
    grafo(int);
    ~grafo();
    void aniadir_arista(int,int);
    void amplitud(int);
    void imprimir();
};

grafo::grafo(int v){
    vertices=v;
    ady=new list <int> [v];
    cout<<"Construyendo grafo de "<<v<<" vertices"<<endl;
}

grafo::~grafo()
{
    delete[]ady;
    cout<<"Destruyendo grafo...."<<endl;

}

void grafo::aniadir_arista(int u, int v){
    ady[u].push_back(v);
    ady[v].push_back(u);


}


void grafo::amplitud(int origen){
    queue<int>q;
    vector<bool>visitado(vertices,false);
    q.push(origen);
    visitado[origen]=true;
    while(!q.empty()){
        int w=q.front();
        q.pop();
        for(int x:ady[w]){
            if(!visitado[x])
            {
                visitado[x]=true;
                q.push(x);
            }
        }
    }
}

void grafo::imprimir(){
    list<int>::iterator it;
    cout<<"Listas de adyacencia "<<endl;
    for(int i=0; i<vertices; i++){
        cout<<"["<<i<<"]: ";
        for(it= ady[i].begin();it!=ady[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    grafo g(5);
    g.aniadir_arista(0,1);
    g.aniadir_arista(0,4);
    g.aniadir_arista(1,2);
    g.aniadir_arista(1,3);
    g.aniadir_arista(1,4);
    g.aniadir_arista(2,3);
    g.aniadir_arista(3,4);


    cout<<"Recorridos en amplitud"<<endl;
    for(int i=0;i<5;i++){
        g.amplitud(i);
        cout<<endl;
    }
    return 0;
}