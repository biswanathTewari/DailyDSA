#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    sort(a,a+n);

    int count = 0;

    for(int k=n-1;k>=2;k--){ //time : O(N^2)

      int l = 0;
      int r = k-1; //using two pointers

      while(l < r){

        if(a[l] + a[r] == a[k]){
          count++;
          r--;
          l++; //looking for other combos
          //break;
        }
        else if(a[l]+a[r] > a[k])
          r--;
        else l++;

      }

    }

    if(count)
      cout<<count<<endl;
    else cout<<-1<<endl;

  }

  return 0;
}
