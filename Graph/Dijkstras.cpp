// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;

        vector<vector<int>> g(V);

        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }

        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }

        int s;
        cin>>s;

        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends
/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

int findMin(int vis[],int dis[],int V){

    int min = INT_MAX;
    int index= 0;

    for(int i = 0;i < V;i++){
        if(vis[i] == 0){
            if(min > dis[i]){
                min = dis[i];
                index = i;
            }
        }
    }

    return index;
}



void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here
    int dis[V];
    fill(dis,dis+V,INT_MAX); //making the distance from src infinity

    dis[src] = 0; //from src to src = 0 

    int vis[V];
    fill(vis,vis+V,0);
    int countVis = -1;//counts the no.of vertex visited , starting from 0

    while(countVis < V){ //if countVis = V , then we have found the min distance for every vertex for src

        int u = findMin(vis,dis,V); //finds the nonVisited min weighted(closest) vertex to src

        vis[u] = 1;
        countVis++;

        for(int v = 0;v < V ;v++){ //now v iterate all the vertex adjacent to u,if graph[u][v] == 0,then v !adj to u

            if(v == u || graph[u][v] == 0)
                continue;

            if(dis[v] > dis[u]+graph[u][v])
                dis[v] = dis[u]+graph[u][v];
        }

    }

    for(int i=0;i<V;i++)
        cout<<dis[i]<<" ";
}

Time : O(N + N(N+N)) = O(N^2)
