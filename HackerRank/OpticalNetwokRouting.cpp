//using dijkstra's algo in a modified version

#include<bits/stdc++.h>
using namespace std;
#define mk make_pair

#define max 100

bool isValid(int x, int y, int n)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return true;
    }
    return false;
}

int shortestPath(int a[max][max],int n){

  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};

  int dis[n][n];

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      dis[i][j] = INT_MAX;

  set<pair<int,pair<int,int>>> s;

  s.insert(mk(a[0][0],mk(0,0)));
  dis[0][0] = a[0][0];

  while(!s.empty()){

    pair<int,pair<int,int>> p = *(s.begin());
    pair<int,int> vec = p.second;
    int cost = p.first;
    s.erase(s.begin());

    for(int k=0;k<4;k++){
      int xvec = vec.first + dx[k];
      int yvec = vec.second + dy[k];

      if(isValid(xvec,yvec,n)){

        if(cost + a[xvec][yvec] < dis[xvec][yvec]){
          auto l = s.find(mk(dis[xvec][yvec],mk(xvec,yvec)));

          if(l != s.end())
            s.erase(l);

          dis[xvec][yvec] = cost + a[xvec][yvec];
          s.insert(mk(dis[xvec][yvec],mk(xvec,yvec)));
        }
      }
    }

  }

  return dis[n-1][n-1];

}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    int a[max][max];

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        cin>>a[i][j];
    }

    cout<<shortestPath(a,n)<<endl;
  }
  return 0;
}
