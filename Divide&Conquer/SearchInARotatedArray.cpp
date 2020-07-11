#include<bits/stdc++.h>
using namespace std;


int search(int a[],int n,int k,int x){ // time : O(N) , space : O(1)

  int res1 = lower_bound(a,a+x,k) - a; //first of the half
  int res2 = lower_bound(a+x,a+n,k) - a; //point after which the array is rotated

  if(res1 >= n || k != a[res1])
    res1 = -1;

  if(res2 >= n || k != a[res2])
    res2 = -1;

  return max(res1,res2);

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n];
    int x,k,prev = -1;

    for(int i=0;i<n;i++){
      cin>>a[i];

      if(prev > a[i])
        x = i; //stores the point from where the array is rotated

      prev = a[i];
    }

    cin>>k;

    cout<<search(a,n,k,x)<<endl;

  }

  return 0;

}
