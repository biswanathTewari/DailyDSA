#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void sorted(ll a[],ll n){ //time : O(N) : space : O(1)

  ll counter[3] = {0}; //counts the number of 0s 1s and 2s

  for(ll i=0;i<n;i++)
    if(a[i] == 0)
      counter[0]++;
    else if(a[i] == 1)
      counter[1]++;
    else counter[2]++;


  //printing the sorted array
  for(ll i=0;i<n;i++)
    if(counter[0]){
      cout<<0<<" ";
      counter[0]--;
    }
    else if(counter[1]){
      cout<<1<<" ";
      counter[1]--;
    }
    else if(counter[2]){
      cout<<2<<" ";
      counter[2]--;
    }

  cout<<endl;

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

    sorted(a,n);

  }

  return 0;
}
