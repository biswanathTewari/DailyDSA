#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL) ; cout.tie(NULL)


int counting(ll x,ll b[],ll be[],ll m){ //time : O(log m)

  if(x == 0) return 0;

  if(x == 1) return be[0]; //returning the count of zeroes in b


  //general case all the numbers in b greater x counts + 0's and 1's
  ll sum = 0;
  ll p = upper_bound(b,b+m,x) - b;
  sum = (m - p);
  sum += (be[0]+be[1]); //adding the counts of 0's and 1's


  //now the expections.
  //when x is 2 , the logic fails when y is 3 or 4, rest is same
  if(x == 2)
    sum -= (be[3]+be[4]);


  //when x is 3, just like o's and 1's , 2's also counts in this case -> 3^2 > 2^3
  if(x == 3)
    sum += be[2];


  return sum; //Yup ! thats it .. done ;)

}


ll countPairs(ll a[],ll b[],ll n,ll m){ //time: O(M log M + N log M)

  ll be[5] = {0}; //be -> elements of b

  for(ll i=0;i<m;i++)
    if(b[i]<5)
      be[b[i]]++;

  ll counter  = 0;

  sort(b,b+m); //O(M log M)

  for(ll i=0;i<n;i++) //O( N * log M)
    counter += counting(a[i],b,be,m);

  return counter;

}

int main(){

  fast;
  int t;
  cin>>t;

  while(t--){

    ll n,m;
    cin>>n>>m;

    ll a[n],b[m];

    for(ll i=0;i<n;i++)
      cin>>a[i];

    for(ll i=0;i<m;i++)
      cin>>b[i];

    cout<<countPairs(a,b,n,m)<<endl;

  }

  return 0;
}
