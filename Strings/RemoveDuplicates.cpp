#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;
  cin.ignore(); //flushes the buffer

  while(t--){ //time : O(N) , space : O(1)

    string s;
    getline(cin,s);

    int count = 0; //its like maintaing array of size 25 , with count at index as 0

    for(auto i:s){
      int x = i - 'a';

      if((count & (1<<x)) == 0){ //left shift the "0......00001" x times
        cout<<i;
        count = count | (1<<x);
      }
    }

    cout<<endl;

  }

  return 0;
}
