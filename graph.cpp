#include <iostream>
#include <vector>
#include <unordered_map>
#include<list>
#include <queue>
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

void bfsTraversalFast(int node,unordered_map<int,list<int>>&adjlist,queue<int> &q,unordered_map<int,bool> &vis,vector<int> &ans){
    
        q.push(node);
        vis[node]=true;

        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:adjlist[front]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
}
   
// Traversal
    void bfsTraversal(Graph* g,int node){
        queue<int> q;
        vector<int> ans;
        unordered_map<int,bool> vis;

        bfsTraversalFast(node,g->adjList,q,vis,ans);
        for(int i=0;i<g->vertices;i++){
            if(!vis[i]){
                bfsTraversalFast(i,g->adjList,q,vis,ans);
            }
        }

        for(auto i:ans){
            cout<< i <<" ";
        }
    }

    void dfsTraversalFast(int node,unordered_map<int,list<int>>&adjList,unordered_map<int,bool> &vis,vector<int> &ans){
        ans.push_back(node);
        vis[node]=true;
        for(auto i:adjList[node]){
            if(!vis[i]){
                dfsTraversalFast(i,adjList,vis,ans);
            }
        }
    }

    void dfsTraversal(Graph* g,int node){
        unordered_map<int,bool> vis;
        vector<int> ans;
        dfsTraversalFast(node,g->adjList,vis,ans);
        for(int i=0;i<g->vertices;i++){
            if(!vis[i]){
                dfsTraversalFast(i,g->adjList,vis,ans);
            }
        }

        for(auto i: ans){
            cout<<i<<" ";
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
    cout<<endl<< "BFS Traversal :"<<endl;
    bfsTraversal(g1,1);
    cout<<endl<< "DFS Traversal :"<<endl;
    dfsTraversal(g1,0);
    return 0;
}
