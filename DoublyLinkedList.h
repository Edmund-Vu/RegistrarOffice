#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList{
  public:
    int size;
    ListNode<T> *front;
    ListNode<T> *rear;

    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertRear(T data);
    T removeFront();
    T getFront();

    void printList();
    int deletePos(int pos);

    bool isEmpty();
    int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  rear = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){

}

template <class T>
void DoublyLinkedList<T>::insertRear(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(size == 0){
    front = node;
  }
  else{
    rear->next = node;
    node->prev = back;
  }

  back = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if(!isEmpty()){
    ListNode<T> *node = front;
    if(front->next == NULL){
      front = NULL;
      rear = NULL;
    }
    else{
      front->next->prev = NULL;
      front = front->next;
    }
    T temp = node->data;
    delete node;
    --size;
    return temp;
  }
  else{
    return T();
  }
}

template <class T>
T DoublyLinkedList<T>::getFront(){
  return front->data;
}

template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;
  while(true){
    if(curr->next == NULL){
      break;
    }
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
void DoublyLinkedList<T>::deletePos(int pos){
  int indx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(indx != pos){
    prev = curr;
    curr = curr->next;
    ++indx;
  }
  prev->next = curr->next;
  curr->next->prev = prev;
  curr->next = NULL;
  curr->prev = NULL;
  curr->data = NULL;

  --size;
  delete curr;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return(size == 0);
}

template <class T>
int DoublyLinkedList<T>::getSize(){
  return size;
}
