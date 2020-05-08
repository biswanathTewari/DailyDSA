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

void bizan(char ch[],ll n){
  list<char> l;
  ll a[26];
  list<char> ::iterator b[26];
  fill(a,a+26,0);
  fr(i,n){
    ll x = ch[i]-97;
    if(a[x]==0){
      l.push_back(ch[i]);
      a[x]++;
      b[x] = l.end();
      b[x]--;
    }
    else if(a[x] == 1){
      l.erase(b[x]);
      a[x]++;
    }
    if(l.empty())
      cout<<"-1"<<" ";
    else cout<<l.front()<<" ";
  }
}



int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    char ch[n];
    fr(i,n)
      cin>>ch[i];
    bizan(ch,n);
    cout<<endl;
  }
  return 0;
}
