#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<graphics.h>
#include<stdlib.h>
void cross(int A,int B)
{ line(A-40,B-40,A+40,B+40);
  line(A+40,B-40,A-40,B+40);
  }
void bnaobhyi(int i,int j,int A[][3],int poly[])
{ fillpoly(4,poly);
   if(A[i][j]==9)
{setcolor(WHITE);circle(100+(100*j),100+(100*i),40);
}
else if(A[i][j]==1)
{setcolor(WHITE);cross(100+(100*j),100+(100*i));}
}
int evaluate(int A[][3],int *score, char *shape,int poly[],int I,int J)
{ int i,j, a,b,result=0;

if(A[0][0]==A[1][1]&&A[1][1]==A[2][2]&&A[0][0]!=0)
{ setfillstyle(SOLID_FILL,BLACK);
 bnaobhyi(I,J,A,poly);setcolor(RED);line(100,100,300,300);
if(A[0][0]==9)if(strcmp(shape,"circle")==0)score[0]++;else score[1]++;
else if(strcmp(shape,"cross")==0)score[0]++;else score[1]++;
 result=1;}
if(A[0][2]==A[1][1]&&A[1][1]==A[2][0]&&A[0][2]!=0)
{ setfillstyle(SOLID_FILL,BLACK);
 bnaobhyi(I,J,A,poly);setcolor(RED);line(300,100,100,300);
if(A[0][2]==9)if(strcmp(shape,"circle")==0)score[0]++;else score[1]++;
else if(strcmp(shape,"cross")==0)score[0]++;else score[1]++;
result=1;}
for(i=0;i<3;i++)
{a=b=0;a=A[i][0];b=A[0][i];
  for(j=0;j<3;j++)
 if(a!=A[i][j]&&b!=A[j][i])break;
if(j==3)
{
 if(A[i][j-2]==A[i][j-1]&&A[i][j-2]==a&&a!=0)
 {if(a==9&&a!=0)if(strcmp(shape,"circle")==0)score[0]++;else score[1]++;
else if(a!=0)if(strcmp(shape,"cross")==0)score[0]++;else score[1]++;
setfillstyle(SOLID_FILL,BLACK);
 bnaobhyi(I,J,A,poly);setcolor(RED);line(100,100+i*100,300,100+i*100);
 result=1;}
 if(A[j-2][i]==A[j-1][i]&&A[j-2][i]==b&&b!=0)
 {if(b==9&&b!=0)if(strcmp(shape,"circle")==0)score[0]++;else score[1]++;
else if(b!=0)if(strcmp(shape,"cross")==0)score[0]++;else score[1]++;
setfillstyle(SOLID_FILL,BLACK);
 bnaobhyi(I,J,A,poly);setcolor(RED);line(100+i*100,100,100+i*100,300);
result=1;}
   }
 } setcolor(WHITE);
 return result;
}
int main(void)
{
int gd=DETECT,gm,poly[8],A[3][3]={0,0,0,0,0,0,0,0,0},score[2];
int i,turn=0,a=1;
char ch;

char shape[8],shape2[8],mov; int j;
score[0]=score[1]=0;
    clrscr();
while(1)
{printf("\nplayer 1: cross/circle\n");
gets(shape); clrscr();
if(strcmp(shape,"cross")==0)
{strcpy(shape2,"circle");break;}
else if(strcmp(shape,"circle")==0)
{strcpy(shape2,"cross");break;}
else
printf("wrong choice try again");
}
printf("So...\n%s for player 1 \n%s for player 2\n",shape,shape2);
printf("enter any key to start game");
getch();
initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

setlinestyle(SOLID_LINE,1,3);
for(i=0;i<=200;i=i+100)
{for(j=0;j<=200;j=j+100)
rectangle(50+j, 50+i,150+j, 150+i);
}
poly[0]=50;poly[1]=50;
poly[2]=50;poly[3]=150;
poly[4]=150;poly[5]=150;
poly[6]=150;poly[7]=50;
       i=0;j=0;

while(1)
{setfillstyle(SOLID_FILL, GREEN);
 bnaobhyi(i,j,A,poly);
 if( evaluate( A,score,shape,poly,i,j))break;

 if(turn==9){setfillstyle(SOLID_FILL,BLACK),bnaobhyi(i,j,A,poly);break;}

 if(a==1)
 {gotoxy(22,25);
 if(turn%2==0) printf("player 1");
 else
 printf("player 2"); }

 mov=getch();
 if(mov==0)
  mov=getch();


 if(mov==77&&j<2)
  { setfillstyle(SOLID_FILL,BLACK); bnaobhyi(i,j,A,poly);
 poly[0]+=100;poly[2]+=100;poly[4]+=100;poly[6]+=100; j++;a=0;}
 else if(mov==80&&i<2)
{setfillstyle(SOLID_FILL,BLACK); bnaobhyi(i,j,A,poly);
poly[1]+=100;poly[3]+=100;poly[5]+=100;poly[7]+=100;i++;a=0;}
 else if(mov==75&&j>0)
{setfillstyle(SOLID_FILL,BLACK); bnaobhyi(i,j,A,poly);
poly[0]-=100;poly[2]-=100;poly[4]-=100;poly[6]-=100; j--;a=0;}
else if(mov==72&&i>0)
{setfillstyle(SOLID_FILL,BLACK); bnaobhyi(i,j,A,poly);
poly[1]-=100;poly[3]-=100;poly[5]-=100;poly[7]-=100;i--;a=0;}
else if(mov==13&&A[i][j]!=9&&A[i][j]!=1)
	if(turn%2!=0)
	{turn++;
	if(strcmp(shape,"cross")==0)
	A[i][j]=9;
	else A[i][j]=1;a=1;}
	else
	  {turn++;
	  if(strcmp(shape2,"circle")==0)A[i][j]=1;
	  else A[i][j]=9;a=1;}
else a=0;


}
//evaluate(A,score,shape);
gotoxy(18,23);
printf("score :: player 1= %d",score[0]);
gotoxy(18,24);
printf("score :: player 2= %d",score[1]);
gotoxy(18,25);
score[0]>score[1]?printf("winner:: player 1"):score[0]<score[1]?printf("winner:: player 2"): printf("winner:: no one"); getch();


   closegraph();
   return 0;
}
