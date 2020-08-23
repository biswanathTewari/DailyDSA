#include<bits/stdc++.h>
using namespace std;


bool cmp(string a,string b){

  string ab = a+b; //putting a first then b
  string ba = b+a; //putting b first then a

  return  (stoi(ab) > stoi(ba)); //converting them to number , then comparing

}


void formLargestNumber(vector<string> v,int n){ //time : O(N log N)

  sort(v.begin(),v.end(),cmp);

  for(auto i: v) //printing out the largest combination
    cout<<i;

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    vector<string> v;

    for(int i=0;i<n;i++){
      string x;
      cin>>x;
      v.push_back(x);
    }

    formLargestNumber(v,n);
    cout<<endl;

  }


  return 0;
}
