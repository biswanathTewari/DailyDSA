#include<bits/stdc++.h>
using namespace std;


void stockBuySell(int a[],int n){ //time : O(N) , space : O(1)

  int i = 0;
  int f = 1;
  int buy,sell;

  while(i < n){

    //buying the stock
    while(i < n-1 && a[i]>=a[i+1]) //untill the future price is seen increasing,then buy the current
      i++;

    if(i == n-1) //no optimal buying scene
      break;

    buy = i;

    //selling the stock
    i++;

    while(i<n && a[i-1]<=a[i]) //untill the current price is seen decreasing, then sell the previous
      i++;

    sell = i - 1;

    f = 0;

    cout<<"("<<buy<<" "<<sell<<")"<<" ";

  }

  if(f)
    cout<<"No Profit";
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

    stockBuySell(a,n);

    cout<<endl;

  }

  return 0;

}
