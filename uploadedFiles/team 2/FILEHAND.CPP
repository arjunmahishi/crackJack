#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<process.h>

   int men=0;
   int N,ns,nb,nl,p;
   void writecontract();
   void modifycontract();
   void dispcontract();
   void Main_menu();
   void del();



   class addmoney
   {
      char Sname[30];
      char Smoney[30];
      char Rno[30];


      public:

	 void add()
    {	    cout<<"Enter Rno"<<endl;
	    gets(Rno);
	    cout<<"Enter name:"<<endl;
	    gets(Sname);
	    cout<<"Enter Money"<<endl;
	    gets(Smoney);

		 }
	 void disp()
	 {

	    cout<<"Name:"<<endl;
	    puts(Sname);
	    cout<<"Money:"<<endl;
		    puts(Smoney);
	 }



	 char* getsname()
	 {
	    return Sname;
	 }

	 char* getrno()
	 {
	    return Rno;
	 }


   }i1;

   void writecontract()
     {
     fstream f;
      gotoxy(1,1);
      char ch[50];
      f.open("Contracts.dat",ios::app|ios::binary);
      i1.add();
      f.write((char*)&i1,sizeof(addmoney));
      cout<<"Record added."<<endl;
      cout<<"Do You Want To Enroll Another Record? Type Y/N"<<endl;
      cin>>ch;
      if(!((strcmpi(ch,"Y"))))
	 {
	   f.close();
	   cleardevice();
	   writecontract();
	 }
	 f.close();
   }
   void modifycontract()
   {
      fstream f;
      gotoxy(1,1);
      char no[30];
      char ch[50];
      int found=0;
      f.open("Contracts.dat",ios::in|ios::binary|ios::out);
      if(!f)
      {
	cout<<"File Not opened"<<endl;
	getch();
      }
      cout<<"Enter Roll:"<<endl;
      gets(no);
      while(f.read((char*)&i1,sizeof(i1)))
	 {
	 if(strcmpi(i1.getrno(),no)==0)
	    {
	       found=1;
	       cout<<"Data to be modified:"<<endl;
	       i1.disp();
	       cout<<endl<<endl<<"Enter New Data"<<endl;
	       i1.add();
	       f.seekp(-1*(signed)sizeof(i1),ios::cur);
	       f.write((char*)&i1,sizeof(i1));
	       cout<<"Record Added"<<endl;
	    }
	 }
      f.close();

     if(found==0)
	{
	   cout<<"Record does not exist"<<endl;
	   cout<<"Do You Want To Try Again?? Type(Y/N)"<<endl;
	   cin>>ch;
	}
      else
	{
	   cout<<"Do You Want To Add More?? Type(Y/N)"<<endl;
	   cin>>ch;
	}
      if(!((strcmpi(ch,"Y"))))
      {   cleardevice();
	  modifycontract();
      }
    }
  /*  void del()
    {
      fstream f;
      gotoxy(1,1);
      char no[30];
      char ch[50];
      int found=0;
      f.open("Contracts.dat",ios::in|ios::binary|ios::out);
      if(!f)
      {
	cout<<"File Not opened"<<endl;
	getch();
      }
      cout<<"Enter Roll:"<<endl;
      gets(no);
      while(f.read((char*)&i1,sizeof(i1)))
	 {
	 if(strcmpi(i1.getrno(),no)==0)
	    {
	       found=1;
	       cout<<"Data to be deleted:"<<endl;
	       i1.disp();
	       f.seekp(-1*(signed)sizeof(i1),ios::cur);
	       f.write((char*)&i1,sizeof(i1),ios::end);
	       cout<<"Record Deleted"<<endl;
	    }
	 }
      f.close();

     if(found==0)
	{
	   cout<<"Record does not exist"<<endl;
	   cout<<"Do You Want To Try Again?? Type(Y/N)"<<endl;
	   cin>>ch;
	}
      else
	{
	   cout<<"Do You Want To Add More?? Type(Y/N)"<<endl;
	   cin>>ch;
	}
      if(!((strcmpi(ch,"Y"))))
      {   cleardevice();
	  del();
      }
    }  */


   void dispcontract()
   {
   cleardevice();
      fstream f;
      gotoxy(1,1);
      char no[30],ch[50];
      int found=0;
      f.open("Contracts.dat",ios::in|ios::binary|ios::out);
      cout<<"Enter Roll"<<endl;
      gets(no);
      if(!f)
      {
	 cout<<"File Not opened"<<endl;
	 getch();
	 return;
      }
      while(f.read((char*)&i1,sizeof(i1)))
      {

	 if(strcmpi(i1.getrno(),no)==0)
	 {
	   found=1;
	   cout<<"Contract Details:"<<endl;
	   i1.disp();
	 }
      }

     if(found==0)
     {
	cout<<"Record does not exist"<<endl;
	cout<<"Do You Want To Try Again Type Y/N"<<endl;
	cin>>ch;
     }
     else
     {
	cout<<"Do You Want To Display Another Record? Y/N"<<endl;
	cin>>ch;
     }
     if(!((strcmpi(ch,"Y"))))
     {
	f.close();
	cleardevice();
	dispcontract();
     }
     f.close();
     }


    void Main_menu()
    {
      int x=getmaxx();
      int y=getmaxy();
      cleardevice();
      setbkcolor(4);
      outtextxy(3*(x/8),y/8,"WELCOME TO Contracts DEADSHOT");
      outtextxy(2*(x/8),3*(y/10),"1.Add");
      outtextxy(2*(x/8),5*(y/10),"2.Display");
      outtextxy(2*(x/8),6*(y/10),"3.Modify");
      outtextxy(2*(x/8),7*(y/10),"4.Exit");
      outtextxy(56*(x/64),50*(y/64),"Developed By Team 2");
      outtextxy(58*(x/64),58*(y/64),"Rishi");
      outtextxy(58*(x/64),62*(y/64),"Amrita");
      outtextxy(58*(x/64),64*(y/64),"Shriram");
      cin>>ns;
      if(ns==1)
       {
	 cleardevice();
	 writecontract();
	 Main_menu();
       }

       else if(ns==2)
       {
	 cleardevice();
	 dispcontract();
	 Main_menu();
       }
       else if(ns==3)
       {
	 cleardevice();
	 modifycontract();
	 Main_menu();

       }
       else if(ns==4)
       exit(0);
    }
   void main()
   {
    clrscr();
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\bgi");
    int x=getmaxx();
    int y=getmaxy();
    cleardevice();
    setbkcolor(2);
    outtextxy(3*(x/7),(y/2),"LOADING..."); //Loading Screen
    delay(1000);
    setbkcolor(0);
    cleardevice();
    int l=getmaxx()/2;
    int	m=getmaxy()/2;
    setcolor(15);
   outtextxy(3*(x/8),6*(y/10),"Welcome Deadshot!");
    outtextxy(3*(x/8),7*(y/10),"Press Any Key To Continue!");
    getch();
    cleardevice();
    Main_menu();
    getch();
   }







