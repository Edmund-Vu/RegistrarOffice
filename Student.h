#include <iostream>

using namespace std;

template <class T>
class Student{
  public:
    int windowTime;
    int entryTime;
    int queueTime;
    int idleTime;

    Student();
    Student(int t, int e);
    ~Student();
};

template <class T>
Student<T>::Student(){
  windowTime = 0;
  entryTime = 0;
  queueTime = 0;
  idleTime = 0;
}

template <class T>
Student<T>::Student(int t, int e){
  windowTime = t;
  entryTime = e;
  queueTime = 0;
  idleTime = 0;
}

template <class T>
Student<T>::~Student(){

}
