#include<bits/stdc++.h>
using namespace std;

int main(){

   int t;
   cin>>t;

   while(t--){

     string a,b;
     cin>>a>>b;

     int n = b.length();
     string r = b.substr(n-2,2) + b.substr(0,n-2);
     string l = b.substr(2,n-2) + b.substr(0,2);

     if(a == r || a == l)
      cout<<1<<endl;
    else cout<<0<<endl;


   }

  return 0;
}
