// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isBST(root) << endl;
  }
  return 0;
}
// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */

bool isBST(Node* root) {
    return isBSTUtil(root,INT_MIN,INT_MAX);
}

int isBSTUtil(Node* root,int minn,int max){

    if(root == NULL)
        return 1;

    if(root != NULL){

        if(minn > root->data || root->data > max)
            return 0;

        int a=isBSTUtil(root->left,minn,root->data);
        int b=isBSTUtil(root->right,root->data,max);
        return min(a,b);

    }
}

/* if(root != NULL){
    int x=root->data;

    if(x<minn || max<x)
        return 0;

    int a=isBSTUtil(root->left,minn,x);
    int b=isBSTUtil(root->right,x,max);

    return min(a,b);
    } */
