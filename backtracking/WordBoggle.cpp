#include<bits/stdc++.h>
using namespace std;

vector<string> v;
string dic[11]; //dic stands for dictionary , get it straight u pervert!!
int x;
int n,m;
char boggle[11][11];
int dx[8] = {1,0,0,-1,-1,-1,1,1};
int dy[8] = {0,-1,1,-0,-1,1,-1,1};


void printWords(){

  sort(v.begin(),v.end());

  for(auto i:v)
    cout<<i<<" ";

  cout<<endl;

}


bool looking(string &str){

  for(int i=0;i<x;i++)
    if(dic[i] == str)
      return true;

  return false;

}


bool isSafe(int row,int col,bool vis[11][11]){

  if(row<0 || row>=n || col<0 || col>=m)
    return false;

  if(vis[row][col] == true)
    return false;

  return true;

}


void google(int row,int col,bool vis[11][11],string &str){

  vis[row][col] = true;
  str.push_back(boggle[row][col]);

  if(looking(str)){
    //cout<<"working"<<endl;
    v.push_back(str);
  }

  for(int i=0;i<8;i++){

      int rx = row + dx[i];
      int cx = col + dy[i];

      if(isSafe(rx,cx,vis))
        google(rx,cx,vis,str);
  }

  str.pop_back();
  vis[row][col] = false;

}


void findWords(){

  bool vis[11][11] = {{false}};

  v.clear();
  string str = "";

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      google(i,j,vis,str);

  if(v.size() > 0)
    printWords();
  else cout<<-1<<endl;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    cin>>x;

    for(int i=0;i<x;i++)
      cin>>dic[i];

    cin>>n>>m;

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>boggle[i][j];

    findWords();

  }

  return 0;
}
