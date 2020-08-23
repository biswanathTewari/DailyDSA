/*variation of LIS : O((3N)^2)*/
#include<bits/stdc++.h>
using namespace std;


struct Box{
  int l;
  int w;
  int h;
};

bool cmp(Box a,Box b){
  return (a.l * a.w) > (b.l * b.w);
}

int maxHeight(int height[],int width[],int length[],int n){

  Box b[3*n];
  int index = -1;

  //making diff dimensions
  for(int i=0;i<n;i++){

    //first dimension
    index++;
    b[index].l = max(length[i],width[i]);
    b[index].w = min(width[i],length[i]);
    b[index].h = height[i];

    //second dimension
    index++;
    b[index].h = width[i];
    b[index].l = max(height[i],length[i]);
    b[index].w = min(height[i],length[i]);

    //third dimensions
    index++;
    b[index].h = length[i];
    b[index].l = max(width[i],height[i]);
    b[index].w = min(width[i],height[i]);
  }

  sort(b,b+(3*n),cmp);

  int value[n*3];

  //baseCase
  for(int i=0;i<n*3;i++){
    value[i] = b[i].h; //considering only one element , highest height  
  }

  int mx = INT_MIN;

  for(int i=0;i<n*3;i++){
    for(int j=i-1;j>=0;j--){

      if(b[j].l > b[i].l && b[j].w > b[i].w)
        value[i] = max(value[i],value[j]+b[i].h);

      mx = max(mx , value[i]);

    }
  }

  return mx;

}

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;


 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}

return 0;

}
