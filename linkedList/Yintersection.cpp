// { Driver Code Starts
#include<iostream>
#include<stdio.h>
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

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends



/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{

    int i=0,j=0;

    Node* temp1=head1;
    Node* temp2=head2;

    while(head1){ //counting the size of 1st linked list
        i++;
        head1=head1->next;
    }

    while(head2){ //counting the size of 2nd linked list
        j++;
        head2=head2->next;
    }

    int diff = abs(i - j); //difference b/w there sizes
    int k=0;
    int prev=-1;
    Node* don;
    Node* jon;

    if(i >= j){ //bigger list is don and smaller jon
        don=temp1;
        jon=temp2;
    }
    else{
        jon=temp1;
        don=temp2;
    }

    while(don){ //travelling the distance by which don is bigger than jon
        k++;
        if(k==diff+1)
            break;
        don=don->next;
    }

    while(don != jon && don && jon){ //once the nodes match of the two lists or if faces NULL , while will stop
        don=don->next;
        jon=jon->next;
    }

    if(!don && !jon)
        return -1;

    return don->data;
}
