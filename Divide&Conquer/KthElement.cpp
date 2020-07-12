#include<bits/stdc++.h>
using namespace std;


int merge(int a[],int b[],int n,int m,int target){

  int c[n+m];

  int i = 0, j = 0 , k = 0;

  while(i<n && j<m){

    if(a[i] < b[j])
      c[k++] = a[i++];
    else c[k++] = b[j++];

  }

  while(i<n)
    c[k++] = a[i++];

  while(j<m)
    c[k++] = b[j++];

  return c[target-1];

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n,m,k;
    cin>>n>>m>>k;

    int a[n],b[m];

    for(int i=0;i<n;i++)
      cin>>a[i];

    for(int i=0;i<m;i++)
      cin>>b[i];

    cout<<merge(a,b,n,m,k)<<endl;

  }

  return 0;

}
