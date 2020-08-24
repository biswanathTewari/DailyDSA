/*
https://practice.geeksforgeeks.org/problems/non-repeating-character/0
DailyDSA: biZan7X
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;
    char s[n];
    int a[26] = {0};

    for(int i=0;i<n;i++){
      cin>>s[i];
      a[s[i]-'a']++;
    }

    char ch = '#';

    for(int i=0;i<n;i++)
      if(a[s[i]-'a'] == 1){
        ch = s[i];
        break;
      }

    if(ch == '#')
      cout<<-1<<endl;
    else cout<<ch<<endl;

  }

  return 0;
}
