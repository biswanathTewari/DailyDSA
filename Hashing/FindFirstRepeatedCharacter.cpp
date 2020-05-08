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

char bizan(ll a[],string s){

  fr(i,s.length()){
    if(a[s[i]-'a'] == 0)
      a[s[i]-'a']++;
    else return s[i];
  }

  return '#';
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    ll a[26];
    fill(a,a+26,0);

    char b = bizan(a,s);

    if(b != '#')
      cout<<b<<endl;
    else cout<<-1<<endl;
  }
  return 0;
}
