/*
https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


int missing(int a[],int n){ //time : O(N) , space : O(1)

  for(int i=0;i<n;i++){

    if(abs(a[i]) > n) //ignoring the negative and the 0
      continue;

    int index = abs(a[i]);

    if(a[index-1] > 0) //if positive
      a[index-1] *= -1; //marking it as it exists

  }

  for(int i=0;i<n;i++){
    if(a[i] > 0)
      return i+1; //first positive number which is missing
  }

  return n+1; //every number exists till n , then n+1 is missing ovio

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
      cin>>a[i];
      if(a[i] <= 0)
        a[i] = n+1;
    }

    cout<<missing(a,n)<<endl;

  }

  return 0;
}
