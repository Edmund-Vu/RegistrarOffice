#include "Student.h"

using namespace std;

Student::Student(){
  windowTime = 0;
  entryTime = 0;
  queueTime = 0;
  idleTime = 0;
}

Student::Student(int t, int e){
  windowTime = t;
  entryTime = e;
  queueTime = 0;
  idleTime = 0;
}

Student::~Student(){

}
