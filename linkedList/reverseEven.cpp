//biZanXsolutions
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define ll long long int
#define ld long double
#define sl unsigned long long int
#define str string
#define vll vector<ll>
#define pb push_back
#define fr(i,n) for(ll (i) = 0; (i) <(n) ; (i)=(i+1))
#define frn(i,n) for(ll (i) = 1; (i) <=(n) ; (i)=(i+1))
#define frev(i,n) for(ll (i) = n-1; (i) >=(0) ; (i)--)
#define fr1(j,a,b,c) for(ll (j) = a; (j) <b ; (j)=(j+c))
#define bw(t) while(t--)
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
typedef pair<ll, pair<ll, ll>> xecs;

bool cmp(ll a, ll b){
  return a*b;
}

struct Node{
  int data;
  Node* next;
  Node(int val){
    data=val;
    next=NULL;
  }
};

Node* insertAtHead(Node* head,int val){
  Node* temp=new Node(val);

  if(head == NULL){
    head=temp;
    return head;
  }

  temp->next=head;
  head = temp;

  return head;
}

Node* reverse(Node* head){
  if(head == NULL) return NULL ;
  Node* head2 = NULL;
  Node* temp=head;
  while(temp){
    head2 = insertAtHead(head2,temp->data);
    temp=temp->next;
  }
  return head2;
}

/*Node* evenReverse(Node* head){
  if(head == NULL) return NULL ;
  Node* prev;
  Node* temp=head;
  if((temp->data)%2 == 0)
    prev = temp;
  temp = temp->next;
  while(temp){
    if((temp->data)%2 == 0){
      vll v;
      while(temp && (temp->data)%2 != 0 ){
        v.pb(temp->data);
        temp = temp->next;
      }

    }
    if((temp->data)%2 == 0)
      prev = temp;
    else prev = NULL;
    temp=temp->next;
  }
  return head;
}*/

void vectorize(Node* head){

  if(head == NULL){
    cout<<"";
    return;
  }
  vll v;
  Node* temp=head;
  while(temp){
    v.pb(temp->data);
    temp=temp->next;
  }

  fr(i,v.size()){
    if(v[i]%2 == 0){
      ll j  = i;
      while(i+1 < v.size() && v[i+1]%2 == 0 )
        i++;
      sort(v.begin()+j,v.begin()+i+1,cmp);
    }
  }

  fr(i,v.size())
    cout<<v[i]<<" ";
}

int main(){
  fast;
  int n;
  cin>>n;
  int val;

  Node* head = NULL;

  while(n--){
    cin>>val;
    head=insertAtHead(head,val);
  }

  Node* rHead = reverse(head);
  vectorize(rHead);

  /*fr(i,v.size()){
    if(v[i]%2 == 0){
      ll j  = i;
      while(i+1 < v.size() && v[i+1]%2 == 0 )
        i++;
      sort(v.begin()+j,v.begin()+i+1,cmp);
    }
  }

  fr(i,v.size())
    cout<<v[i]<<" ";*/
  cout<<endl;
  return 0;
}
