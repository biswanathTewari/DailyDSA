#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node* prev;
  Node(int val){
    data=val;
    next=prev=NULL;
  }
};

Node* insertAtHead(Node* head,int val){
  Node* temp=new Node(val);

  if(head == NULL){
    head=temp;
    return head;
  }

  head->prev=temp;
  temp->next=head;
  head=temp;
  return head;
}

void print(Node* head){
  if(head == NULL) return ;

  Node* temp=head;
  while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

void printbackwards(Node* head){
  Node* temp=head;

  //getting the last node
  while(temp->next)
    temp=temp->next;
  while(temp){
    cout<<temp->data<<" ";
    temp=temp->prev;
  }
  cout<<endl;
}

int main(){
  int n;
  cin>>n;
  int val;

  Node* head = NULL;

  while(n--){
    cin>>val;
    head=insertAtHead(head,val);
  }

  //print(head);
  printbackwards(head);
  return 0;
}
