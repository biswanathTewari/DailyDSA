/*
https://practice.geeksforgeeks.org/problems/min-subsets-with-consecutive-numbers/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;


int numofsubset(int a[],int n){ // time : O(N log N) , space : O(1)

  sort(a,a+n);

  int count = 0;
  int prev = a[0];

  for(int i=1;i<n;i++){
    if(a[i] - prev > 1) //counting the consecutive numbers
      count++;

    prev = a[i];
  }

  return count+1; //+1 for the last consecutive set of numbers.

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    cout<<numofsubset(a,n)<<endl;

  }

  return 0;
}
