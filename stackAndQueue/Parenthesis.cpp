//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
#define stir string
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;

bool isMatch(char a,char b){
  if(a == '[' && b == ']')
    return true;
  else if(a == '{' && b == '}')
    return true;
  else if(a == '(' && b == ')')
    return true;
  return false;
}

bool isBalanced(string p,stack<char> s){
  for(int i=0;i<p.length();i++){
    if(s.empty())
      s.push(p[i]);
    else{
      if(isMatch(s.top(),p[i]))
        s.pop();
      else s.push(p[i]);
    }
  }
  if(s.empty())
    return true;
  return false;
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    string p;
    cin>>p;
    stack<char> s;
    if(isBalanced(p,s))
      cout<<"Balanced"<<endl;
    else cout<<"Not Balanced"<<endl;
  }
  return 0;
}
