#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


void sieve(ll primes[]){ //variation of sieve , instead for marking the multiple of a prime , we init the multiple wd the prime

  for(ll i=2;i<MAX;i++)
    if(primes[i] == -1){

      for(ll j=i;j<MAX;j+=i)
        if(primes[j] == -1)
          primes[j] = i;

    }

}

void geekNumber(vector<ll> &factors,ll primes[],ll n){ //time : O(log N)

  //basecase
  if(primes[n] == n) //if the number is prime
  {
    factors.push_back(n);
    return ;
  }

  factors.push_back(primes[n]);
  geekNumber(factors,primes,n/primes[n]);

}


int main(){

  fast;

  ll *primes = new ll[MAX];
  fill(primes,primes+MAX,-1);

  sieve(primes);

  ll t;
  cin>>t;

  while(t--){

    ll n;
    cin>>n;

    vector<ll> factors;

    geekNumber(factors,primes,n);

    ll prev = -1,f = 1;

    for(auto i: factors){
      if(i == prev){
        f = 0;
        break;
      }
      prev  = i;
    }

    if(f)
      cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

  }
  return 0;

}
