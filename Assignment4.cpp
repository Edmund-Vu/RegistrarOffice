#include <fstream>
#include <queue>
#include <algorithm>
#include <sstream>
#include "Assignment4.h"

using namespace std;

Sim::Sim(){
  type = 1;
  entryTime = 0;
  timeAtWindow = 0;

  SCTC = 0;
  MEC = 0;
  IEC = 0;

  totalWindows = 0;
  totalStudents = 0;
}

Sim::~Sim(){
  delete [] windowArray;
  delete [] idleArray;
  delete [] medianArray;
}

bool Sim::importFile(string file){
  string line;
  int lineCount = 1;

  ifstream iStream;
  iStream.open(file.c_str());

  try{
    getline(inputStream, line);
    totalWindows = atoi(line.c_str());

    windowArray = new Students*[totalWindows];

    for(int i = 0; i < totalWindows; ++i){
      Students* student = new Student();
      windowArray[i] = student;
    }
    ++lineCount;
  }
  catch(exception e){
    cout << "Error" << endl;
    return false;
  }
  while(getline(inputStream, line)){
    switch(type){
      case(1): {
        try{
          entryTime = atoi(line.c_str());
          ++type;
          ++lineCount;
        }
        catch(exception e){
          cout << "Error" << endl;
          return false;
        }
        break;
      }
      case(2): {
        try{
          if(line != ""){
            SCTC = atoi(line.c_str());

            for(int i = 0; i < SCTC; ++i){
              getline(inputStream, line);
              ++lineCount;

              try{
                timeAtWindow = atoi(line.c_str());
              }
              catch(exception e){
                cout << "Error" << endl;
                return false;
              }
              ++totalStudents
              Students* student = new Student(timeAtWindow, entryTime);
              studentQueue.insert(student);
            }
            --type;
          }
        }
        catch(exception e){
          cout << "Error" << endl;
          return false;
        }
        break;
      }
      default:
        break;
    }
  }
  return true;
}

bool Sim::trackTime(int t){
  for(int i = 0; i < totalWindows; ++i){
    if(windowArray[i]->windowTime > 0){
      windowArray[i]->windowTime--;
    }
    else{
      windowArray[i]->idleTime--;
    }
  }

  if(!studentQueue.isEmpty()){
    ListNode<Students*> *curr = studentQueue.front;

    while(curr != NULL){
      if(curr->data->entryTime < t){
        curr->data->queueTime += 1;
      }
      curr = curr->next;
    }
  }
  return true;
}

double Sim::meanTime(){
  ListNode<int> *curr = waitStats.front;

  double mean = 0;
  double sum = 0;
  double n = 0;

  while(curr != NULL){
    sum += curr->data;
    curr = curr->next;
    ++n;
  }
  if(n == 0){
    return 0;
  }
  mean = sum / n;
  return mean;
}

double Sim::medianTime(){
  ListNode<int> *curr = waitstats.front;

  double median = 0;
  MEC = 0;

  while(curr != NULL){
    curr = curr->next;
    ++MEC;
  }

  if(MEC == 0){
    return 0;
  }
  else{
    medianArray = new int[MEC];
    curr = waitStats.front;

    for(int i = 0; i < MEC; ++i){
      medianArray[i] = curr->data;
      curr = curr->next;
    }

    sort(medianArray, medianArray + MEC);
    if(MEC % 2 == 1){
      double d = 0;
      int r = 0;

      r = (MEC/2) + 1;
      d = medianArray[r];

      return d;
    }
    else{
      double d = 0;
      int a = 0;
      int z = 0;

      a = MEC/2;
      z = (MEC/2) + 1;

      if(medianArray[z] == 0){
        return 0;
      }

      d = double(medianArray[a]/double(medianArray[z]));

      return d;
    }
  }
}

int Sim::longestTime(){
  
}
