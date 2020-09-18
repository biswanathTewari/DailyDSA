//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
#define stir string
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;

void nextlarger(ll a[],ll n){
  stack<ll> s;
  ll b[n];

  //array to store the next larger element for each position
  fill(b,b+n,-1);


  fr(i,n){

      //only smaller elements gets entry to the stack
      if(s.empty() || a[i]<a[s.top()])
        s.push(i);

      else{
          //all the elements in the stack gets a[i] as there next larger element
          while(!s.empty() && a[i]>a[s.top()]){
            ll x = s.top();
            s.pop();
            b[x]=a[i];
          }
          s.push(i);
      }
  }

  fr(i,n)
    cout<<b[i]<<" ";
  cout<<endl;

  return;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll a[n];
    fr(i,n)
      cin>>a[i];
    nextlarger(a,n);
  }
  return 0;
}
