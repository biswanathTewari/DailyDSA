// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
        if(findTriplets(arr, n))
        cout<<"1"<<endl;
        else
        cout<<"0"<<endl;
	}
    return 0;
}// } Driver Code Ends


/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findTriplets(int nums[], int n) /*variation of two pointers : time: O(N^2) , space : O(1)*/
{
        sort(nums,nums+n);


        //int prev = INT_MAX;

        for(int i=0;i<n-2;i++){

            //if(nums[i] == prev)
               // continue;

            int cur = nums[i];

            int start = i+1;
            int end = n-1;


            while(start < end){

                if(cur + nums[start] + nums[end] == 0 && start < end){
                    return 1;
                }

                else if(cur + nums[start] + nums[end] > 0){
                    end--;
                }

                if(cur + nums[start] + nums[end] < 0){
                    start++;
                }
            }

            //prev = nums[i];
        }

        return 0;
}
