//https://codeofgeeks.com/digit-pair/

#include<bits/stdc++.h>
using namespace std;


int msd(int x){

  return x/10;

}


void bitscore(int a[],int n){

  for(int i=0;i<n;i++){

    int sum = 0;

    int first = a[i]%10;
    a[i]/=10;
    int sec = a[i]%10;
    a[i]/=10;
    int third = a[i]%10;
    a[i]/=10;

    int l = max(max(first,sec),third);
    int s = min(min(first,sec),third);

    sum = (l*11) + (s*7);

    if(sum>99){
      first = sum%10;
      sum/=10;
      sec = sum%10;

      a[i] = (sec*10) + first;
    }
    else a[i] = sum;

  }

}


int main(){

  int n;
  cin>>n;

  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];

  bitscore(a,n);

  int msdcount[10] = {0};
  int used[n] = {0};
  int count = 0;

  for(int i=0;i<n;i++){

    if(used[i])
      continue;

    for(int j=i+2;j<n;j+=2){

      int x = msd(a[i]);
      int y = msd(a[j]);

      if(x == y && !used[j] && msdcount[x] != 2){

        count++;
        msdcount[x]++;
        used[i] = 1;
        used[j] = 1;
        //cout<<i<<" "<<j<<endl;
        //break;

      }

    }
  }


  cout<<count<<endl;

  return 0;

}
