//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
#define str string
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;

ll biZan(ll n,ll a[]){
  if(a[n]!=0)
    return a[n];
  ll j=1;
  for(ll i=n-3;i>=1;i--){
    ll temp=(j++ + 1)*biZan(i,a);
    a[n]=max(a[n],temp);
  }

  return a[n];
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll a[76]={0};
    fr(i,7)
      a[i]=i;
    if(n>=75)
      cout<<-1<<endl;
    else
      cout<<biZan(n,a)<<endl;
  }
  return 0;
}
