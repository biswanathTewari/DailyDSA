#include<bits/stdc++.h>
using namespace std;


void maxofsub(int a[],int k,int n){

  deque<int> d;

  for(int i=0;i<k;i++){ //filling for the first k elements

    while(!d.empty() && a[i] > a[d.back()]) //if the a[i] is greater than the prev elements, we pop the smaller elements , such that only greater values come inthe front side
      d.pop_back();

    d.push_back(i); //to keep an idea abou the position of the element in array , we push just the index
  }

  for(int i=k;i<n;i++){

    cout<<a[d.front()]<<" "; //greatest element among the range of k

    while(!d.empty() && d.front() <= (i - k)) //eliminate the elements whoes position is not greater than (i - k) -> capacity to hold
      d.pop_front();

    while(!d.empty() && a[i] > a[d.back()]) //repeating line number: 11
      d.pop_back();

    d.push_back(i);
  }

  if(!d.empty())
    cout<<a[d.front()];

}


int main(){

  int t;
  cin>>t;

  while(t--){

    int n,k;
    cin>>n>>k;

    int a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    maxofsub(a,k,n);
    cout<<endl;

  }

  return 0;
}
