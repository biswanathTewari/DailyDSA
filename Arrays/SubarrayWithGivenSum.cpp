#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    int n,sum;
    cin>>n>>sum;

    int b[n],a[n+1];

    a[0] = 0;

    for(int i=0;i<n;i++){
      cin>>b[i];
      a[i+1]=a[i]+b[i]; //making a prefix sum array with first element as zero
    }

    int l=0,r=1,f=0;

    while(l<=r && r<=n){

      if(a[r] - a[l] == sum){ //applying the two pointers concept
        f = 1;
        break;
      }
      else if(a[r] - a[l] < sum)
        r++;
      else l++;

    }

    if(f)
      cout<<l+1<<" "<<r<<endl;
    else cout<<-1<<endl;

  }

  return 0;

}
