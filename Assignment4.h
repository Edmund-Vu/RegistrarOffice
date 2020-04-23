#include <string>
#include "Student.h"
#include "GenQueue.h"

using namespace std;

class Sim{
  private:
    int type; //File line type (Student, Time, CLock)
    int entryTime;
    int timeAtWindow;
    int SCTC; //Student Count/Clock Tick
    int MEC; //Median Element Count
    int IEC; //Idle Element Count
  public:
    Sim();
    ~Sim();

    bool importFile(string file);
    bool trackTime(int t);
    // Stat methods for students
    double meanTime();
    double medianTime();
    int longestTime();
    int overTenTime();
    // Stat methods for the window/registrar
    double meanIdleTime();
    double longestIdleTime();
    int idleOverFiveTime();

    Student* *windowArray;
    GenQueue<Student*> studentQueue;
    GenQueue<int> waitStats;
    GenQueue<int> idleStats;

    int *medianArray;
    int *idleArray;

    int totalWindows;
    int totalStudents;
};
