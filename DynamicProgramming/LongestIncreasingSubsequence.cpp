/*Longest Increasing Subsequence : iterative approach O(N^2)*/
#include<bits/stdc++.h>
using namespace std;


int LIS(int a[],int n){

  int out[n];
  out[0] = 1; //at max for this element LIS is 1 : baseCase

  for(int i=1;i<n;i++){
    out[i] = 1;

    for(int j=i-1;j>=0;j--){

      if(a[j] >= a[i]) //if the previuos numners are greater or same as the current , then dont we want them
        continue;

      out[i] = max(out[j] + 1 , out[i]); 

    }
  }

  int ans = INT_MIN;

  for(int i=0;i<n;i++)
    ans = max(ans , out[i]);

  return ans;

}


int main(){
  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    cout<<LIS(a,n)<<endl;

  }

  return 0;
}
