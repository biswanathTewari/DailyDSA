#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

  ll n,m;
  cin>>n>>m;

  ll lim = 10E6;
  ll *present = new ll[lim];

  fill(present,present+lim,0);

  ll a[n],sum=0;

  for(ll i=0;i<n;i++){
    a[i] = i+1;
    sum+=a[i];
    present[a[i]] = 1;
  }

  for(ll i=0;i<m;i++){

    ll x;
    cin>>x;

    if(present[x]){

      swap(a[0],a[n-1]);
      cout<<sum<<endl;

    }
    else{

      present[a[n-1]] = 0;
      present[x] = 1;
      sum -= a[n-1];
      sum += x;
      a[n-1] = x;
      cout<<sum<<endl;

    }

  }

  return 0;
}
