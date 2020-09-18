#include<bits/stdc++.h>
using namespace std;

#define MAX 100001 //it is the square root of the max(r)
#define MOD 1000000007
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


vector<ll> seive(){ //normal sieve

  ll primes[MAX+1];

  fill(primes,primes+MAX+1,1);
  primes[0] = 0;
  primes[1] = 0;

  for(ll i=2;i<=MAX;i++){
    if(primes[i]){
      for(ll j=i*2;j<=MAX;j+=i)
        primes[j] = 0;
    }
  }

  vector<ll> v;
  v.push_back(2);

  for(ll i=3;i<=MAX;i+=2)
    if(primes[i])
      v.push_back(i);

  return v;
}


ll product(vector<ll> primes,ll l,ll r){

  ll prod = 1;
  ll range[r-l+1];

  fill(range,range+r-l+1,1);

  for(ll i=0;primes[i]*(ll)primes[i]<=r;i++){ //iterating over the primes numbers till sqrt(r)

    ll base = (l/primes[i])*primes[i]; //multiple of primes[i] close to l(starting of the range)

    if(base<l)
      base+=primes[i];

    //marking all the multiples of primes[i] in the range l to r
    for(ll j=base;j<=r;j+=primes[i])
      range[j-l] = 0;

    //corner case when base is prime itself
    if(base == primes[i])
      range[base-l] = 1;

  }

  for(ll i=0;i<=r-l;i++){

    if(range[i])
      prod = ((prod%MOD)*((i+l)%MOD))%MOD;

  }

  return prod;

}


int main(){
  fast;

  ll t;
  cin>>t;

  vector<ll> primes = seive();

  while(t--){

    ll l,r;
    cin>>l>>r;

    cout<<product(primes,l,r)<<endl;

  }

  return 0;
}
