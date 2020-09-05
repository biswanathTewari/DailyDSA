//biZanXsolutions

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007


ll power(ll a,ll b){

  ll res = 1;

  a = a%MOD;

  if(a == 0)
    return 0;

  while(b > 0){

    if(b & 1)
      res = (res * a)%MOD;

    a = (a*a)%MOD;

    b = b >> 1;

  }

  return res;

}

int main(){

  int n;
  cin>>n;

  ll a[n];
  ll sum = 0,mx = INT_MIN;

  for(ll i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    mx = max(mx,a[i]);
  }

  cout<<power(sum,mx)<<endl;

  return 0;
}
