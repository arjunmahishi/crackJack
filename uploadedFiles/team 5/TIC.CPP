#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void diagram()
{
for(int j=11;j<=15;j+=1)
  for(int i=40;i<=44;i++)
{     if ((j==11)||(j==13)||(j==15))
       {
	if((i==41)||(i==43))
       {	 gotoxy(i,j);
	cout<<"|";
	}
	}

else  if((i==40)||(i==42)||(i==44))
{gotoxy(i,j);
cout<<"-";}
else if((i==41)||(i==43))
{gotoxy(i,j);
cout<<"+";}
}
}

void placex(int a,char x )
{
if(a== 1 )
{gotoxy( 40 ,11  );
cout<<x;}
if(a== 2 )
{
gotoxy( 42 ,11  );
cout<<x; }
if(a== 3 )
{gotoxy( 44 ,11  );
cout<<x;}
if(a==4  )
{gotoxy(40  ,13  );
cout<<x;
}if(a== 5 )
{gotoxy(42  ,13  );
cout<<x;
}if(a== 6 )
{gotoxy( 44 ,13  );
cout<<x;
}if(a== 7 )
{gotoxy(40  ,15  );
cout<<x;
}if(a== 8 )
{gotoxy( 42 ,15  );
cout<<x;
}if(a== 9 )
{gotoxy( 44 ,15  );
cout<<x;
}
}
int check_availability( int check[],int num)
{           //     int present=0;
for(int i=0;i<9;i++)
{
if(check[i]==num)
{//cout<<"match" ;
//cout<<num<<" "<<check[i];
return 1;     }
}
return 0;
}
void win(int check[],int size)
{
int chek=0;

for(int i=0;i<size;i++)
{
cout<<"checking";
if((check[i]==1)||(check[i]==2)||(check[i]==3))
chek++;
cout<<check;
}
if(chek==3)
cout<<"win";

chek=0;
for( i=0;i<size;i++)
{
if((check[i]==4)||(check[i]==4)||(check[i]==6))
chek++;
}
if(chek==3)
cout<<"win";

chek=0;
for( i=0;i<size;i++)
{
if((check[i]==7)||(check[i]==8)||(check[i]==9))
chek++;
}

if(chek==3)
cout<<"win";
}





void main()
{  clrscr();
diagram();
gotoxy(1,23);
int player[5];int w=0;
int random;  int win1[5]={0,0,0,0,0};
int win2[4]={0,0,0,0};
randomize();int check[9]={0,0,0,0,0,0,0,0,0};int count=0;
for(int i=0;i<5;i++)
{
input:
cin>>player[i];
gotoxy(1,23);
if(check_availability(check,player[i])==1)
goto input ;
check[count]=player[i];
win1[w]=player[i];
count++;
placex(player[i],'x');
gotoxy(1,23);
win(win1,5);
input2:
random=rand()%9;
if(check_availability(check,random)==1)
goto input2;
check[count]=random;
win2[w]=random;
count++;
placex(random,'o');
gotoxy(1,23);

}


getch();
}
