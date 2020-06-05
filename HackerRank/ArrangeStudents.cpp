/*biZan7X*/
#include<bits/stdc++.h>
using namespace std;


bool merge(int b[],int g[],int n){

  vector<int> v;

  int i=0,j=0,p = 0;
  bool left = false , right = false;

  while(i<n && j<n){
    if(b[i] < g[j] && p != 1){
      v.push_back(b[i]);
      i++;
      p = 1;
    }
    else if(g[j] < b[i] && p != 2){
      v.push_back(g[j]);
      j++;
      p = 2;
    }
    else if(b[i] == g[j]){
      if(p != 1){
        v.push_back(b[i]);
        v.push_back(g[j]);
        i++;
        j++;
        p = 2;
      }
      else{
        v.push_back(g[j]);
        v.push_back(b[i]);
        j++;
        i++;
        p = 1;
      }
    }
    else break;
  }

  if((2*n)-1 <= v.size())
    left = true;


  i = n-1,j = n-1,p = 0;

  v.clear();

  while(i >= 0 && j >= 0){

    if(b[i] > g[j] && p != 1){
      v.push_back(b[i]);
      i--;
      p = 1;
    }
    else if(g[j] > b[i] && p != 2){
      v.push_back(g[j]);
      j--;
      p = 2;
    }
    else if(b[i] == g[j]){
      if(p != 1){
        v.push_back(b[i]);
        v.push_back(g[j]);
        i--;
        j--;
        p = 2;
      }
      else{
        v.push_back(g[j]);
        v.push_back(b[i]);
        j--;
        i--;
        p = 1;
      }
    }
    else break;
  }

  if((2*n)-1 <= v.size())
    right = true;


  return left || right;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int b[n],g[n];


    for(int i=0;i<n;i++){
      cin>>b[i];
    }

    for(int i=0;i<n;i++){
      cin>>g[i];
    }

    sort(b,b+n);
    sort(g,g+n);

    if(merge(b,g,n))
      cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

  }
  return 0;
}
