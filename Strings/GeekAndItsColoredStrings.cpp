/*
https://practice.geeksforgeeks.org/problems/geek-and-its-colored-strings/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll fact[21];

void factorials(){

  fact[0] = 1;

  for(int i=1;i<=20;i++)
    fact[i] = i * fact[i-1];

}

int main(){

  int t;
  cin>>t;
  factorials();

  while(t--){

    ll n,r,g,b;
    cin>>n>>r>>g>>b;

    ll left = n - r - g - b;
    ll combo = 0;

    for(int i=0;i<=left;i++){
      for(int j=0;j<=left;j++){
        ll k = left - i - j;
        if(k >= 0){
          ll R = r + i;
          ll G = g + j;
          ll B = b + k;
          combo += fact[n]/(fact[R]*fact[G]*fact[B]);
        }
      }
    }

    cout<<combo<<endl;

  }

  return 0;
}
