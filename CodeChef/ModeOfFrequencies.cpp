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
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (i)=(i+c))
#define w(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


/*Link : https://www.codechef.com/LTIME87B/problems/MODEFREQ  */

int main(){
  fast;
  ll t;
  cin>>t;

  while(t--){

    ll n,k;
    cin>>n;

    ll a[n];
    fr(i,n)
      cin>>a[i];

    ll num[11];
    fill(num,num+11,0);

    fr(i,n)
      num[a[i]]++;

    ll mx = INT_MIN;

    ll freq[10001];
    fill(freq,freq+10001,0);

    for(int i=1;i<=10;i++)
      freq[num[i]]++;

    for(int i=1;i<10001;i++)
      mx = max(mx,freq[i]);

    vector<int> v;

    for(int i=1;i<10001;i++)
      if(freq[i] == mx)
        v.push_back(i);

    sort(v.begin(),v.end());

    cout<<v[0]<<endl;
  }
  return 0;
}
