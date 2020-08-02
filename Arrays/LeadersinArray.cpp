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

    stack<int> s;
    s.push(a[n-1]);

    for(int i=n-2;i>=0;i--)
      if(a[i] >= s.top())
        s.push(a[i]);

    while(!s.empty()){
      cout<<s.top()<<" ";
      s.pop();
    }

    cout<<endl;

  }

  return 0;
}
