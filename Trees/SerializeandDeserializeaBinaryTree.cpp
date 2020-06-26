// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends



void serialize(Node *root,vector<int> &A){

  if(root == NULL) return ;

  //levelOrderTraversal
  queue<Node*> q;
  q.push(root);

  //pushing the value of the children of the node in the vector
  while(!q.empty()){

    Node* current = q.front();
    q.pop();

    if(current != NULL){

      A.push_back(current->data); //inserting the value of this node in the vector
      q.push(current->left);
      q.push(current->right);

    }
    else A.push_back(-1); //if the node is null

  }

}



Node * deSerialize(vector<int> &A){

  Node* root = new Node(A[0]);

  queue<Node*> q;
  q.push(root);

  int i = 1; //index of the vector

  //attaching the children of the nodes , if present
  while(!q.empty() && i<A.size()){

    Node* current = q.front();
    q.pop();

    if(A[i] != -1){ //if the left is not null

      current->left = new Node(A[i]);
      q.push(current->left);

    }

    i++; //increasing the index/position of the vector
    if(i >= A.size())
      break;

    if(A[i] != -1){ //if the right is not null

      current->right = new Node(A[i]);
      q.push(current->right);

    }

    i++;

  }

  return root;

}


// { Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        vector<int> A;
        serialize(root, A);

        Node *getRoot = deSerialize(A);
        inorder(getRoot);
        cout << "\n";

    }


    return 0;
}  // } Driver Code Ends
