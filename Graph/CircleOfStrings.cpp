#include<bits/stdc++.h>
using namespace std;

#define M 26

void DFS(vector<int> g[],vector<int> &vis,int index){

  vis[index] = 1;

  for(auto i=g[index].begin();i!=g[index].end();i++)
    if(!vis[*i])
      DFS(g,vis,*i);

}


int isStronglyConnected(vector<int> g[],vector<int> mark,int index){

  vector<int> vis(M,0);

  DFS(g,vis,index);

  for(int i=0;i<M;i++)
    if(vis[i] != mark[i])
      return 0;

  return 1;
}


int isCycle(string s[],int n){

  vector<int> g[M]; //adjacency list

  vector<int> mark(M,0); //presence of letters

  vector<int> in(M,0); //counts inwards directions
  vector<int> out(M,0); //counts outwards directions

  for(int i=0;i<n;i++){

    int f = s[i].front() - 'a';
    int l = s[i].back() - 'a';

    mark[f] = 1;
    mark[l] = 1;

    //f -> l
    in[l]++;
    out[f]++;

    g[f].push_back(l);

  }

  //no.of in = out for each char
  for(int i=0;i<M;i++)
    if(in[i] != out[i])
      return 0;

  return isStronglyConnected(g,mark,s[0].front()-'a');

}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    string s[n];

    for(int i=0;i<n;i++)
      cin>>s[i];

    cout<<isCycle(s,n)<<endl;
  }
  return 0;
}
