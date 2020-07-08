// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

     int t;
     cin>>t;

     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;

         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }

        int k;
        cin>>k;
        head = reverse(head, k);

        printList(head);

     }

     return(0);

}

// } Driver Code Ends


//creating my own fucking linked list

struct node *reverse (struct node *head, int k)
{
    if(head == NULL || k == 0 || k == 1) return head;

    node* prev = NULL;
    node* cur = head;
    node* ahead = NULL;
    int count = 0;

    while(cur && count < k){ //reversing the linked list for a length k

      ahead = cur->next;
      cur->next = prev;
      prev = cur;
      cur = ahead;
      count++;

    }

    //edge cases
    if(cur) //after reversing the cur will be pointin to the next node to the kth node & if a node exists there
      head->next = reverse(cur,k); //now head->next will point to the 1st node of the next k reversed linked list

    return  prev; //the 1st node of this k places reversed linked list
}
