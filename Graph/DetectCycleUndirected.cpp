#include<bits/stdc++.h>
using namespace std;

void DFS(int index,vector<int> adj[],int vis[],int V,int p,bool &val){//p -> parent of the index

  vis[index] = true;

  for(auto i=adj[index].begin();i!=adj[index].end();i++){

    if(vis[*i] == 0){
      DFS(*i,adj,vis,V,index,val);

      if(val)
        return;
    }
    else if(vis[*i] == 1 && p != *i){// if(u,v) -> both are visited && v is not the parent of u(index)
      val = true;
      return;
    }

  }

  return;

}


int isCyclic(vector<int> adj[],int V){

  int vis[V];
  fill(vis,vis+V,0);

  bool val = false;

  for(int i=0;i<V;i++)//this loop is to ensure that in the case of seperate isolated edges , we cover them all.
    if(vis[i] == 0)
      DFS(i,adj,vis,V,-1,val);

  return (val)? 1 : 0;

}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
