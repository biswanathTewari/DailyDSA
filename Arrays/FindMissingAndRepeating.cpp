#include<bits/stdc++.h>
using namespace std;

#define ll long long int


void MissingAndRepeating(ll a[],ll n){ //time : O(N), space : O(1)

  ll counter = 0;
  ll B,A = 0;

  for(ll i=0;i<n;i++){

    if((counter & (1 << a[i])) != 0)
      B = a[i];

    counter = counter | (1 << a[i]);
    //cout<<counter<<endl;

  }

  counter/=10;

  for(ll i = counter;i>0;i/=10){

    A++;

    if(i%10 == 0)
      break;

  }

  cout<<B<<" "<<A<<endl;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    ll n;
    cin>>n;

    ll a[n];

    for(ll i=0;i<n;i++)
      cin>>a[i];

    MissingAndRepeating(a,n);

  }

  return 0;
}
