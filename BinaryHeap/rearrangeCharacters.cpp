#include<bits/stdc++.h>
using namespace std;


struct key{

  int freq;
  char ch;

  bool operator<(const key &k) const { //works as a comparator
    return freq < k.freq;
  }

};


int rearrange(string s){

  priority_queue<key> pq; //max heap for storing the chars

  int count[26]; //to count the chars
  fill(count,count+26,0);

  int n = s.length();

  for(int i=0;i<n;i++)
    count[s[i]-'a']++;

  for(char i = 'a'; i<='z'; i++)
    if(count[i - 'a'])
      pq.push(key {count[i - 'a'],i});

  string ns = ""; //new string

  key prev {-1,'#'}; //to break the continous printing of the max freq chars

  while(!pq.empty()){

    key a = pq.top();
    pq.pop();

    ns += a.ch;

    if(prev.freq > 0)
      pq.push(prev);

    a.freq--;
    prev = a;

  }

  if(ns.length() == n)
    return 1;
  else return 0;

}


int main(){
  int t;
  cin>>t;

  while(t--){

    string s;
    cin>>s;
    cout<<rearrange(s)<<endl;

  }

  return 0;
}
