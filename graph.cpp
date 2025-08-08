#include <iostream>
#include <vector>
using namespace std;

class Graph{
public:
    int vertices;
    int edges;
    bool directed;
    vector<vector<int>> adjMat;

public:

     Graph(int v,int e,bool dir){
        this->vertices=v;
        this->edges=e;
        this->directed=dir;
    }

    void initAdjMat(){
        this->adjMat=vector<vector<int>> (vertices,vector<int>(vertices,0));
    }

    void addEdge(int u,int v){
        adjMat[u][v]=1;
        if(!directed){
            adjMat[v][u]=1;
        }
    }

    void print(){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<< adjMat[i][j]<<" "; 
            }
            cout<<endl;
        }
    }

    
};

void initGraph(Graph* g){
    int u;
    int v;
    for(int i=0;i<g->edges;i++){
        cout<<"Enter the source and destination"<<endl;
        cin>> u >> v ;
        g->addEdge(u,v);
    }
}

int main(){
    int v;
    int e;
    int d;
    cout<<"Enter the no of vertices and edges and directedBoolean"<<endl;
    cin>>v>>e>>d;
    Graph* g1=new Graph(v,e,d);
    g1->initAdjMat();
    initGraph(g1);
    g1->print();
    return 0;
}