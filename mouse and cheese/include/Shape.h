#include <bits/stdc++.h>
/*#include <chrono>
#include <thread>
#include <unistd.h>*/
#include <windows.h>
using namespace std;
enum edir {STOP,UP,DOWN,RIGHT,LEFT};
class Shape
{
public:
    bool gameOver=false;
    bool winOver=false;
    bool b=false;
    char shape [30][60];
    //void setUp();
    // void SetCursorPos(int XPos, int YPos);
    Shape( );
    void setup();
    void start();
    void drow();
    void input();
    void logic();
    void drowGameOver();
    void clearscreen();
    void drowWinOver();

};
