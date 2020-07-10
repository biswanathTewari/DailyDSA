// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
// Should reverse list and return new head.
Node* reverseList(Node *head)
{
  if(head == NULL) return head;


  Node* prev = NULL;
  Node* temp = head;
  Node* ahead = NULL;

  while(temp != NULL){

      ahead = temp->next; //to access the next right node later
      temp->next = prev; //chnaging the next direction of every node from next right node to next left node
      prev = temp;
      temp = ahead ; //accessing the next right node

  }

  return prev ;

}


bool isPalindrome(Node *head){

  //finding the size of the linked lists
  int size = 0;
  Node* temp = head;

  while(temp){
    size++;
    temp = temp->next;
  }

  int target;

  //middle of the list
  if(size %  2 == 0)
    target = size / 2;
  else target = (size / 2) + 1;

  //slicing the list into two halves
  Node* head1 = head; //1st half
  Node* head2; //second half
  temp = head;

  while(temp && target){
    target--;
    temp = temp->next;
  }// if odd gives the middle , if even gives the left from the middle

  //reversing the second half
  head2 = reverseList(temp);


  //palin check
  while(head1 && head2){

    //checking the left of the list with the right of the original list
    if(head1->data != head2->data)
      return 0;

    head1=head1->next;
    head2=head2->next;

  }

  return 1;
}
