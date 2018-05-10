#include "Shape.h"

Shape::Shape()
{

}
edir dir;
/*void Shape::SetCursorPos(int x, int y)
{
 printf("%c[%d;%df",0x1B,y,x);
 }*/
void Shape::clearscreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);

}
void Shape::drowWinOver()
{
        cout<<endl;
        cout<<endl;
        cout<<endl;


    cout<<"\t  **                         **     #                     \n";
    cout<<"\t   **                       **          **                \n";
    cout<<"\t    **         ***         **      **   **                \n";
    cout<<"\t     **       ** **       **       **   ***********       \n";
    cout<<"\t      **     **   **     **        **   * ******* *       \n";
    cout<<"\t       **   **     **   **         **   **       **       \n";
    cout<<"\t        ** **       ** **          **   **       **       \n";
    cout<<"\t         ***         ***           **   **       **   \n\n\n";


    cout<<"\t                **                  **    **************               \n";
    cout<<"\t************     **                **     * ********** *     **     ***\n";
    cout<<"\t*          *      **              **      * *        * *      **   **  \n";
    cout<<"\t* ******** *       **            **       * *        * *      **  **   \n";
    cout<<"\t* *      * *        **          **        * ********** *      ** **    \n";
    cout<<"\t* *      * *         **        **         **************      ***      \n";
    cout<<"\t* ******** *          **      **          **                  **       \n";
    cout<<"\t*          *           **    **           **                  **       \n";
    cout<<"\t************            **  **            **                  **       \n";
    cout<<"\t                         ****             **                  **       \n";
    cout<<"\t                                          *********           **       \n";
    cout<<"\t                                          *********                  \n\n";

}

void Shape::drowGameOver()
{
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<"****"<<"\t****"<<"*   *       *  *****   %"<<endl;
cout<<"*  *"<<"\t*  **"<<"\t*"<<"       *"<<"  *   *"<<endl;
cout<<"*  *"<<"\t*  **"<<"\t* *"<<"   * *"<<"  *   *"<<endl;
cout<<"****"<<"\t** **"<<"\t*   *"<<"*  *"<<"  *   *"<<endl;
cout<<"   *"<<"\t   ****"<<"\t*       *"<<"  *****"<<endl;
cout<<"   *"<<"                       *"<<endl;
cout<<"****"<<"                       ******"<<endl;
cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
cout<<" ****"<<"  *     *"<<"  ***"<<"   *  *"<<endl;
cout<<" *  *"<<"   *   *"<<"   * *"<<"   * *"<<endl;
cout<<" *  *"<<"    * *"<<"    ***"<<"   **"<<endl;
cout<<" ****     *     *     *"<<endl;
cout<<"                ***   *           %"<<endl;
cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;

}
void Shape:: drow()
{
    /*in Windows OS you should use*//**system("cls");*//*but in Linux OS you should use*/ ///system("clear");
   //s.SetCursorPos(0,0);
   system("cls");
    for(int y=0; y<30; y++)
    {
        for(int x=0; x<25; x++)
        {
            if(shape[y][x]=='m')
                cout<<"@";
            else if(shape[y][x]=='s')
                cout<<" ";
            else if (shape[y][x]=='w')
                cout<<"#";
            else if(shape[y][x]=='c')
                cout<<"$";


        }
        cout<<endl;

    }

}

void Shape::input()
{
    dir=STOP;
   if(GetAsyncKeyState(VK_UP))
            dir=UP;
        else  if(GetAsyncKeyState(VK_DOWN))
            dir=DOWN;
        else  if(GetAsyncKeyState(VK_RIGHT))
           dir=RIGHT;
        else  if(GetAsyncKeyState(VK_LEFT))
           dir=LEFT;

         /*  if(c=='w')
           dir=UP;
           else if(c=='a')
           dir=LEFT;
           else if(c=='d')
            dir=RIGHT;
          else if(c=='s')
          dir=DOWN;*/
}
void Shape::logic()
{
   b=false;
    switch(dir)
    {
    case LEFT :

        for(int y=0; y<30; y++)
        {
            for(int x=0; x<25; x++)
            {
                if(shape[y][x]=='m'&&shape[y][x-1]=='s'&&x!=0)
                {
                    swap(shape[y][x],shape[y][x-1]);
                    b=true;
                    break;
                }
                if(shape[y][x]=='m'&&shape[y][x-1]=='c'&&x!=0)
                    winOver=true;

            }
            if(b)
            break;
        }
        break;


    case RIGHT :

        for(int y=0; y<30; y++)
        {
            for(int x=0; x<25; x++)
            {
                if(shape[y][x]=='m'&&shape[y][x+1]=='s'&&x!=59)
                {
                    swap(shape[y][x],shape[y][x+1]);
                    b=true;
                    break;
                }
                if(shape[y][x]=='m'&&shape[y][x+1]=='c'&&x!=59)
                    winOver=true;
            }
            if(b)
            break;
        }



        break;

    case UP :
        for(int y=0; y<30; y++)
        {
            for(int x=0; x<25; x++)
            {
                if(shape[y][x]=='m'&&shape[y-1][x]=='s'&&y!=0)
                {
                    swap(shape[y][x],shape[y-1][x]);
                   b=true;
                   break;

                }
                if(shape[y][x]=='m'&&shape[y-1][x]=='c'&&y!=0)
                    winOver=true;

            }
            if(b)
                break;
        }

        break;
    case DOWN :
        for(int y=0; y<30; y++)
        {
            for(int x=0; x<25; x++)
            {
                if(shape[y][x]=='m'&&shape[y+1][x]=='s'&&y!=29)
                {
                    swap(shape[y][x],shape[y+1][x]);
                    b=true;
                    break;
                }
                if(shape[y][x]=='m'&&shape[y+1][x]=='c'&&y!=29)
                    winOver=true;



            }
            if(b)
                break;
        }

        break;
    }

}
