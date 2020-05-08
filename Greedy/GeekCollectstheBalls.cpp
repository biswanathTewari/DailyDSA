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
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n,m,sum1=0,sum2=0,ans=0;

    cin>>n>>m;

    ll a[n],b[m];

    fr(i,n)
      cin>>a[i];

    fr(i,m)
      cin>>b[i];

    ll i=0,j=0;

    while(i<n && j<m){
      if(a[i] < b[j])
        sum1+=a[i++];

      else if(a[i] > b[j])
        sum2+=b[j++];

      else{
        ll init = a[i];

        while(a[i] == init && i<n){
          sum1+=a[i];
          i++;
        }

        while(b[j] == init && j<m){
          sum2+=b[j];
          j++;
        }

        ans+=max(sum1,sum2);
        sum1 = 0;
        sum2 = 0;
      }
    }

    while(i < n)
      sum1+=a[i++];

    while(j < m)
      sum2+=b[j++];

    cout<<ans+max(sum1,sum2)<<endl;
  }
  return 0;
}
