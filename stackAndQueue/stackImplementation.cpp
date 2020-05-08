#include<bits/stdc++.h>
using namespace std;

struct stackNode {
  int data;
  stackNode * next;
  stackNode (int val){
    data = val;
    next = NULL;
  }
};

stackNode * push(stackNode * head,int val){
  stackNode * temp = new stackNode (val);
  if(head == NULL)
      head = temp;
  else{
    temp->next = head ;
    head = temp;
  }

  return head;
}

stackNode * pop(stackNode * head){
  stackNode * temp = head;
  head = head->next;
  cout<<"popped:"<<temp->data<<endl;
  free(temp);
  return head;
}

void print(stackNode* head){
  stackNode* temp = head ;
  while(temp){
    cout<<temp->data<<endl;
    temp = temp->next;
  }
  return ;
}

int main(){
  stackNode * head = NULL;
  int n;
  cin>>n;
  while(n--){
    int x;
    cin>>x;
    head = push(head,x);
  }
  head = pop(head);
  print(head);
  return 0;
}
