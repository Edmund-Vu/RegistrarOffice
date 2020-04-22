#include <string>
#include "Student.h"
#include "GenQueue.h"

using namespace std;

class Sim{
  private:
    int type;
    int entryTime;
    int timeAtWindow;
    int Median;
    int Idle;
  public:
    Sim();
    ~Sim();

    bool inportFile(string file);
    bool trackTime(int t);

    double meanTime();
    double medianTime();
    int longestTime();
    int overTenTime();

    double meanIdleTime();
    double longestIdleTime():
    int idleOverFiveTime();

    Students* *windowArray;
    GenQueue<Students*> studentQueue;
    GenQueue<int> waitStats;
    Genqueue<int> idleStats;

    int *medianArray;
    int *idleArray;

    int totalWindows;
    int totalStudents;
};
