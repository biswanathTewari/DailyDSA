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


void bizan(ll a[],ll n){
  priority_queue<ll> small;
  priority_queue<ll,vector<ll>,greater<ll>> large;

  ll prev = a[0];
  small.push(a[0]);
  cout<<prev<<endl;

  fr1(i,1,n,1){
    if(small.size() > large.size()){
      if(a[i]<prev){
        large.push(small.top());
        small.pop();
        small.push(a[i]);
      }
      else large.push(a[i]);
      prev = floor((small.top()+large.top())/2);
    }
    else if(small.size() == large.size()) {
      if(a[i] < prev)
        small.push(a[i]);
      else large.push(a[i]);
      prev = (small.size() > large.size())? small.top() : large.top();
    }
    else {
      if(a[i] > prev){
        small.push(large.top());
        large.pop();
        large.push(a[i]);
      }
      else small.push(a[i]);
      prev = floor((small.top()+large.top())/2);
    }

    cout<<prev<<endl;
  }
}


int main(){
  fast;
  ll n;
  cin>>n;
  ll a[n];
  fr(i,n)
    cin>>a[i];
  bizan(a,n);
  return 0;
}


/*fr(i,n){
    //1 add
    if(large.empty() || a[i]<large.top())
      large.push(a[i]);
    else small.push(a[i]);

    //2 balance
    ll s = small.size();
    ll l = large.size();
    if(abs(l-s)>1)
      if(s>l){
        large.push(small.top());
        small.pop();
        s--;
        l++;
      }
      else{
        small.push(large.top());
        large.pop();
        l--;
        s++;
      }

    //3 median
    if(s == l)
      b[i] = floor((small.top()+large.top())/2);
    else b[i] = (s>l)? small.top() : large.top();
}*/
