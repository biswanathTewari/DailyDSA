//Wednesday, June 10, 2020 7:44 PM
//variation of dijkstras + BFS

#include<bits/stdc++.h>
using namespace std;

//global variables
int n,m;
int x,y;
int a[21][21];
int des[21][21];
int vis[21][21];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isSafe(int nx , int ny){
  if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && a[nx][ny] == 1)//if a valid vertex & not visited & passabel = 1;
    return true;
  return false;
}


void bfs(){

  //visited matrix and source to destination matrix
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      vis[i][j] = 0;
      des[i][j] = INT_MAX;
    }
  }

  queue<pair<int,int>> q;

  //pushing the source + des of source to source = 0
  if(isSafe(0,0))
  {
    q.push(make_pair(0,0));
    vis[0][0] = 1;
    des[0][0] = 0;
  }

  while(!q.empty()){

    pair<int,int> p = q.front(); //instead of the min , we get the front() of the queue
    q.pop();

    for(int i=0;i<4;i++){ //checking all the neighbours of the vertex
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if(isSafe(nx,ny) && des[nx][ny] > des[p.first][p.second] + 1){
        des[nx][ny] = des[p.first][p.second] + 1;
        q.push(make_pair(nx,ny));
        vis[nx][ny] = 1;
      }
    }

  }

}


int main(){

  int t;
  cin>>t;
  while(t--){

    cin>>n>>m;

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){

        cin>>a[i][j];

      }
    }

    cin>>x>>y;

    bfs();

    if(des[x][y] == INT_MAX)
      cout<<-1<<endl;
    else cout<<des[x][y]<<endl;

  }
  return 0;
}
