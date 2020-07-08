// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

    printf("%d", getNthFromLast(head, k));
    cout << endl;
    }
    return 0;
}// } Driver Code Ends



/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n){

  if(head == NULL) return -1;

  int size = 0;
  Node* t1 = head;
  Node* t2 = head;

  while(t1){ //counting the size of the list
    size++;
    t1 = t1->next;
  }

  if(n > size)
    return -1;

  int pos = size - n + 1; //simple math

  while(t2){

    pos--;
    if(pos == 0)
      return t2->data;

    t2 = t2->next;

  }

  return -1;

}
