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


ll medium(ll a[],ll start,ll end){

  sort(a,a+end+1);

  if((end - start + 1)%2 != 0)
    return  a[((start + end)/2)];

  ll low = floor((start + end)/2);
  ll high = low + 1;

  ll avg = (a[low]+a[high])/2;

  return avg;
}

int main(){
  fast;

  ll n,d,count=0;
  cin>>n>>d;

  ll a[n];

  fr(i,n)
    cin>>a[i];

  fr(i,d)

  for(ll i =d;i<n;i++){
    ll med = medium(a,i-d,i-1);

    if(a[i] >= (2*med))
      count++;
  }

  cout<<count<<endl;

  return 0;
}
