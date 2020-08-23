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
    fast;
    string str;
    cin>>str;

    map<char,ll> mp;
    map<ll,ll> bi;

    fr(i,str.length())
      mp[str[i]]++;

    for(auto i :mp)
      bi[i.second]++;

    if(bi.size() == 1)
      cout<<1<<endl;
    else if(bi.size() == 2){

      ll a[2],flag = 0,ans,j=0;

      for(auto i: bi){
        if(i.second == 1 && j == 1)
          flag++;
        a[j++] = i.first;
      }

      ans = abs(a[1] - a[0]);

      if(flag > 0 && ans == 1)
        cout<<1<<endl;
      else cout<<-1<<endl;

    }
    else cout<<0<<endl;

  }
  return 0;
}
