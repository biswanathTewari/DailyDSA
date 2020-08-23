#include<bits/stdc++.h>
using namespace std;


class Graph{
  int V;

  list<int> *l;

  void DFSUtil(int v,int visited[]){
    visited[v] = 1;
    cout<<v<<" ";

    list<int> ::iterator i;

    for(i = l[v].begin();i!=l[v].end();i++)
      if(visited[*i] == 0)
        DFSUtil(*i,visited);
  }

public:
  Graph(int v){
    this->V = v;
    l = new list<int>[V];
  }

  void addEdge(int u, int w){
    l[u].push_back(w);
  }

  void DFS(int v){
    int visited[V];

    fill(visited,visited+V,0);

    DFSUtil(v,visited);
  }
};


int main(){
  Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
  return 0;
}
