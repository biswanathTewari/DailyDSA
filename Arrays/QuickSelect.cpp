#include<bits/stdc++.h>
using namespace std;


int partition(int a[],int low,int high){

  int p = high;
  int i = low-1;

  for(int j=low;j<high;j++){

    if(a[j] < a[p]){
      i++;
      swap(a[i],a[j]);
    }

  }

  swap(a[i+1],a[p]);

  return i+1;

}


int quickSelect(int a[],int low,int high,int k){ //time : O(N) ~ O(N^2) , space : O(1)

  if(k > 0 && k <= high-low+1){

    int pt = partition(a,low,high);

    if(pt - low == k - 1)
      return a[pt];

    if(k - 1 < pt - low)
      return quickSelect(a,low,pt-1,k);
    else return quickSelect(a,pt+1,high,k - (pt + 1 - low));

  }

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n,k;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    cin>>k;

    cout<<quickSelect(a,0,n-1,k)<<endl;
  }

  return 0;
}
