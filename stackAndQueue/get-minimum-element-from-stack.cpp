// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
   if(s.size())
    return minEle;

   return -1;
}

/*returns poped element from stack*/
int _stack ::pop()
{

  if(s.size() == 0)
    return -1;

  int x = s.top();
  s.pop();

  //if the poping element is the min in the stack
  if(x < minEle){

    int nextMin = 2*minEle - x;
    int k = minEle;
    minEle = nextMin;
    return k;

  }

  return x;

}

/*push element x into the stack*/
void _stack::push(int x)
{

   //if the stack is empty
   if(s.size() == 0){
     s.push(x);
     minEle = x;
   }

   else{

     //if the new element is the new min
     if(x < minEle){
       int k = 2*x - minEle;
       minEle = x;
       s.push(k);
     }
     else{
       s.push(x);
     }
   }
}
