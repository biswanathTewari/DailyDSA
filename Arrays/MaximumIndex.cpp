#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main(){

  fast;

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    ll a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    int res = 0;

    for(int i=0;i<n;i++){
      for(int j=n-1;j>i;j--){

        if(a[i]<=a[j]){
          res = max(res,j-i);
          break;
        }

      }
    }

    cout<<res<<endl;

  }

  return 0;
}
