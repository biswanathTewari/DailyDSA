// { Driver Code Starts
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

Node* sortedMerge(struct Node* a, struct Node* b);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;

    cin>>T;

    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;

        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}



// } Driver Code Ends


/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to merge the two sorted linked lists
// head1, head2: head of the two sorted linked lists
Node* sortedMerge(Node* head1,   Node* head2)
{
    Node* headnew ;
    Node* prev ;

    //picking the smaller as the newhead and prev
    if(head1->data <= head2->data){
        headnew=head1;
        prev = head1;
        head1 = head1->next;
    }
    else{
        headnew=head2;
        prev = head2;
        head2 = head2->next;
    }


    // similar to merge sort , we pick a node , append it to the prev node and move forward in the list
    while(head1 && head2){
        if(head1->data <= head2->data){
            prev->next = head1;
            head1 = head1->next;
        }
        else{
            prev->next = head2;
            head2 = head2->next;
        }
        prev = prev->next;
    }

    //remaining nodes
    while(head1){
        prev->next=head1;
        head1 = head1->next;
        prev = prev->next;
    }

    while(head2){
        prev->next = head2;
        head2 = head2->next;
        prev = prev->next;
    }

    return headnew;
}
