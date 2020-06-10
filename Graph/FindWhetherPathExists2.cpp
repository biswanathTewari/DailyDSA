//Wednesday, June 10, 2020 7:44 PM
//BFS

#include<bits/stdc++.h>
using namespace std;

//global variables
int n,m;
int x,y;
int sx,sy;
int a[21][21];
int des[21][21];
int vis[21][21];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isSafe(int nx , int ny){
  if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 && a[nx][ny] == 3)//if a valid vertex & not visited & passabel = 3;
    return true;
  return false;
}


int bfs(){

  //visited matrix
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      vis[i][j] = 0;
    }
  }

  queue<pair<int,int>> q;

  //pushing the source
    q.push(make_pair(sx,sy));
    vis[sx][sy] = 1;

  while(!q.empty()){

    pair<int,int> p = q.front();
    q.pop();

    for(int i=0;i<4;i++){ //checking all the neighbours of the vertex
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if(nx == x && ny == y)//if the destination
        return 1;

      if(isSafe(nx,ny)){
        q.push(make_pair(nx,ny)); //pushing the new neighbour
        vis[nx][ny] = 1;
      }
    }

  }

  return 0;

}


int main(){

  int t;
  cin>>t;
  while(t--){

    cin>>n;
    m = n;

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){

        cin>>a[i][j];

        if(a[i][j] == 1){
            sx = i;
            sy = j;
        }

        if(a[i][j] == 2){
          x = i;
          y = j;
        }

      }
    }

    cout<<bfs()<<endl;

  }
  return 0;
}
