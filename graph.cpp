#include <iostream>
#include <vector>
#include <unordered_map>
#include<list>
using namespace std;

class Graph{
public:
    int vertices;
    int edges;
    bool directed;
    vector<vector<int>> adjMat;
    unordered_map<int,list<int>> adjList;


public:

     Graph(int v,int e,bool dir){
        this->vertices=v;
        this->edges=e;
        this->directed=dir;
        this->adjMat=vector<vector<int>> (vertices,vector<int>(vertices,0));
    }

    void addEdge(int u,int v){
        adjMat[u][v]=1;
        adjList[u].push_back(v);
        if(!directed){
            adjMat[v][u]=1;
            adjList[v].push_back(u);
        }
    }

    void print(){

        cout<< "Adjacency Matrix"<<endl;
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<< adjMat[i][j]<<" "; 
            }
            cout<<endl;
        }
        
        cout<<endl<<"Adjacency List"<< endl;
        for(int i=0;i<vertices;i++){
            cout<<i<<"->";
            for(auto j:adjList[i]){
                cout<<j<<" ";
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
    initGraph(g1);
    g1->print();
    return 0;
}