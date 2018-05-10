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
    char shape [29][60]=
    {
        {'w','m','w','w','w','w','w','w','s','s','w','s','s','s','s','w','w','w','s','s','s','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','w','s','s','s','s','s','s','w','s','s','s','s','s','s','s','s','w','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','w','s','w','w','s','s','s','s','s','w','s','s','s','s','w','s','w','s','w','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','w','s','w','s','s','s','s','s','s','w','s','s','s','s','w','s','w','s','w','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','w','s','s','s','s','s','s','s','s','w','s','s','s','s','w','s','w','s','w','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','w','w','w','w','w','s','s','s','s','w','s','s','s','s','w','s','w','s','w','s','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','w','s','s','s','s','w','s','s','s','s','w','s','w','s','s','s','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','w','s','s','s','s','w','s','s','s','s','w','s','w','s','s','s','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','w','s','s','s','s','w','s','s','s','s','w','s','w','s','s','s','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','w','s','s','s','s','w','w','w','w','w','w','s','w','s','s','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','s','s','s','w','s','s','s','s','s','s','w','s','s','w','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','s','w','s','w','s','w','w','w','w','w','w','s','s','w','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','s','w','s','w','s','w','s','s','s','s','s','s','s','w','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','s','w','s','w','s','w','s','s','s','s','s','s','s','w','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','w','w','s','w','s','w','s','s','s','s','s','s','s','w','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','w','s','s','w','s','w','w','w','w','w','w','w','w','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','w','s','s','w','s','s','s','s','s','s','s','w','s','s','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','s','s','s','w','s','s','s','s','s','s','s','w','s','w','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','s','s','s','w','w','w','w','s','s','s','s','s','s','s','w','s','w','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','w','s','s','s','s','s','w','s','s','s','s','s','s','s','w','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','w','w','w','w','w','s','w','w','w','w','w','w','w','s','w','w','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','w','s','s','s','w','s','w','w','s','s','s','s','s','s','w','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','w','s','s','w','w','s','w','s','s','s','s','s','w','w','w','s','s','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','w','s','w','w','w','s','w','s','w','w','w','w','w','s','s','s','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','w','s','w','s','s','s','w','s','w','s','s','s','s','s','s','s','c','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','w','w','w','s','w','s','s','w','w','s','w','s','w','w','w','w','w','w','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w'},
        {'w','s','s','s','w','s','w','s','s','w','w','s','w','s','s','s','w','s','w','s','w','w','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','s','w','w','w'},
        {'w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w'},
    };
    //void setUp();
   // void SetCursorPos(int XPos, int YPos);
    Shape( );

    void drow();
    void input();
    void logic();
    void drowGameOver();
   void clearscreen();
   void drowWinOver();

};