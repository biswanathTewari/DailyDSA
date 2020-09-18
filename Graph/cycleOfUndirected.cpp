// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/


void check(int index,vector<int> adj[],int vis[],int p,bool &val){


    vis[index] = 1;

    vector<int> ::iterator i;

    for(i = adj[index].begin();i!=adj[index].end();i++)
      if(vis[*i] == 0){
        check(*i,adj,vis,index,val);
        if(val == true)
            return;
      }
      else if(*i != p){
          val = true;
          return;
      }
}


bool isCyclic(vector<int> adj[], int V)
{

   int vis[V];

   fill(vis,vis+V,0);

   bool val = false;

   for(int i=0;i<V;i++)
    if(vis[i] == 0)
        check(i,adj,vis,-1,val);

   return val;
}

// { Driver Code Starts.

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
  // } Driver Code Ends
