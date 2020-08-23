#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


ll reverseDigits(ll n){

  ll rev = 0;

  while(n>0){

    rev = rev*10 + n%10;
    n/=10;

  }

  return rev;

}


ll power(ll n,ll r){ // time : O(log r)

  ll res = 1;

  n = n % MOD;

  if(n == 0)
    return 0; //incase n is divisible by MOD

  while(r > 0){

    if(r & 1) //if odd
      res = (res*n)%MOD;

    n = (n*n)%MOD;
    r = r >> 1;// r = r/2;

  }

  return res;

}


int main(){
  fast;

  int t;
  cin>>t;

  while(t--){

    ll n;
    cin>>n;

    ll r = reverseDigits(n);

    if(n)
      cout<<power(n,r)<<endl;
    else cout<<1<<endl;

  }

  return 0;
}
