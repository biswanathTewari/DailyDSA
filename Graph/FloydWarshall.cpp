//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define M 26
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
#define str string
#define nll nector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define fren(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;
#define V 100


void printg(ll dis[V][V],ll n){

  fr(i,n){
    fr(j,n){
      if(dis[i][j] >= 10000000)
        cout<<"INF"<<" ";
      else cout<<dis[i][j]<<" ";
    }
    cout<<endl;
  }

}

void floydWarshall(ll g[V][V],ll n){

  ll dis[V][V];

  fr(i,n){
    fr(j,n){
      dis[i][j] = g[i][j];
    }
  }


  fr(k,n){
    fr(i,n){
      fr(j,n){
        if(dis[i][j] > dis[i][k]+dis[k][j])
          dis[i][j] = dis[i][k] + dis[k][j];
      }
    }
  }


  printg(dis,n);
}



int main(){
  fast;
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;

    ll g[V][V];

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        string x;
        cin>>x;

        if(x == "INF")
          g[i][j] = INT_MAX;
        else g[i][j] = stoi(x);
      }
    }

    floydWarshall(g,n);

  }

  return 0;
}
