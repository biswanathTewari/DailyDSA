#include<bits/stdc++.h>
using namespace std;


int GCD(int a,int b){

  if(a == 0)
    return b;

  return GCD(b%a,a);

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;
    int a[n],sum;

    for(int i=0;i<n;i++)
      cin>>a[i];

    if(n == 1)
      cout<<a[0]<<endl;
    else{
      sum = GCD(a[0],a[1]);

      for(int i=2;i<n;i++)
        sum = GCD(sum,a[i]);

      cout<<sum<<endl;
    }

  }

  return 0;
}
