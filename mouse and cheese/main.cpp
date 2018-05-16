#include "Shape.h"

int main()
{
     Shape s;
     int stime=0 ,etime=0,e_stime=0,time1=180;
    s.start();
    stime = time(NULL);
    system("cls");
    do
      {
       s.clearscreen();
       s.drow();
       s.input();
       s. logic();
       etime =time(NULL);
       e_stime=etime-stime;
       time1=180-e_stime;
       cout<<"Time : "<<time1<<"  sec\n";
       if(time1<=0)
        s.gameOver=true;
       // s.SetCursorPos(0,0);
       Sleep(200);
      // usleep(1000000);

       }
    while (!s.winOver&&!s.gameOver);
    if(s.gameOver){
        system("cls");
        s.drowGameOver();
        Sleep(100000);
        }
        else if(s.winOver){
                system("cls");
        s.drowWinOver();
                Sleep(100000);
        }
        system("pause");
    return 0;
}
