#include <bits/stdc++.h>
using namespace std;


int bs(int a[],int n,int left,int right){ // time : O(log N) , space  : O(1)

    int mid;

    if(left <= right){

        mid =  left + (right - left)  / 2;

        if(mid > 0  && mid < n-1){

            if(a[mid] != a[mid - 1] && a[mid] != a[mid + 1]){
                cout<<a[mid];
                return 1;
            }
        }

        else if(mid == 0 && a[mid] != a[mid+1]){ //corner
                cout<<a[mid];
                return 1;
        }

        else if(mid == n-1 && a[mid] != a[mid-1]){ //corner
            cout<<a[mid];
            return 1;
        }


        //checking the left side of mid
        if(bs(a,n,left,mid-1))
          return 1;                     //uisng the boolean to avoid running both the recursions
        //checking the right side of mid
        if(bs(a,n,mid+1,right))
          return 1;

    }

    return 0;
}

int main() {

	int t;
	cin>>t;

	while(t--){

	    int n;
	    cin>>n;

	    int a[n];

	    for(int i=0;i<n;i++)
	        cin>>a[i];

	    //binarySearch
	    bs(a,n,0,n-1);

	   cout<<endl;

	}

	return 0;
}
