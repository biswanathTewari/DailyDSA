#include<bits/stdc++.h>
using namespace std;

class minHeap{
    int *ha;
    int capacity;
    int hsize;

  public:
    minHeap(int x){
      capacity = x;
      hsize = 0;
      ha = new int[capacity];
    }

    int parent(int i)  { return (i-1)/2 ; }

    int leftChild(int i) { return (2*i)+1 ; }

    int rightChild(int i) { return (2*i)+2 ; }

    void heapify(int i); //correcting the structure , we are going down the structer

    void decreaseKey(int i,int ival);// its nothing , just replaces the current value of ha[i] with ival.

    int extractMin(); //remove the minimum(root) and return it.

    int getMin() { return ha[0]; }

    void insertKey(int k);

    void deleteKey(int i);

    void display(){
      for(int i=0;i<hsize;i++)
        cout<<ha[i]<<" ";
        cout<<endl;
    }

};

void minHeap :: insertKey(int k){
  if(hsize == capacity){
    cout<<"Overflow bro! Dude just look"<<endl;
    return ;
  }

  hsize++;
  int i = hsize-1;
  ha[i] = k;


  while(i != 0 && ha[i]<ha[parent(i)]){ //mainting the structure in a minimum fashion, checking upwards
    swap(ha[i],ha[parent(i)]);
    i = parent(i);
  }
}

void minHeap :: decreaseKey(int i,int ival){
  ha[i] = ival;
  while(i != 0 && ha[parent(i)]>ha[i]){
    swap(ha[parent(i)],ha[i]);
    i = parent(i);
  }
}

int minHeap :: extractMin(){
  if(hsize <=0 ) return INT_MAX;

  if(hsize == 1){
    hsize--;
    return ha[0];
  }

  int root = ha[0];
  ha[0] = ha[hsize-1]; // can be replaced with anything
  hsize--;
  heapify(0);
  return root;
}

void minHeap :: deleteKey(int i){
  decreaseKey(i,INT_MIN);
  extractMin();
}

void minHeap :: heapify(int i){
  int l = leftChild(i);
  int r = rightChild(i);

  int smallest = i;

  if(l<hsize && ha[l]<ha[i])
    smallest = l;
  if(r<hsize && ha[r]<ha[smallest])
    smallest = r;
  if(smallest != i){
    swap(ha[i],ha[smallest]);
    heapify(smallest);
  }
}

int main(){

  minHeap h(11);
  h.insertKey(3);
  h.insertKey(2);
  h.deleteKey(1);
  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);
  h.display();

  cout<<h.extractMin()<<endl;
  cout<<h.getMin()<<endl;

  h.decreaseKey(2,1);

  cout<<h.getMin()<<endl;

  return 0;
}
