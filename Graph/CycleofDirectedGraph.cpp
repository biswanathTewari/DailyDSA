// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/


bool check(int index,vector<int> adj[],int vis[]){ //using three domains , unused,ongoin and used.. if one ongoin
//finds another ongoinn then its a loop ... ongoin might face used, since two nodes can get connected to one node.

    vis[index] = 1;

    vector<int> :: iterator i;

    for(i = adj[index].begin(); i != adj[index].end(); i++){

        if(vis[*i] == 0){
            if(check(*i,adj,vis))
                return true;
        }
        else if(vis[*i] == 1)
            return true;
    }

    vis[index] = 2;

    return false;
}



bool isCyclic(int V, vector<int> adj[])
{
    int vis[V];
    fill(vis,vis+V,0);


    for(int i=0;i<V;i++){
        if(vis[i] == 0){
            if(check(i,adj,vis))
                return true;
        }
    }

    return false;
}

// { Driver Code Starts.

int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}  // } Driver Code Ends
