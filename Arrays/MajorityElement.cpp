/*
https://practice.geeksforgeeks.org/problems/majority-element/0
DailyDSA: bizan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main(){

  fast;

  int t;
  cin>>t;

  while(t--){

    ll n;
    cin>>n;

    map<ll,ll> mp;

    ll x;

    for(ll i=0;i<n;i++){
      cin>>x;
      if(mp.find(x) == mp.end())
        mp[x] = 1;
      else mp[x]++;
    }

    double majority = (double)(n/2);
    ll f = 0 , element;

    for(auto it=mp.begin();it!=mp.end();it++){
      if(it->second > majority){
        f = 1;
        element = it->first;
      }
    }

    if(f)
      cout<<element<<endl;
    else cout<<-1<<endl;


  }
  return 0;
}
