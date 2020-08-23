//https://codeofgeeks.com/swayamvar/

#include<bits/stdc++.h>
using namespace std;


int main(){

  int n;
  cin>>n;

  string bride , groom ;
  cin>>bride>>groom;

  deque<char> q;

  for(auto i:groom)
    q.push_back(i);


  int j;
  for(j = 0;j<bride.length();j++){

    char i = bride[j];
    int c = 0;

    while(c != q.size() && i != q.front()){

      char x = q.front();
      q.pop_front();
      q.push_back(x);
      c++;

    }

    if(c == q.size())
      break;

    q.pop_front();

  }


  cout<<n-j<<endl;


  return 0;

}
