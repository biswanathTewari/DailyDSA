/*
https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


ll closests(ll a[],ll n){ //time : O(n log n) due to the sorting we do

  sort(a,a+n);

  ll prev = INT_MAX;

  ll left = 0 , right = n-1;

  while(left < right){

    ll sum = a[left] + a[right];

    if(abs(sum) < abs(prev))
      prev = a[left] + a[right];

    if(sum < 0)
      left++ ;
    else right --;

  }


  return prev;

}


int main(){
  fast;

  int t;
  cin>>t;

  while(t--){

    ll n;
    cin>>n;
    ll a[n];

    for(ll i=0;i<n;i++){
      cin>>a[i];
    }

    cout<<closests(a,n)<<endl;

  }

  return 0;
}
