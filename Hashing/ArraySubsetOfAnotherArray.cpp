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


bool bizan(ll a[],ll b[]){

  fr(i,100005)
    if(b[i] > a[i])
      return false;

  return true;
}


int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll m,n;
    cin>>m>>n;
    ll a[100005],b[100005];

    fill(a,a+100005,0);
    fill(b,b+100005,0);

    fr(i,m){
      ll x ;
      cin>>x;
      a[x]++;
    }

    fr(i,n){
      ll x;
      cin>>x;
      b[x]++;
    }

    if(bizan(a,b))
      cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

  }
  return 0;
}
