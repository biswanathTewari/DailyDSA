#include<bits/stdc++.h>
using namespace std;


void nonrepeat(char ch[],int n){

  int freq[26]; //stores the frequncy of the chars
  fill(freq,freq+26,0);

  list<char> l; //since queue does not supports erase() , using list as its alternative
  list<char> :: iterator b[26]; //to store the position of the chars in the queue

  for(int i=0;i<n;i++){

    int x = ch[i] - 97;

    //if unique element
    if(freq[x] == 0){

      freq[x]++;
      l.push_back(ch[i]);
      b[x] = l.end();
      b[x]--; //stores the iterator position to char ch[i] in the list

    }

    //if duplicate char
    else if(freq[x] == 1){

      l.erase(b[x]);
      freq[x]++;

    }

    //else if the freq is greater than 1 do nothing , its duplicate which does not exists in the list anymore

    if(l.empty())
      cout<<-1<<" ";
    else cout<<l.front()<<" ";

  }

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    char ch[n];

    for(int i=0;i<n;i++)
      cin>>ch[i];

    nonrepeat(ch,n);
    cout<<endl;

  }

}
