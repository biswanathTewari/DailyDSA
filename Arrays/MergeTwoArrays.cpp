/*

Variation of insertion sort, using shell short
https://www.youtube.com/watch?v=Bcay1cEqrrA
Time : O((m+n)log(n+m)) , space : O(1)

*/

#include<bits/stdc++.h>
using namespace std;


int nextGap(int gap){
  if (gap <= 1)
      return 0;
  return (gap / 2) + (gap % 2); //can use ceil
}

void merge(int a[],int b[],int n,int m){

  int i,j,gap;

  for(int gap = nextGap(n+m); gap > 0; gap=nextGap(gap)){

    //operating till the first array
    for(i=0;i+gap<n;i++)
      if(a[i] > a[i+gap])
        swap(a[i],a[i+gap]);

    //operating on both the arrays, till the scope of the first array does not finishes
    j = (gap > n)? gap-n : 0; //if gap<n , then there will an instance when gap will enter array 2 from index 0.
    for(;i<n && j<m;i++,j++)
      if(a[i]>b[j])
        swap(a[i],b[j]);

    if(j<m){

      for(j=0;j+gap<m;j++)
        if(b[j]>b[j+gap])
          swap(b[j],b[j+gap]);

    }

  }

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int m,n;
    cin>>n>>m;

    int a[n],b[m];

    //inputs
    for(int i=0;i<n;i++)
      cin>>a[i];

    for(int i=0;i<m;i++)
      cin>>b[i];

    //merging
    merge(a,b,n,m);

    //printing
    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";

    for(int i=0;i<m;i++)
      cout<<b[i]<<" ";

    cout<<endl;

  }

  return 0;
}
