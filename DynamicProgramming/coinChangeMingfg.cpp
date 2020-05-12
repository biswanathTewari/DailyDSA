/*variation of unbouned knapsack*/
#include<bits/stdc++.h>
using namespace std;

void rodCutting(int a[],int l,int n){

  int i = 0;
  while(n && i<l){
    if(a[i] <= n){
      n-=a[i];
      cout<<a[i]<<" ";
      continue;
    }
    i++;
  }

}



int main(){

  int t;
  cin>>t;

  while(t--){

  int n;
  cin>>n;

  int a[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

  sort(a,a+10,greater<int>());

  rodCutting(a,10,n);
  cout<<endl;

  }
  return 0;
}
