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
    ll n,m,k;
    cin>>n>>m>>k;
    unordered_map<ll,ll> mp;
    vll v;
    fr(i,n){
      ll x;
      cin>>x;
      mp[x]=1;
    }
    fr(i,m){
      ll x;
      cin>>x;
      if(mp.find(x)!=mp.end() && mp[x] == 1)
        mp[x] = 2;
    }
    fr(i,k){
      ll x;
      cin>>x;
      if(mp.find(x)!=mp.end() && mp[x] == 2)
        mp[x] = 3;
    }

    for(auto it = mp.begin();it!=mp.end();it++)
      if(it->second == 3)
        v.pb(it->first);
    if(v.size()){
      fr(i,v.size())
        cout<<v[i]<<" ";
    }
    else cout<<-1<<" ";
    cout<<endl;
  }
  return 0;
}
/*void bizan(ll arr[], ll n, ll k)
{
    // map to store sum and indexes for
    // a pair sum
    unordered_map<ll, vector<pair<ll, ll> > > hash;
    vector<vector<ll>> q;

    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {

            // calculate the sum of each pair
            ll sum = arr[i] + arr[j];

            // if k-sum exist in map
            if (hash.find(k - sum) != hash.end()) {
                auto num = hash.find(k - sum);
                vector<pair<ll, ll> > v = num->second;

                // check for index coincidence as if
                // there is a common that means all
                // the four numbers are not from
                // different indexes and one of the
                // index is repeated
                for (ll k = 0; k < num->second.size(); k++) {

                    pair<ll, ll> it = v[k];

                    // if all indexes are different then
                    // it means four number exist
                    // set the flag and break the loop
                    if (it.first != i && it.first != j &&  it.second != i && it.second != j){
                      vll sam ;
                      sam.pb(arr[it.first]);
                      sam.pb(arr[it.second]);
                      sam.pb(arr[i]);
                      sam.pb(arr[j]);
                      sort(sam.begin(),sam.end());
                      q.pb(sam);
                    }
                }
            }

            // store the sum and index pair in hashmap
            hash[sum].push_back(make_pair(i, j));
        }
    }

    if(q.size()){
      fr(i,q.size()){
        fr(j,4)
          cout<<q[i][j]<<" ";
        cout<<"$";
      }
    }
    else cout<<-1;

    hash.clear();
}*/
