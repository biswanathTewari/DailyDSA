#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){ //time : O(N)

    int n;
    cin>>n;

    int a[n];

    int sum = 0,largest = INT_MIN;

    for(int i=0;i<n;i++){

      cin>>a[i];
      sum += a[i];

      largest = max(largest,sum);

      if(sum<0) //if the sum becomes less than 0 , starts fresh
        sum = 0;
    }

    cout<<largest<<endl;

  }

    return 0;
}
