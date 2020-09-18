#include<bits/stdc++.h>
using namespace std;
#define lim 11

void SpiralTraversal(int a[lim][lim],int n,int m){ //time : O(N*M) , space : O(1)

  int r = 0;//starting of the row
  int c = 0;//starting of the col

  while(r < n && c < m){

    for(int i=c;i<m;i++) //printing the upper-side
      cout<<a[r][i]<<" ";
    r++;// starting of the row incremented to prevent previous values

    for(int i=r;i<n;i++)//printin the right-side
      cout<<a[i][m-1]<<" ";
    m--;//end of the  column decresed to prevent previous values

    if(r<n){

      for(int i=m-1;i>=c;i--)//printing the down-side
        cout<<a[n-1][i]<<" ";
      n--;//decreasing the limit of the row

    }

    if(c<m){

      for(int i=n-1;i>=r;i--) //printing the left-side
        cout<<a[i][c]<<" ";
      c++;//increasing the col starting index

    }

  }

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n,m;
    cin>>n>>m;

    int a[11][11];
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>a[i][j];

    SpiralTraversal(a,n,m);
    cout<<endl;

  }

  return 0;
}
