#include<iostream>
using namespace std;

struct node{
  int val;
  node* left;
  node* right;

  node(int x){
    val  = x;
    left = right = NULL;
  }
};

class BST{
public:


  node* insert(node* root,int x){

    node* temp = new node(x);

    if(root == NULL){
      root = temp;
      return root;
    }

    if(x <= root->val)
      root->left = insert(root->left,x);
    else root->right = insert(root->right,x);

    return root;

  }

  bool search(node* root,int x){
    if(root->val == x) return true;
    if(x <= root->val) return search(root->left,x);
    return search(root->right,x);
  }

  node* deletenode(node* root,int x){

    if(root == NULL) return root;
    else if(x < root->val) return deletenode(root->left,x);
    else if(x > root->val) return deletenode(root->right,x);
    else{
      if(root->left == NULL && !root->right){
        node* temp = root;
        root = NULL;
        delete(temp);
      }
      else if(root->right){
        node* temp = root;
        root=root->right;
        delete(temp);
      }
      else if(root->left){
        node* temp = root;
        root=root->left;
        delete(temp);
      }
      else{
        node* temp = findmin(root->right);
        root->val = temp->val;
        root->right = deletenode(root->right,val);
      }
    }

    return root;

  }
};

int main(){

  node* root = NULL;
  BST b;
  root = b.insert(root,5);
  root = b.insert(root,4);
  root = b.insert(root,6);
  root = b.insert(root,3);
  cout<<b.search(root,4)<<endl;
}
