/**************************************************************************/
/*       PROGRAM TO DRAW KOCH SNOWFLAKE /**************************************************************************/


#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class fractal
{
 int x1,y1,x2,y2,x3,y3,n;

  public:
  void initgr();
  void close();
   void koch (int it, int x1, int y1, int x5, int y5);

	void draw();


  };

  void fractal:: initgr()
  {
    int gm,gd=DETECT;
    initgraph(&gd,&gm,NULL);
  }

  void fractal:: close()
  {
   getch();
   closegraph();
   }

void fractal:: koch (int it, int x1, int y1, int x5, int y5)
{ 
   fractal f1;
  int deltaX, deltaY, x2, y2, x3, y3, x4, y4;
 
          if (it == 0){
 
              line(x1, y1, x5, y5);
          }
          else{
                deltaX = x5 - x1;
                deltaY = y5 - y1;
 
                x2 = x1 + deltaX / 3;
                y2 = y1 + deltaY / 3;
 
                x3 = (int) (0.5 * (x1+x5) + sqrt(3) * (y1-y5)/6);
                y3 = (int) (0.5 * (y1+y5) + sqrt(3) * (x5-x1)/6);
 
                x4 = x1 + 2 * deltaX /3;
                y4 = y1 + 2 * deltaY /3;
 
                koch (it-1, x1, y1, x2, y2);
               koch (it-1, x2, y2, x3, y3);
                koch (it-1, x3, y3, x4, y4);
                koch (it-1, x4, y4, x5, y5);

 
}
}

  void fractal::draw()
  {
   //int x1,x2,y1,y2,n;

   cout<<"\n\tEnter The No Of Iteration:=>";
   cin>>n;
  /* cout<<"\n\tEnter The three vertices of equilateral triangle:=>";
   cin>>x1>>y1>>x2>>y2>>x3>>y3;*/

	
	koch(n,280,280,150,20);
 koch(n,20,280,280,280);
	koch(n,150,20,20,280);



  }

int main()
{

    fractal f;
    f.initgr();
    f.draw();
getch();
    f.close();

 
 return 0;
}  


