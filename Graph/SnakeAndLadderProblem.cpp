#include<bits/stdc++.h>
using namespace std;

int BFS(vector<int> adj[31]){

  int vis[31];
  int dis[31];

  fill(vis,vis+31,0);
  fill(dis,dis+31,0);

  queue<int> q;

  q.push(1);
  vis[1] = 1;
  dis[1] = 0;

  while(!q.empty()){
    int x = q.front();
    q.pop();

    for(int i=0;i<adj[x].size();i++){

      if(vis[adj[x][i]] == 0){
        vis[adj[x][i]] = 1;
        dis[adj[x][i]] = dis[x] + 1;
        q.push(adj[x][i]);

        if(adj[x][i] == 30)
          return dis[x]+1;
      }

    }

  }


  return dis[30];

}


int main(){
  int t;
  cin>>t;
  while(t--){

    vector<int> adj[31];


    int board[40] = {0};
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        board[a]=b-a;
    }

	   for(int u=1;u<=30;u++){
		   for(int dice=1;dice<=6;dice++){
			     int v = u + dice + board[u+dice];
			     adj[u].push_back(v);
		   }
	   }

    cout<<BFS(adj)<<endl;

  }
  return 0;
}
