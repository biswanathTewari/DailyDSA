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
    ll n,k;
    cin>>n>>k;

    ll a[n],b[n],min=0,max=0;

    fr(i,n){
      cin>>a[i];
      b[i] = a[i];
    }

    sort(a,a+n);
    sort(b,b+n,greater<ll>());

    ll i=0,j=n-1;

    while(i<=j){
      if(i == j){
        min+=a[i];
        break;
      }

      min+=a[i];
      i++;
      j-=k;
    }

    i=0;
    j=n-1;

    while(i<=j){
      if(i == j){
        max+=b[i];
        break;
      }

      max+=b[i];
      i++;
      j-=k;
    }

    cout<<min<<" "<<max<<endl;
  }

  return 0;
}
