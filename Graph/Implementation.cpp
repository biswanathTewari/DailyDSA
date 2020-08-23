#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> v[],int u,int y){
  v[u].push_back(y);
  v[y].push_back(u);
}

void printGraph(vector<int> v[],int V){

  for(int i=0;i<V;i++){
    cout << "\n Adjacency list of vertex "
             << i << "\n head ";
        for (auto x : v[i])
           cout << "-> " << x;
        printf("\n");
  }
}

int main(){
  int n,en;
  cout<<"enter the number of Vertices"<<endl;
  cin>>n;

  vector<int> v[n];

  cout<<"enter the no of edges"<<endl;
  cin>>en;

  for(int i=0;i<en;i++){
    int x,y;
    cin>>x>>y;
    insert(v,x,y);
  }

  printGraph(v,n);

  return 0;
}
