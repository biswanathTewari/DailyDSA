#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    map<string,int> mp;
    int mx = 0, second = 0; //max freq , second most freq

    for(int i=0;i<n;i++){
      string s;
      cin>>s;

      if(mp.find(s) == mp.end()) //it the string does not exits in the map
        mp[s] = 1;
      else mp[s]++;

      mx = max(mx,mp[s]);
    }

    string s;

    for(auto it = mp.begin();it != mp.end();it++){
      int freq = it->second;
      if(second < freq && freq != mx){ //looking for the highest freq string after mx
        s = it->first;
        second = freq;
      }
    }

    cout<<s<<endl;

  }

  return 0;
}
