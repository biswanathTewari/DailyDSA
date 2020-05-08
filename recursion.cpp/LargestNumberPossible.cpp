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

vector<string> v;
ll a[10] = {0,1,2,3,4,5,6,7,8,9};
char b[10] = {'0','1','2','3','4','5','6','7','8','9'};

void combinations(ll index,ll n,ll s,ll cursum,string sam){

  if(cursum == s && sam.length() == n)
  {
    v.pb(sam);
    return;
  }

  if(cursum >= s)
    return ;
  if(sam.length() >= n )
    return;

  for(ll i=index;i<10;i++){
    cursum+=a[i];
    sam.push_back(b[i]);
    combinations(index+1,n,s,cursum,sam);
    sam.pop_back();
    cursum-=a[i];
  }
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n,s;
    cin>>n>>s;
    v.clear();
    string sam;

    combinations(0,n,s,0,sam);

    //sort(v.begin(),v.end(),greater<string>());

    if(v.size() > 0){
      fr(i,v.size())
        cout<<v[i]<<" ";
      cout<<endl;
    }
    else cout<<-1<<endl;

  }
  return 0;
}
