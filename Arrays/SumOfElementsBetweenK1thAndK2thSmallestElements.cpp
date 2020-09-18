/*
https://practice.geeksforgeeks.org/problems/min-subsets-with-consecutive-numbers/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fast ios::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL)

int SumOfElement(vector<ll> &a,ll n,ll k,ll l){ // time : O(N log N) , space : O(1)

  sort(a.begin(),a.end());

  ll smaller = a[k-1];
  ll greater = a[l-1];

  ll sum = 0;

  for(ll i=k;i<=l-2;i++)
    if(i>=0 && i<n)
      sum+=a[i];

  return sum ;

  /*//prefix Sum
  for(int i=1;i<n;i++)
    a[i]+=a[i-1];

  if(k == 1)
    return a[l-1] - (smaller + greater);

  return ((a[l-1] - a[k-2]) - (smaller + greater)); */
}


int main(){
  fast;

  int t;
  cin>>t;

  while(t--){

    ll n;
    cin>>n;

    vector<ll> a(n);

    for(ll i=0;i<n;i++)
      cin>>a[i];

    ll k,l;
    cin>>k>>l;

    cout<<SumOfElement(a,n,k,l)<<endl;

  }

  return 0;
}
