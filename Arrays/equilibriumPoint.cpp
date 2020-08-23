#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n];
    cin>>a[0];

    for(int i=1;i<n;i++){
      cin>>a[i];
      a[i]+=a[i-1]; //performing prefix sum
    }

    int f = 0,equ = 0;

    if(n == 1){
      equ = 1;
      f = 1;
    }
    else{

      for(int i=1;i<n;i++)
        if(a[i-1] == (a[n-1]-a[i])){ //if left sum == right sum
          equ = i+1;
          f = 1;
          break;
        }

    }

    if(f)
      cout<<equ<<endl;
    else cout<<-1<<endl;
  }

  return 0;
}
