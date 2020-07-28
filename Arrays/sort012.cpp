#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void sorted(ll a[],ll n){ //time : O(N) : space : O(1)

  ll high = n-1;
  ll low = 0;
  ll mid = 0;

  while(mid <= high){

    if(a[mid] == 0 )
      swap(a[mid++],a[low++]);

    else if(a[mid] == 1) //simply ignore
      mid++;

    else swap(a[mid],a[high--]); //next check will start from current mid only, due to the swap from high

  }

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

    for(ll i=0;i<n;i++)
      cout<<a[i]<<" ";
    cout<<endl;

  }

  return 0;
}
