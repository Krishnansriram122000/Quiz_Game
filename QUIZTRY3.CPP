#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
class quiz
{
  char loc,c,sn[10][2],*dum[10],*dum1[10],*dum2[10],*dum3[10],qu[10][200],op1[10][25],op2[10][25],op3[10][25],crtop[10];
  int mark;
  public:
  quiz()
  { mark=0;}
  void quizgame();
  ~quiz()
  {
   delete dum,dum1,dum2,dum3;
   cout<<"hello";
  delay(1000);}
  };
void quiz::quizgame()
{ clrscr();
  int gd=DETECT,gm,x,y;

  union REGS p,q,r,s;
  initgraph(&gd,&gm,"c:\\turboc3\\bgi");
  setbkcolor(BLUE);
  int i,j,k;
  FILE *f;

  for(i=0;i<10;i++)
  { f=fopen("quiz.csv","r+");
    c=getc(f);
    randomize();
    k=0;
    j=rand()%100 +  1;
    while(c!=EOF)
    { if(c=='\n')k++;
      if(k==j)break;
      c=getc(f);
      }
    c=getc(f);
    for(int m=0;(c!=EOF);m++)
    { sn[i][m]=c;
      c=getc(f);
      if(c==',')break;
      }
    c=getc(f);
    for( m=0;(c!=EOF);m++)
    { qu[i][m]=c;
      c=getc(f);
      if(c==',')break;
      }
    dum[i]=new char[m+1];
    strcpy(dum[i],qu[i]);
    c=getc(f);
    for(m=0;(c!=EOF);m++)
    { op1[i][m]=c;
      c=getc(f);
      if(c==',')break;
      }
    dum1[i]=new char[m+1];
    strcpy(dum1[i],op1[i]);
    c=getc(f);
    for(m=0;(c!=EOF);m++)
    { op2[i][m]=c;
      c=getc(f);
      if(c==',')break;
      }
    dum2[i]=new char[m+1];
    strcpy(dum2[i],op2[i]);
    c=getc(f);
    for(m=0;(c!=EOF);m++)
    { op3[i][m]=c;
      c=getc(f);
      if(c==',')break;
      }
    dum3[i]=new char[m+1];
    strcpy(dum3[i],op3[i]);
    c=getc(f);
    for(m=0;(c!=EOF);m++)
    {
      c=getc(f);
      if(c==',')break;
      }
    c=getc(f);
    crtop[i]=c;
    fclose(f);

  outtextxy(0,60,dum[i]);
  outtextxy(0,100,dum1[i]);
  outtextxy(0,130,dum2[i]);
  outtextxy(0,160,dum3[i]);
  //outtextxy(0,getmaxy()-20,"previous");
  outtextxy(getmaxx()-40,getmaxy()-20,"next");
  p.x.ax=0x1;
  r.x.ax=0x5;
  r.x.bx=r.x.cx=r.x.dx=0;
  int86(0x33,&p,&q);
  s.x.bx=s.x.cx=s.x.dx=0;
  delay(5000);
  int86(0x33,&r,&s);
  cleardevice();
  int click;
  click=s.x.bx;
  if((click>0)&&(s.x.dx>=90)&&(s.x.dx<130) )
  {cleardevice();loc='a';}
  else if((click>0)&&(s.x.dx>=130)&&(s.x.dx<160))
  {cleardevice();loc='b';}
  else if((click>0)&&(s.x.dx>=160)&&(s.x.dx<=185))
  {cleardevice();loc='c';}
  //else if((click>0)&&(s.x.dx>getmaxy()-80)&&(s.x.dx<getmaxy())&&(s.x.cx<getmaxx()/2))
  //{cleardevice();cout<<"previous";}
  else
  {cleardevice();continue;}
  //printf("%d\t%d\t%d",s.x.bx,s.x.cx,s.x.dx);
  if(loc==crtop[i])
  mark+=10;
    }
  cleardevice();
  cout<<mark;
  delay(1500);
  closegraph();
  clrscr();
  }
void main()
{ {quiz g;
  //g =new quiz;
  g.quizgame();
  //delete g;
      }
  getch();
  }
