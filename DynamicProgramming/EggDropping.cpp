#include<bits/stdc++.h>
using namespace std;


int ED(int e,int f){

  //baseCase
  if(e == 1)//we need to check each floor from bottom to up
    return f;

  if(f == 0 || f == 1)
    return f;


  int mn = INT_MAX;

  for(int k = 1;k<=f;k++){

    int broke = ED(e-1,k-1);
    int unbroke = ED(e,f-k);//check remaining floors
    int temp = max(broke,unbroke) + 1;

    mn = min(mn,temp);

  }

  return mn;
}


int main(){
  int t;
  cin>>t;
  while(t--){

    int e,f;

    cin>>e>>f;

    cout<<ED(e,f)<<endl;

  }

  return 0;
}
