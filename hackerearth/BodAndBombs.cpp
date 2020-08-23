/*HackerEarth : Bob And Bomb : bizan7X*/
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)


int main(){
  fast;
  int t;
  cin>>t;
  while(t--){

    string s;
    cin>>s;

    int which[s.length()]; //to store the bombs and walls
    int j=0;

    map<int,int> mp; //to store the positions of the bombs

    for(auto i :s){
      if(i == 'W')
        which[j] = 1;
      else {
        which[j] = 0;
        mp[j] = 1;
      }

      j++;
    }

    int count = 0;

    for(auto it = mp.begin(); it != mp.end() ; it++){
      int pos = it->first;

      if(pos - 2 >= 0){ //two steps back from the bomb
        if(which[pos-2] == 1){
          count++;
          which[pos-2] = -1;
        }
      }

      if(pos - 1 >= 0){ //one step back from the bomb
        if(which[pos-1] == 1){
          count++;
          which[pos-1] = -1;
        }
      }

      if(pos + 1 < s.length()){ //one step forward from the bomb
        if(which[pos+1] == 1){
          count++;
          which[pos+1] = -1;
        }
      }

      if(pos + 2 < s.length()){ //two steps forward from the bomb
        if(which[pos+2] == 1){
          count++;
          which[pos+2] = -1;
        }
      }

    }

    cout<<count<<endl;

  }

  return 0;
}
