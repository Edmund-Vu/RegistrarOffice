#include "ListNode.h"

using namespace std;

template <class T>
class GenQueue{
  public:
    int numElements;
    ListNode<T> *front;
    ListNode<T> *rear;
    char *myQueue;

    GenQueue();
    ~GenQueue();

    void insert(T d);
    T remove();

    T rFront();
    T rRear();

    void printQ();
    bool isEmpty();
    int getSize();
};

template <class T>
GenQueue<T>::GenQueue(){
  numElements = 0;
  front = NULL;
  rear = NULL;
}

template <class T>
GenQueue<T>::~GenQueue(){
  delete myQueue;
}

template <class T>
void GenQueue<T>::insert(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(numElements == 0){
    front = node;
  }
  else{
    rear->next = node;
    node->prev = rear;
  }

  rear = node;
  ++numElements;
}

template <class T>
T GenQueue<T>::remove(){
  if(!isEmpty()){
    ListNode<T> *node = front;

    T temp = node->data;

    // If it is the only node
    if(front->next == NULL){
      front = NULL;
      rear = NULL;
    }
    // More than one node
    else{
      front->next->prev = NULL;
      front = front->next;
    }

    delete node;
    --numElements;
    return temp;
  }
  else{
    return T();
  }
}

template <class T>
T GenQueue<T>::rFront(){
  return front->data;
}

template <class T>
T GenQueue<T>::rRear(){
  return rear->data;
}

template <class T>
void GenQueue<T>::printQ(){
  ListNode<T> *curr = front;

  while(true){
    if(curr != NULL){
      cout << curr->data << endl;
      curr = curr->next;
    }
    else{
      break;
    }
  }
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return(numElements == 0);
}

template <class T>
int GenQueue<T>::getSize(){
  return numElements;
}
