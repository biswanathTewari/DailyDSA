// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void printSpiral(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        printSpiral(root);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

void printSpiral(Node *root)
{
    if(root ==  NULL) return ;

    queue<pair<Node*,int>> q;
    map<int,vector<int>> mp; //for storing the elements according to there depth in the tree

    q.push(make_pair(root,0));

    while(!q.empty()){

        pair<Node*,int> p = q.front();
        Node* current = p.first;
        int height = p.second;

        mp[height].push_back(current->data);

        if(current->left != NULL) q.push(make_pair(current->left,height+1));
        if(current->right != NULL) q.push(make_pair(current->right,height+1));

        q.pop();
    }

    int i=0;
    cout<<mp[0][0]<<" ";

    for(auto it=mp.begin();it != mp.end();it++){

        if(i++ == 0) //for eliminating the root
            continue;

        vector<int> v= it->second;

        if(i % 2 == 0){ //left -> right
            for(int k=0;k<v.size();k++)
                cout<<v[k]<<" ";
        }
        else{ //right -> left
            for(int k=v.size()-1;k>=0;k--)
                cout<<v[k]<<" ";
        }
    }

    return ;
}
