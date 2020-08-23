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

bool cmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
  return a.first.second < b.first.second ;
}

int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n,c,pc=0,count = 0;
    cin>>n;
    ll a[n];

    fr(i,n)
      cin>>a[i];
    cin>>c;

    deque<ll> q;

    fr(i,n){

      ll flag = 1,pos;

      fr(j,q.size()){

        if(q[j] == a[i]){
          flag = 0;
          pos = j;
        }
      }

      if(flag){
        count++;

        if(pc < c){
          q.push_back(a[i]);
          pc++;
        }
        else{
          q.pop_front();
          q.push_back(a[i]);
        }
      }
      else{

        q.erase(q.begin()+pos);
        q.push_back(a[i]);

      }

    }

    cout<<count<<endl;

  }
  return 0;
}
