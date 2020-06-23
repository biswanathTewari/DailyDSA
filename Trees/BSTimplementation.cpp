#include<bits/stdc++.h>
using namespace std;

// NOTE: the least common ancestor of two nodes, is simply the first traversed node whoes value lies b/w
//the values of the other two nodes, else root is the LCA

struct node{
  int value;
  node* right;
  node* left;
};


node* createNode(int value){
  node* temp=new node;
  temp->value=value;
  temp->right= NULL;
  temp->left= NULL;
  return temp;
}

node* insert(node* root,int value){
  if(root== NULL){
    root=createNode(value);
  }

  else if(value<=root->value)
    root->left=insert(root->left,value);

  else root->right=insert(root->right,value);

  return root;
}

// inorder traversal

void display(node* root){
  if(root==NULL)
    return;
  //cout<<"HOLA"<<endl;
  if(root != NULL){
    display(root->left);
    cout<<root->value<<endl;
    display(root->right);
  }
  return;
}

// level order traversal

void levelOrderTraversal(node* root){
  if(root == NULL)
    return ;
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node* current=q.front();
    cout<<current->value<<endl;
    if(current->left != NULL)
      q.push(current->left);
    if(current->right != NULL)
      q.push(current->right);
    q.pop();
  }
  return ;
}

int main(){
  node* root=NULL;
  int x;
  int n;
  cin>>n;
  while(n--){
    cin>>x;
    root=insert(root,x);
  }
  //display(root);
  levelOrderTraversal(root);
  return 0;
}
