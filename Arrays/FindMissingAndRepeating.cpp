#include<bits/stdc++.h>
using namespace std;

#define ll long long int


void MissingAndRepeating(ll a[],ll n){ //time : O(N), space : O(1)


  ll missing , repeating;

  for(ll i=0;i<n;i++)
    if(a[abs(a[i])-1] > 0) //using indexing with the same array , instead of 0 & 1 , using -ve & +ve to signify visited or not
      a[abs(a[i])-1] *= -1;
    else repeating = abs(a[i]);

  for(ll i=0;i<n;i++)
    if(a[i] > 0){ //the only +ve element is the missing element
      missing = i+1;
      break;
    }

  cout<<repeating<<" "<<missing<<endl;

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
