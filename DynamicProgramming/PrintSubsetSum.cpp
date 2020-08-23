//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int (i) = 0; (i) <(n) ; (i)=(i+1))
#define fr1(j,a,b,c) for(int (j) = a; (j) <b ; (j)=(j+c))


bool dp[1000][1000]; //global : change accordingly


void display(vector<int> p){

  for(auto i:p)
    cout<<i<<" ";

  cout<<endl;

}


void printSubsets(int a[],int i,int sum,vector<int>& p){

  //baseCases
  //if only one element is left
  if(i == 1 && sum != 0 && dp[i][sum]) //this means that the only element is equal to the sum
  {
    p.push_back(a[i-1]);
    display(p);
    return;
  }

  //if the sum becomes zero
  if(sum == 0 && i == 1){
    display(p);
    return;
  }

  //choicePrograms

  //if we ignore the current element
  if(dp[i-1][sum]){
    vector<int> b = p;
    printSubsets(a,i-1,sum,b);
  }


  //considering the current element
  if(sum >= a[i-1] && dp[i-1][sum-a[i-1]]){
    p.push_back(a[i-1]);
    printSubsets(a,i-1,sum-a[i-1],p);
  }


}


void subsetSum(int a[],int n,int sum){

  //base case
  fr(i,n+1)
    fr(j,sum+1){
      //if there are no elements left
      if(i == 0)
        dp[i][j] = false;

      //if the sum is 0
      if(j == 0)
          dp[i][j] = true;
    }

  //choice program
  fr1(i,1,n+1,1)
    fr1(j,1,sum+1,1){

    if(a[i-1] > j)
      dp[i][j] = dp[i-1][j];
    else dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j] ;

    }


    if(!dp[n][sum]){
      cout<<"Not Possible"<<endl;
      return ;
    }
    //cout<<"possible"<<endl;

    vector<int> p; //to store the combinations , will be referenced
    printSubsets(a,n,sum,p);
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n,sum;
    cin>>n;

    int a[n];

    fr(i,n){
      cin>>a[i];
    }

    cin>>sum;

    memset(dp,-1,sizeof(dp));

    subsetSum(a,n,sum);

    }

  return 0;
}
