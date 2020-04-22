#include <iostream>

using namespace std;

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
