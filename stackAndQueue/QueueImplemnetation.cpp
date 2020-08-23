#include<bits/stdc++.h>
using namespace std;

struct queuenode{
  int data;
  queuenode* next;
  queuenode(int val){
    data = val;
    next = NULL;
  }
};

void push(queuenode** rear,queuenode** front,int val){
  queuenode* temp = new queuenode(val);

  if(*rear == NULL){
    *front = *rear = temp ;
    return ;
  }

  (*rear)->next = temp;
  *rear = temp;

  return ;
}

void pop(queuenode* rear,queuenode* front){
  if(front == NULL) return;
  queuenode* temp = front ;
  int x = temp->data;
  if(rear == front)
    rear = front = NULL;
  else
    front = front->next;
  free(temp);
  cout<<"the data deleted is :"<<x<<endl;
  return ;
}

int main(){
  queuenode* front = NULL;
  queuenode* rear = NULL;
  int n;
  cin>>n;
  while(n--){
    int x;
    cin>>x;
    push(&rear,&front,x);
  }
  pop(rear,front);
  return 0;
}
