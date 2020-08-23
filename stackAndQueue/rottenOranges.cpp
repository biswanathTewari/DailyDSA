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

ll rottenoranges(ll r,ll c){
  queue<pair<ll,ll>> q;
  ll a[r][c];
  ll count=0,time=-1;
  fr(i,r)
    fr(j,c){
      cin>>a[i][j];
      if(a[i][j] == 2)
        q.push(make_pair(i,j));
      else if(a[i][j] == 1)
        count++;
    }
  q.push(make_pair(-1,-1));
  while(!q.empty()){
    pair<ll,ll> p = q.front();
    q.pop();
    if(p.first == -1 && p.second == -1){
      time++;
      if(!q.empty())
        q.push(make_pair(-1,-1));
    }
    if(p.first-1 >= 0)
      if(a[p.first-1][p.second] == 1){
        a[p.first-1][p.second]=2;
        q.push(make_pair(p.first-1,p.second));
        count--;
      }
    if(p.first+1 <= r-1)
      if(a[p.first+1][p.second] == 1){
        a[p.first+1][p.second]=2;
        q.push(make_pair(p.first+1,p.second));
        count--;
      }
    if(p.second-1 >= 0)
      if(a[p.first][p.second-1] == 1){
        a[p.first][p.second-1]=2;
        q.push(make_pair(p.first,p.second-1));
        count--;
      }
    if(p.second+1 <= c-1)
      if(a[p.first][p.second+1] == 1){
        a[p.first][p.second+1]=2;
        q.push(make_pair(p.first,p.second+1));
        count--;
      }
  }
  if(count)
    return -1;
  return time;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll r,c;
    cin>>r>>c;
    cout<<rottenoranges(r,c)<<endl;
  }
  return 0;
}
