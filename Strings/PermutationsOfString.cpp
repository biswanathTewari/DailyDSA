/*

next_permutation(begining of array or vectors,end of array or vector) -> it is present in the STL, which gives us the next permutation
in place , i.e., does not takes up extra space.
prev_permutation -> similar to next_permutation , it just that it gives the pervious permutation
checkout more on GFG

*/

#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){ //time : O(N!) , where n is the size of the string, next_permutation takes O(1) * the number of times the do while will run O(N!)[since n distinct elements have N! arrangments]

    string s;
    cin>>s;

    do{

      cout<<s<<" ";

    }while(next_permutation(s.begin(),s.end()));

    cout<<endl;

  }

  return 0;
}

/--------- second method ---------------------------------------------------------------------------------------


void permute(string s,int index,int end,vector<string> &v){ //basic recursion

  if(index == end){
    v.push_back(s); //adding the different arrangments in a vector
    return;
  }

  for(int i=index;i<=end;i++){

    swap(s[i],s[index]); //in place swapping
    permute(s,index+1,end,v);
    swap(s[i],s[index]);

  }

  return;
}

//sort the vector and print
