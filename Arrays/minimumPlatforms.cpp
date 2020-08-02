#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first < b.first;
}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n],b[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    for(int i=0;i<n;i++)
      cin>>b[i];

    vector<pair<int,int>> v;

    for(int i=0;i<n;i++)
      v.push_back(make_pair(a[i],b[i]));

    sort(v.begin(),v.end(),cmp); //sorting the trains according to their arrival time

    int count = 0;
    int vis[n] = {0};

    for(int i=0;i<n;i++){

      if(vis[i]) //if the this train has been allocated platform
        continue;
      else count++; //if not , created a new platform

      int lastdept = v[i].second;

      for(int j=i+1;j<n;j++) //checking how many trains can this platform handle
        if(v[j].first > lastdept && !vis[j]){
          vis[j] = 1;
          lastdept = v[j].second;
        }

    }

    cout<<count<<endl;

  }

  return 0;
}
