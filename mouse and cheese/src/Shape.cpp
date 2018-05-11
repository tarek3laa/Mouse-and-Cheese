#include "Shape.h"

Shape::Shape()
{

}
edir dir;
/*void Shape::SetCursorPos(int x, int y)
{
 printf("%c[%d;%df",0x1B,y,x);
 }*/

 void Shape::start()
 {
        bool sn=true,sa=false;
        while(true)
        {
            system("cls");
            cout<<endl<<endl<<endl<<endl<<endl;
            if(sn){
            cout<<"\t\t\t  __________\n";
            cout<<"\t\t\t | New Game |\n";
            cout<<"\t\t\t  ----------\n\n";
            cout<<"\t\t\t    About !\n\n";

            }
            else if(sa==true)
            {
                cout<<"\t\t\t  New Game\n\n";
                cout<<"\t\t\t  _________\n";
                cout<<"\t\t\t | About ! |\n";
                cout<<"\t\t\t  ---------\n";

            }
            if(GetAsyncKeyState(VK_UP)){
            sn=true;
            sa=false;
            }
            else if(GetAsyncKeyState(VK_DOWN))
            {
                sn=false;
                sa=true;
            }
            else if(GetAsyncKeyState(VK_RETURN))
            break;

        }
        if(sa==true)
        {
            system("cls");
            cout<<"\t\t  press ESC to return to the menu\n\n";
            cout<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t Mouse and cheese";
            cout<<endl<<endl;
            cout<<"\t\t\t   version 1.0";
            cout<<endl<<endl<<endl;
            cout<<"\t\t\t   coding by\n\n\t Tarek A. Attia , Aisha M. Eltahir and Saleh A. Al Baz\n\n";
            while(true){
            if(GetAsyncKeyState(VK_RETURN))
                break;
            }

        }


 }
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
