#include<bits/stdc++.h>
using namespace std;


int leftRight(int a[],int n){ // time : O(N)

  int leftmax[n]; //max flow from left
  int rightmin[n]; //min flow from right

  leftmax[0] = a[0];
  rightmin[n-1] = a[n-1];

  for(int i=1;i<n;i++)
    leftmax[i] = max(leftmax[i-1],a[i]);

  for(int i=n-2;i>=0;i--)
    rightmin[i] = min(rightmin[i+1],a[i]);

  for(int i=1;i<n-1;i++) //0 and n-1 not included , since we want a middle to left and right
    if(leftmax[i] == rightmin[i]) //first number to match was in position
      return a[i];

  return -1;

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

    cout<<leftRight(a,n)<<endl;

  }

  return 0;
}
