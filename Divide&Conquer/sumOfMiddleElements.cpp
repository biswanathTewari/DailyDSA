#include<bits/stdc++.h>
using namespace std;


int merge(int a[],int b[],int n){ // time : O(N) , space : O(N)

  vector<int> v;

  int l = 0 , r = 0;
  int count = 0;

  while(l<n && r<n && count != n+1){ // when the vector is filled till n (i.e 0 to n) , it has the middle elements of the 2n array

    if(a[l] < b[r]){
      v.push_back(a[l]);
      l++;
    }

    else{
      v.push_back(b[r]);
      r++;
    }

  }

  return v[n-1]+v[n];

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

    cout<<merge(a,b,n)<<endl;

  }

  return 0;

}
