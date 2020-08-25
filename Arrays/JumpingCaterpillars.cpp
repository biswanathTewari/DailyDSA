/*
https://practice.geeksforgeeks.org/problems/jumping-caterpillars/0
DailyDSA: biZan7X
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

    ll n,k;
    cin>>n>>k;

    vector<ll> v;

    for(int i=1;i<=k;i++){
        ll x;
        cin>>x;
        v.push_back(x);
    }

    //removing teh duplicates
    vector<ll> ::iterator it;
    it = unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));

    ll *num = new ll[n+1];
    fill(num,num+n+1,0);

    //using sieve of eratosthenes algo
    for(int i=0;i<v.size();i++){

      int x = v[i];
      if(num[x] != 1){
        for(ll j=x;j<=n;j+=x)
          num[j] = 1;
      }

    }

    ll count = 0;

    for(ll i=1;i<=n;i++)
      if(num[i] == 0)
        count++;

    cout<<count<<endl;

  }

  return 0;
}
