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

void bizan(ll n,ll s){
  if(n == 0) { cout<<endl; return ; }

  if(s < 10){
    cout<<s;
    bizan(n-1,0);
  }
  else{
    cout<<9;
    bizan(n-1,s-9);
  }
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n,s;
    cin>>n>>s;

    if(n*9 < s) cout<<-1<<endl;
    else if(n == 0 || s == 0) cout<<-1<<endl;
    else bizan(n,s);
  }
  return 0;
}
