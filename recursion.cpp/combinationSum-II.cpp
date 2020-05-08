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

vector<vll> bv;

void biZan(ll a[],ll index,ll sum,ll n,ll target,vll v){
  if(sum==target){
    bv.pb(v);
    return ;
  }
  if(sum>target)
    return ;
  ll x=-1;
  for(ll i=index;i<n;i++){
    if(x==a[i])
      continue;
    sum+=a[i];
    v.pb(a[i]);
    biZan(a,i+1,sum,n,target,v);
    v.pop_back();
    sum-=a[i];
    x=a[i];
  }
  return ;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    bv.clear();
    ll n,target;
    cin>>n;
    ll a[n];
    fr(i,n)
      cin>>a[i];
    cin>>target;
    vll v;
    sort(a,a+n);
    biZan(a,0,0,n,target,v);
    if(bv.size()){
      fr(i,bv.size()){
        cout<<"(";
        fr(j,bv[i].size()-1)
          cout<<bv[i][j]<<" ";
        cout<<bv[i][bv[i].size()-1]<<")";
      }
    }
    else
      cout<<"Empty";
    cout<<endl;
  }
  return 0;
}
