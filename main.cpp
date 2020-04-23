#include "Assignment4.h"

using namespace std;

int main(int argc, char** argv){
  Sim s;

  if(argc < 2){
    cout << "Please enter a file path." << endl;
  }
  else if(argc >= 2){
    string file = argv[1];

    int currTime = 0;
    int openWindows = 0;
    bool exit;

    if(s.importFile(file)){
      while(exit){
        if(s.studentQueue.isEmpty()){
          int temp = 0;

          for(int i = 0; i < s.totalWindows; ++i){
            if((s.windowArray[i]->windowTime) < 1){
              ++temp;
            }
          }
          if(temp == s.totalWindows){
            exit = false;
          }
        }
        for(int i = 0; i < s.totalWindows; ++i){
          if((s.windowArray[i]->windowTime) < 1){
            if(!s.studentQueue.isEmpty()){
              Student* student = s.studentQueue.rFront();

              if(student->entryTime <= currTime){
                if(s.windowArray[i]->idleTime > 0){
                  s.idleStats.insert(s.windowArray[i]->idleTime);
                }
                s.windowArray[i] = s.studentQueue.remove();
                s.waitStats.insert(s.windowArray[i]->queueTime);
              }
            }
          }
        }
        ++currTime;
        s.trackTime(currTime);
      }
      for(int i = 0; i < s.totalWindows; ++i){
        if(s.windowArray[i]->idleTime > 0){
          s.idleStats.insert(s.windowArray[i]->idleTime);
        }
      }
      // Print the results
      cout << "Mean Student Wait Time: " << s.meanTime() << endl;
      cout << "Median Student Wait Time: " << s.medianTime() << endl;
      cout << "Longest Student Wait Time:" << s.longestTime() << endl;
      cout << "Number of Students Waiting Over Ten Minutes:" << s.overTenTime() << endl;
      cout << "Mean Window Idle Time:" << s.meanIdleTime() << endl;
      cout << "Longest Window Time:" << s.longestIdleTime() << endl;
      cout << "Idle Time Over Five Minutes:" << s.idleOverFiveTime() << endl;
    }
  }
  return 0;
}
