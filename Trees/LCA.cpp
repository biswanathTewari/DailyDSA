// { Driver Code Starts
//Code by 1shubhamjoshi1
#include<bits/stdc++.h>

using namespace std;

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

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}


Node* LCA(Node *root, int , int );

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        int l,r;
        cin>>l>>r;

        cout<<LCA(root,l,r)->data<<endl;
    }
}
// } Driver Code Ends

/*You are required to complete
this function*/
Node* LCA(Node *root, int l, int h)
{
    // base case
    if(root==NULL)
        return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if(l>root->data and h > root->data)
    {
        return LCA(root->right,l,h);
    }

    // If both n1 and n2 are greater than root, then LCA lies in right
    if(l<root->data and h<root->data)
    {
        return LCA(root->left,l,h);
    }

    // else the root must lie in between the numbers
    //one number lies in the left sub-tree while the other lies in the right sub-tree
    return root;
}
