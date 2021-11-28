#include <bits/stdc++.h>
#include<conio.h>

using namespace std;
typedef long long ll;

bool gameover,pa=1;
int h,w,x=13,y=9,fx,fy,movex=0,movey=0;
int ssize=1,prevx,prevy,de=0,tx,ty;
vector<int> snakex(ssize),snakey(ssize);

void dance()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cout.tie(0);
}

void start()
{
    dance();
    gameover=0,pa=1;
    h=20,w=29;
    x=13,y=9;
    movex=0,movey=0;
    ssize=1;
    snakex.resize(ssize);
    snakey.resize(ssize);
    fx=rand()%h+1;
    fy=rand()%(w-1)+1;

    snakex[0]=-300;
    snakey[0]=-300;

}

void drawlim()
{
    for(int i=0;i<w+1;i++)
    cout<<'#';
    cout<<endl;
}

void fcollision()
{
          if(x<=0 || y<0 || x>=w || y>h)
        gameover=1;
         if(x==fy&&y==fx)
                    {
                        ssize++;
                        snakex.resize(ssize);
                        snakey.resize(ssize);
                      //  snakex[0]=prevx;
                        //snakey[0]=prevy;

                     fx=rand()%h+1;
                     fy=rand()%(w-1)+1;
                    }

}

void draw()
{

    prevx=x,prevy=y;
    x+=movex,y+=movey;

    fcollision();

    for(int l=0;l<45000000;l++){}
     system("cls");

     for(int i=1;i<ssize;i++)
     {
         tx=snakex[i];
         ty=snakey[i];
       snakex[i]=prevx;
       snakey[i]=prevy;
       prevx=tx;
       prevy=ty;
     }

    drawlim();

    for(int i=0;i<=h;i++)
    {
        for(int j=0;j<=w;j++)
        {

            if(j==0||j==w)
                cout<<'#';

            else    if(i==y&&j==x)
                cout<<'O';

           else if(i==fx&&j==fy )
                cout<<char(3);

                else
                {
                    bool con=1;
                  for(int re=0;re<ssize;re++)
                  {
                      if(x==snakex[re] && y==snakey[re])
                        gameover=1;

                      if(j==snakex[re] && i==snakey[re])
                      {
                          cout<<'o';
                          con=0;
                      de++;
                      }
                  }
                  //  if(j+de>=w)
                    //    j=w-1;
                    //else
                      //  j+=de;
                    if(con)
                    cout<<" ";
                }
            de=0;

        }

        cout<<endl;
    }

    drawlim();
    cout<< "SCORE: "<<5*(ssize-1)<<endl;

}




int main()
{

    z:;
    srand(time(0));
    start();
    while(!gameover)
    {

        draw();
    if(kbhit())
         {

    char ch;
   ch=getch();
    /*
    switch(_getch())
    {
        case 'a': movex=-1,movey=0;break;
        case 'd': movex=1,movey=0;break;
        case 'w': movey=-1,movex=0;break;
        case 's'
        : movey=1,movex=0;break;
        default : break;
    }
    */

         if(ch=='a'&&movex!=1){ movex=-1;movey=0;}
        if(ch=='d'&&movex!=-1) {movex=1;movey=0;}
        if(ch=='w'&&movey!=1) {movey=-1;movex=0;}
        if(ch=='s'&&movey!=-1) {movey=1;movex=0;}


         }

    }
        system("cls");
        cout<< "\nGAME OVER\n";
        cout<< "SCORE: "<<5*(ssize-1)<<endl;
        cout<<"Play again ? 1 : 0 \n";
        cin>>pa;
        if(pa)
        {start();
           goto z;

        }
        else
    return 0;
}
