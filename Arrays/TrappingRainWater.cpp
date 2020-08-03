#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];

    int left[n],right[n],sum = 0;

    left[0] = a[0];
    right[n-1] = a[n-1];

    for(int i=1;i<n;i++){
      left[i] = max(left[i-1],a[i]); //max flow from left to right
    }

    for(int i=n-2;i>=0;i--)
      right[i] = max(right[i+1],a[i]); //max flow from right to left

    for(int i=0;i<n;i++)
      sum += min(left[i],right[i]) - a[i];

    cout<<sum<<endl;

  }

  return 0;
}
