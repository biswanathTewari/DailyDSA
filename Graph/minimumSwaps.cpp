/*
Algorithm : like an undirected graph cycle detection , we keep looking to the vertexes which are not in place,
untill we face a visited vertex back again, we call that a cycle of misplaced vertexs , we count the cycles , and
we add the cycles-1 to the no of swaps.(the cycle is specificly for those misplaced vertex, there might be more cycles
for the other unvisited misplaced cycles)
*/

#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends

/* You are required to complete this method */

bool cmp(pair<int,int> a,pair<int,int> b){
  return a.second < b.second ;
}

int minSwaps(int a[], int n){

  int swaps = 0;

  int vis[n];
  fill(vis,vis+n,0);

  vector<pair<int,int>>  v;

  for(int i=0;i<n;i++)
    v.push_back(make_pair(i,a[i]));

  sort(v.begin(),v.end(),cmp);

  for(int i=0;i<n;i++){

    if(vis[i] == 1 || v[i].first == i){
      vis[i] = 1;
      continue;
    }

    int next = i;
    int cycles = 0;
    while(vis[next] == 0){
      vis[next] = 1;
      next = v[next].first;
      cycles++;
    }

    if(cycles != 0)
      swaps+=cycles-1;
  }

  return swaps;
}
