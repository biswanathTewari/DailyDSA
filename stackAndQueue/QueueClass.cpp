#include<iostream>
using namespace std;

struct node{
  int data;
  node* next;
  node(int x){
    data = x;
    next = NULL;
  }
};

class queue{

public:

  node* front;
  node* rear;


  queue(){
    front = rear = NULL;
  }

  void enqueue(int x){
    node* temp = new node(x);

    if(rear == NULL){
      rear = front = temp;
      return ;
    }

    rear->next = temp;
    rear = temp;
  }

  void dequeue(){
    node* temp = front;
    front = front->next;
    delete(temp);
  }
};

int main(){

  queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.dequeue();

  cout<<(q.front)->data<<endl;
  cout<<(q.rear)->data<<endl;

  return 0;
}
