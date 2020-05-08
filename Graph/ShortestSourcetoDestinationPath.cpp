//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
#define str string
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;

class Item {
public :
  int row;
  int col;
  int dis;

  Item(int x,int y,int z)
    : row(x), col(y), dis(z)
  {}
};


int shortestPath(){

  int n,m,ti,tj;
  cin>>n>>m;

  int a[n][m];

  int vis[n][m];
  fr(i,n){
    fr(j,m){
      cin>>a[i][j];
      if(a[i][j] == 0)
        vis[i][j] = 1;
      else vis[i][j] = 0;
    }
  }

  cin>>ti>>tj;
  Item source(0,0,0);

  queue<Item> q;
  q.push(source);
  vis[source.row][source.col] = 1;

  while(!q.empty()){
    Item temp = q.front();
    q.pop();

    if(temp.row == ti && temp.col == tj)
      return temp.dis;

    //moving up
    if(temp.row - 1 >= 0 && vis[temp.row-1][temp.col] == 0){
      q.push(Item(temp.row-1,temp.col,temp.dis+1));
      vis[temp.row-1][temp.col] = 1;
    }

    //moving Down
    if(temp.row + 1 < n && vis[temp.row+1][temp.col] == 0){
      q.push(Item(temp.row+1,temp.col,temp.dis+1));
      vis[temp.row+1][temp.col] = 1;
    }

    //moving left
    if(temp.col - 1 >= 0 && vis[temp.row][temp.col-1] == 0){
      q.push(Item(temp.row,temp.col-1,temp.dis+1));
      vis[temp.row][temp.col-1] = 1;
    }

    //moving right
    if(temp.col + 1 < m && vis[temp.row][temp.col+1] == 0){
      q.push(Item(temp.row,temp.col+1,temp.dis+1));
      vis[temp.row][temp.col+1] = 1;
    }
  }

  return -1;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    cout<<shortestPath()<<endl;
  }
  return 0;
}
