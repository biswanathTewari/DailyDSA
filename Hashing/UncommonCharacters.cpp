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
    ll al[26],bl[26],final[26];
    char alp[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    fill(al,al+26,0);
    fill(bl,bl+26,0);
    fill(final,final+26,0);

    fr(i,a.length())
      al[a[i]-'a'] = 1;
    fr(i,b.length())
      bl[b[i]-'a'] = 1;

    fr(i,26)
      if(al[i] != bl[i])
        final[i] = 1;

    fr(i,26){
      if(final[i])
        cout<<alp[i];
    }

    cout<<endl;
  }
  return 0;
}
