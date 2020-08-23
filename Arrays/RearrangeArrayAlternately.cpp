#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

void rearrange(long long int a[],long long int n){ //time : o(N) , space : O(1),
  //arrays are passed by reference internally so no worries of printing

  long long int me = a[n-1] + 1; //max_element
  long long int max_i = n-1;
  long long int min_i = 0;

  //modiying the array to hold two values at a time.. i.e sorted are rearranged values
  for(long long int i=0;i<n;i++){

    if(i%2 == 0){ //meant to holg larger values

      a[i] = a[i] + (a[max_i]%me) * me; //remainder + quotient * divisor
      max_i--;

    }

    else{ //meant to store smaller elements

      a[i] = a[i] + (a[min_i]%me) * me;
      min_i++;

    }

  }

  //yeah ! thats it.... that was it all about ;)
}


int main(){
  fast;

  int t;
  cin>>t;
  while(t--){

    long long int n;
    cin>>n;

    long long int a[n];
    for(long long int i=0;i<n;i++)
      cin>>a[i];

    long long int me = a[n-1] + 1;

    rearrange(a,n);

    for(long long int i=0;i<n;i++)
      cout<<a[i]/me<<" ";

    cout<<endl;

  }

  return 0;
}
