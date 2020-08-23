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
    string str,txt,s;
    cin>>str>>txt;

    ll hp[26],hs[26];
    fill(hs,hs+26,0);
    fill(hp,hp+26,0);

    fr(i,txt.length())
      hp[txt[i]-'a']++;

    ll min = INT_MAX;
    ll first = -1;
    ll i = 0;
    ll count = 0;
    ll flag = 0;

    fr(j,str.length()){

      hs[str[j]-'a']++;
      if(hs[str[j]-'a'] <= hp[str[j]-'a'])
        count++;

      if(count == txt.length()){

        while(hs[str[i]-'a'] > hp[str[i]-'a']){
          hs[str[i]-'a']--;
          i++;
        }

        if(min > j-i+1){
          min = j-i+1;
          first = i;
          flag = 1;
        }
      }
    }

    if(flag)
        cout<<str.substr(first,min)<<endl;
    else cout<<-1<<endl;

  }
  return 0;
}
