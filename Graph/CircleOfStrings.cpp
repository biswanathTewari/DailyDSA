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
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;


void DFS(vector<int> g[M],vector<int> &vis,int index){

  vis[index] = 1;


  for(int i=0;i<g[index].size();i++){
      if(!vis[g[index][i]])
        DFS(g,vis,g[index][i]);
  }

}


bool isConnected(vector<int> g[M],vector<int> mark,int index){

  vector<int> vis(M,0);

  DFS(g,vis,index);

  for(int i=0;i<M;i++)
    if(mark[i] != vis[i])
      return false;

  return true;
}


bool isCycle(string s[],int n){

  vector<int> g[M];

  vector<int> mark(M,0);

  vector<int> in(M,0),out(M,0);

  for(int i=0;i<n;i++){

    int f = s[i].front() - 'a';
    int l = s[i].back() - 'a';

    mark[f] = 1;
    mark[l] = 1;

    in[l]++;
    out[f]++;

    g[f].pb(l);

  }


  for(int i=0;i<M;i++)
    if(in[i] != out[i])
        return false;

  return isConnected(g,mark,s[0].front() - 'a');

}



int main(){
  fast;
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;

    string s[n];

    for(int i=0;i<n;i++)
      cin>>s[i];

    cout<<isCycle(s,n)<<endl;
  }
  return 0;
}
