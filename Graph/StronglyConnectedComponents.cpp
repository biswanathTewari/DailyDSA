#include<bits/stdc++.h>
using namespace std;

void DFSstack(vector<int> al[],int vis[],int index,stack<int> &s){

  vis[index] = 1;

  for(auto i = al[index].begin(); i != al[index].end(); i++){
    if(vis[*i] == 0)
      DFSstack(al,vis,*i,s);
  }

  s.push(index);

}


void DFScount(vector<int> tl[],int vis[],int index){

  vis[index] = 1;

  for(auto i = tl[index].begin(); i != tl[index].end(); i++){
    if(vis[*i] == 0)
      DFScount(tl,vis,*i);
  }

}


int SSC(vector<int> al[],vector<int> tl[],int n){

  int count = 0;
  stack<int> s;

  int vis[n];
  fill(vis,vis+n,0);


  //DFS + storing in stack
  for(int i=0;i<n;i++){
    if(vis[i] == 0){
        DFSstack(al,vis,i,s);
    }
  }


  fill(vis,vis+n,0);


  //creating transpose Graph ,incase not passed as a parameter to the function
  /* vector<int> trp[n];

  for(int i=0;i<n;i++){
    for(auto j = al[i].begin();j != al[i].end() ;j++){
        trp[*j].push(i);
    }
  } */


  //DFS on transpose Graph
  while(!s.empty()){

    int x = s.top();
    s.pop();

    //DFS
    if(vis[x] == 0){
      DFScount(tl,vis,x);

    //after traversing one Connected Component
    count++;
    }

  }

  return count;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n,m;

    cin>>n>>m;

    vector<int> al[n]; //alacent list
    vector<int> tl[n]; //transpose list

    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;

      al[a].push_back(b);
      tl[b].push_back(a);
    }

    cout<<SSC(al,tl,n)<<endl;

  }

  return 0;
}
