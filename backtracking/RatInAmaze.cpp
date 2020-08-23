#include<bits/stdc++.h>
using namespace std;

int maze[6][6];
bool vis[6][6]; //to make sure that we dont use the co-ordinate we already used for the current path , else it will become a infinite loop
vector<string> v; //to store the paths
string path;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,-0};
char diString[4] = {'D','L','R','U'}; //direction chars


void printPaths(){

  for(auto i:v)
    cout<<i<<" ";

  cout<<endl;

}


bool isSafe(int row,int col,int n){

  //if already used ,i.e., making sure that we dont revisit the current path
  if(vis[row][col])
    return false;

  //if out of the maze dimensions
  if(row < 0 || row > n-1 || col < 0 || col > n-1)
    return false;

  //if the cell is blocked
  if(maze[row][col] == 0) //the value is 0
    return false;

  return true;

}


bool ratHole(int row,int col,int n){

  //if out of the maze dimensions
  if(row < 0 || row > n-1 || col < 0 || col > n-1)
    return false;

  //out of the maze
  if(row >= n-1 && col >= n-1){
    v.push_back(path);
    return true;
  }


  bool res = false;

  vis[row][col] = true; //used for the current path

  for(int i=0;i<4;i++){ //moving in all four directions

    int rowx = row + dx[i];
    int colx = col + dy[i]; //new co-ordinates

    if(isSafe(rowx,colx,n)){

      path.push_back(diString[i]);

      res = ratHole(rowx,colx,n) || res;

      path.pop_back();

    }

  }

  vis[row][col] = false; //making it available for the other paths

  return res;

}


void solve(){

  int n;
  cin>>n;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>maze[i][j];

  memset(vis,false,sizeof(vis));


  if(!maze[0][0] || !ratHole(0,0,n)){

    cout<<-1<<endl;
    return ;

  }

  printPaths();

  return ;

}

int main(){

  int t;
  cin>>t;

  while(t--){

    v.clear();
    path = "";
    solve();
  }
  return 0;
}
