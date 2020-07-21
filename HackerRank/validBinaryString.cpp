/*biZan7X*/
#include<bits/stdc++.h>
using namespace std;

int main(){

  string s;
  cin>>s;

  int d;
  cin>>d;

  string rev = s;
  int range = -1;

  //flow -->
  for(int i=0;i<s.length();i++){

    if(s[i] == '1'){
      range = i + d - 1;
    }
    else if(i <= range){
      s[i] = '1';
    }

  }

  range = s.length();
  //flow : <--
  for(int i=s.length()-1;i>=0;i--){

    if(rev[i] == '1'){
      range = i - d + 1;
    }
    else if(i >= range){
      rev[i] = '1';
    }

  }

  vector<int> zeroes;
  int count = 0;

  for(int i=0;i<s.length();i++){
    if(s[i] == '0' && rev[i] == '0'){
      zeroes.push_back(i);
      //cout<<i<<" ";
    }
  }

  int prev = 1;
  zeroes.push_back(-1);

  for(int i=1;i<zeroes.size();i++){
    if(zeroes[i] - zeroes[i-1] == 1){
      prev++;
    }
    else{
      if(prev <= d)
        count++;
      else count += floor(prev/d);

      prev = 1;
    }
  }

  /*int m = count;
  count = 0;
  range = s.length();
  for(int i=zeroes.size()-1;i>=0;i--){
    if(range > zeroes[i]){
      range = zeroes[i] - d + 1;
      count++;
    }
  }*/

  cout<<count<<endl;

  return 0;
}
