#include<bits/stdc++.h>
using namespace std;


int minimumSteps(int cs, int num,int a[]){

    if(a[cs]!=-1)
      return a[cs];

    if(cs == 0)
      a[cs] = 1+minimumSteps(cs+1,num,a);

    if(cs>num)
      return INT_MAX;

    if(cs == num)
      return 0;

    a[cs] = min(minimumSteps(cs+1,num,a),minimumSteps(cs*2,num,a)) + 1;

    return a[cs];
}


int main(){

    int t;

    cin>>t;

    while(t--){

      int n;
      cin>>n;

      int a[n*2];

      fill(a,a+(n*2),-1);

      cout<<minimumSteps(0,n,a)<<endl;


    }

    return 0;
}
