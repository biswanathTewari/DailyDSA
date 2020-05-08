#include<bits/stdc++.h>
using namespace std;

struct key{
  int freq;
  char ch;

  bool operator<(const key &k) const{
    return freq < k.freq;
  }
};

int bizan(string s){
  priority_queue<key> pq;
  int n = s.length();
  int count[26];
  fill(count,count+26,0);
  for(int i=0;i<n;i++)
    count[s[i]-'a']++;
  for(char i='a';i<='z';i++)
    if(count[i-'a'])
      pq.push(key {count[i-'a'],i});
  key prev;
  prev.freq=-1;
  prev.ch='#';
  string str="";
  while(!pq.empty()){
    key a = pq.top();
    pq.pop();
    str+=a.ch;

    if(prev.freq>0)
      pq.push(prev);

    (a.freq)--;
    prev = a;
  }
  if(n == str.length())
    return 1;
  return 0;
}


int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    cout<<bizan(s)<<endl;
  }
  return 0;
}
