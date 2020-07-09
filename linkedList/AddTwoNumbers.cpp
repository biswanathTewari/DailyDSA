// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* addTwoLists(struct Node* first, struct Node* second);

void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}
// } Driver Code Ends
/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) { // NOTE : the above driver code is storing the mirror of the input stream, so we can take advantage of arrays

    Node* head = NULL ; //resultant head
    int a[5002],b[5002];
    int i=0,j=0;
    int k=0,l=0,carry=0;

    while(first){ //storing the linked list elements in the array, which are already reversed , so ease of adding
        a[i++]=first->data;
        first = first->next;
    }

    while(second){
        b[j++]=second->data;
        second = second->next;
    }

    //filling the diffrence with zeros
    if(i <= j)
        for(k=i;k<i+abs(i-j);k++)
            a[k]=0;
    else
        for(l=j;l<j+abs(i-j);l++)
            b[l]=0;

    int m = (i >= j)? i : j;
    int d,h;

    //addition
    for(h = 0;h<m;h++){
        int sum = a[h] + b[h] + carry;
        if(sum>9){
            carry = sum/10;
            d=sum%10;
        }
        else{
            d = sum;
            carry = 0;
        }

        a[h]=d;
    }

    //special case for the carry
    if(carry)
        a[h++]=carry;

    //using the push function , again the mirror format will be stored in the resultant linked list
    for(int b=0;b<h;b++)
        push(&head,a[b]);

    return head;
}
