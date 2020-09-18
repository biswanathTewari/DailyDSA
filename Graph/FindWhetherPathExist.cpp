//Algo using BFS
#include<bits/stdc++.h>
using namespace std;


class Graph{
public:
  int row;
  int col;

  Graph(int x,int y){
    row = x;
    col = y;
  }
};

int findPath(int n){
  int a[n][n];
  int vis[n][n];
  int dr,dc;

  Graph source(0,0);

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];

      if(a[i][j] == 0)
        vis[i][j] = 1;
      else vis[i][j] = 0;

      if(a[i][j] == 1){
        source.row = i;
        source.col = j;
      }

      if(a[i][j] == 2){
        dr = i;
        dc = j;
      }
    }
  }

  queue<Graph> q;
  q.push(source);
  vis[source.row][source.col] = 1;

  while(!q.empty()){
    Graph temp = q.front();
    q.pop();

    if(temp.row == dr && temp.col == dc)
      return 1;

    //moving up
    if (temp.row - 1 >= 0 &&
			vis[temp.row - 1][temp.col] == 0) {
			q.push(Graph(temp.row - 1, temp.col));
			vis[temp.row - 1][temp.col] = 1;
		}

		// moving down
		if (temp.row + 1 < n &&
			vis[temp.row + 1][temp.col] == 0) {
			q.push(Graph(temp.row + 1, temp.col));
			vis[temp.row + 1][temp.col] = 1;
		}

		// moving left
		if (temp.col - 1 >= 0 &&
			vis[temp.row][temp.col - 1] == 0) {
			q.push(Graph(temp.row, temp.col - 1));
			vis[temp.row][temp.col - 1] = 1;
		}

		// moving right
		if (temp.col + 1 < n &&
			vis[temp.row][temp.col + 1] == 0) {
			q.push(Graph(temp.row, temp.col + 1));
			vis[temp.row][temp.col + 1] = 0;
    }

  }

  return 0;
}


int main(){
  fast;
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<findPath(n)<<endl;
  }
  return 0;
}
