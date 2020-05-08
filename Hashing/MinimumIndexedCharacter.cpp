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

int main(){
  ll t;
  cin>>t;
  while(t--){
    string a,b;
    cin>>a>>b;

    ll loc[26];
    fill(loc,loc+26,-1);

    frev(i,a.length())
      loc[a[i]-'a'] = i;
    ll l=INT_MAX;
    char d;
    ll f=1;
    fr(i,b.length())
      if(loc[b[i]-'a'] != -1)
        if(l > loc[b[i] - 'a']){
          f = 0;
          l = loc[b[i]-'a'];
          d = b[i];
        }
    if(f)
      cout<<"$"<<endl;
    else cout<<d<<endl;
  }
  return 0;
}
