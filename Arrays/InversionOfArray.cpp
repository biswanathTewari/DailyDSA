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

ll sum;

void merge(ll a[],ll left, ll mid, ll right){
  ll nl=mid-left+1;
  ll nr=right-mid;
  ll i=0,j=0,k=left;
  ll l[nl],r[nr];
  fr(g,nl)
    l[g]=a[g+left];
  fr(g,nr)
    r[g]=a[g+mid+1];
  while(i<nl && j<nr){
    if(l[i]<=r[j]){
      a[k++]=l[i++];
    }
    else{
      sum+=nl-i;
      a[k++]=r[j++];
    }
  }
  while(i<nl)
    a[k++]=l[i++];
  while(j<nr)
    a[k++]=r[j++];
}

void mergesort(ll a[],ll left,ll right){
  if(left<right){
    ll mid=left+(right-left)/2;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);

    merge(a,left,mid,right);
  }
}

int main(){
  ll t;
  cin>>t;
  w(t){
    ll n;
    sum=0;
    cin>>n;
    ll a[n];
    fr(i,n)
      cin>>a[i];
    mergesort(a,0,n-1);
    cout<<sum<<endl;
  }
  return 0;
}
