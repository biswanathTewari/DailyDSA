//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
#define stir string
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;


void median(ll a[],ll n){

  priority_queue<ll> small; //contains the small elements or the first half : max_heap
  priority_queue<ll,vector<ll>,greater<ll>> large; //conatins the larger elements or the second half : min_heap

  ll prev = a[0];
  small.push(a[0]);

  cout<<prev<<endl;

  for(int i=1;i<n;i++){

    // case1(left side heap has more elements)
    if(small.size() > large.size()){

      if(a[i]<prev){

        large.push(small.top());
        small.pop();
        small.push(a[i]);

      }
      else large.push(a[i]);

      prev = floor((small.top()+large.top())/2); //even so median = average of the middle two elements
    }


    // case2(both heaps are balanced)
    else if(small.size() == large.size()) {

      if(a[i] < prev)
        small.push(a[i]);
      else large.push(a[i]);

      prev = (small.size() > large.size())? small.top() : large.top(); //odd so the middle element
    }


    // case3(right side heap has more elements)
    else {

      if(a[i] > prev){

        small.push(large.top());
        large.pop();
        large.push(a[i]);

      }
      else small.push(a[i]);

      prev = floor((small.top()+large.top())/2); //even so median = average of the middle two elements
    }

    cout<<prev<<endl;
  }
}


int main(){

  fast;

  ll n;
  cin>>n;
  ll a[n];

  fr(i,n)
    cin>>a[i];

  median(a,n);

  return 0;
}


/* SECOND METHOD-----------------------------------------------------------------------------------------------------------------

void median(int a[],int n){

  priority_queue<int> small; //contains the small elements or the first half : max_heap
  priority_queue<int,vector<int>,greater<int>> large; //conatins the larger elements or the second half : min_heap

  int mid = a[0];
  small.push(mid);
  cout<<mid<<endl;

  for(int i=1;i<n;i++){

    // 1 -> adding elements
    if(large.empty() || a[i] > large.top()) //element a[i] is greater than the smallest element of the 'large' priority_queue
      large.push(a[i]);
    else small.push(a[i]);

    int l = large.size();
    int s = small.size();

    //2 -> maintaing the balance
    if(abs(s - l) > 1){
      if(l > s){
        small.push(large.top()); //sending the smallest element of the large to small
        large.pop();
        l--;
        s++;
      }
      else{
        large.push(small.top()); //sending the largest element of the small to large
        small.pop();
        s--;
        l++;
      }
    }

    //finding the current median
    if(s == l) //if even , both sides are equal
      mid = floor((small.top() + large.top()) / 2 ); //average of the middle two elements
    else mid = (s > l)? small.top() : large.top(); //middle single element in the case of odd

    cout<<mid<<endl;

  }

}

*/
