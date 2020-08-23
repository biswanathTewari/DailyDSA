#include<bits/stdc++.h>
using namespace std;


int BP(string a,int i,int j,int tb){

  //baseCase
  if(i>j)//no chars
    return 0;

  if( i == j){//if only one element
    if(tb  == 1)//what we need is true value
      return (a[i] == 'T')? 1 : 0;
    else return (a[i] == 'F')? 1 : 0;
  }


  //partionFinding
  int ans = 0;
  for(int k=i+1;k<j;k++){

    int lt = BP(a,i,k-1,1);//if the left side is true
    int lf = BP(a,i,k-1,0);//if the left side is false
    int rt = BP(a,k+1,j,1);//if the right side is true
    int rf = BP(a,k+1,j,0);//if the right side is false

    if(a[k] == '|'){
      if(tb == 1)
        ans += lt * rt + lf * rt + lt * rf; //counting total ways if we need true
      else ans += lf * rf ;//if we need false
    }

    if(a[k] == '&'){
      if(tb == 1)
        ans += lt * rt;
      else ans += lf * rf + lt * rf + lf * rt;
    }

    if(a[k] == '^'){
      if(tb == 1)
        ans += lf * rt + lt * rf ;
      else ans += lt * rt + lf * rf;
    }

  }

  return ans ;

}


int main(){
  int t;
  cin>>t;

  while(t--){

    int n;
    cin>>n;

    string a;
    cin>>a;

    cout<<BP(a,0,n-1,1)<<endl;

  }

  return 0;
}
