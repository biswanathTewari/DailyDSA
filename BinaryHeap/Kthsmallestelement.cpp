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

void bizan(ll a[],ll n,ll k){
  priority_queue<ll, vector<ll> ,greater<ll> >q;
  ll b[n];
  fr(i,n){
    if(q.size()+1<k){
      b[i] = -1;
      q.push(a[i]);
    }
    else if(q.size()+1 == k){
      q.push(a[i]);
      b[i] = q.top();
    }
    else{
      if(a[i] >= q.top()){
        q.push(a[i]);
        q.pop();
      }
      b[i] = q.top();
    }
  }
  fr(i,n)
    cout<<b[i]<<" ";
  return;
}


int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll k,n;
    cin>>k>>n;
    ll a[n];
    fr(i,n)
      cin>>a[i];
    bizan(a,n,k);
    cout<<endl;
  }
  return 0;
}
