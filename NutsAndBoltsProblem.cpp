/*
https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    char x;
    cin>>n;

    char ch[9] = {'!','#','$','%','&','*','@','^','~'};

    map<char,int> nuts;
    map<char,int> bolts;

    for(int i=0;i<n;i++){
      cin>>x;
      nuts[x] = 1;
    }

    for(int i=0;i<n;i++){
      cin>>x;
      bolts[x]=1;
    }

    for(int i=0;i<9;i++){
      x = ch[i];

      if(nuts.find(x) != nuts.end() && bolts.find(x) != bolts.end())
        cout<<x<<" ";
    }
    cout<<endl;

    for(int i=0;i<9;i++){
      x = ch[i];

      if(nuts.find(x) != nuts.end() && bolts.find(x) != bolts.end())
        cout<<x<<" ";
    }
    cout<<endl;

  }

  return 0;
}
