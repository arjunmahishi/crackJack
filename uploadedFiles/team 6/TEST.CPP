#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<dos.h>
struct node
{
    char text[100];
    node *next;
};
struct node *head,*temp;
void insert()
{
    struct node *temp=new node;
    cout<<"\nEnter the file name: (.txt) ";
    cin>>temp->text;
    if(head==NULL)
    {
	head=temp;
	temp->next=NULL;
    }
    else
    {
	temp->next=head;
	head=temp;
    }
    cout<<"\nData inserted\n";
}
/*void del(char n[])
{
    temp=head;
    if(temp==NULL)
    {
	cout<<"\nNode is empty";
    }
    else
    {
	while(temp)
	{
	temp=temp->next;
	if(strcmp(n,temp->text)==0)
	{
	head=temp->next;
	temp->next=NULL;
	}
	}
    }
    cout<<"\n";
} */
void disp()
{
    temp=head;
    if(head==NULL)
    {
	cout<<"\nNode is empty";
    }
    else
    {
	while(temp)
	{
	    cout<<temp->text<<" ";
	    temp=temp->next;
	}
    }
    cout<<"\n";
}
void main()
{
    int sel;
    char str[1000],fname[100];
    clrscr();
    while(1)
    {
	cout<<"\n1.Insert File name(.txt)";
       //	cout<<"\n2.Deletion";
	cout<<"\n2.Display File Names";
	cout<<"\n3.Insert data in Text file: ";
	cout<<"\n4.Show Particular file Details: ";
	cout<<"\n5.Modify a file: ";
	cout<<"\n6.Exit";
	cout<<"\nEnter your selection: ";
	cin>>sel;
	if(sel==1)
	{
	    clrscr();
	    insert();
	}
       /*	else if(sel==2)
	{
	    cout<<"\nEnter the file name: ";
	    cin>>ch;
	    del(ch);
	}*/
	else if(sel==2)
	{   clrscr();
	    cout<<"\nFiles in the system are: \n";
	    disp();
	}
	else if(sel==3)
	{       clrscr();
		cout<<"\nEnter the file name(.txt): ";
		cin>>fname;
		ofstream outfile;
		outfile.open(fname,ios::app);
		cout<<"\nEnter details: ";
		cin>>str;
		outfile<<str;
	}
	else if(sel==4)
	{       clrscr();
		cout<<"\nEnter the file name: ";
		cin>>fname;
		cout<<"\nLOADING DATA";
		for(int i=0;i<10;i++)
		{
			delay(100);
			cout<<".";
		}
		cout<<"\n";
		char getdata[1000];
		ifstream openfile(fname);
		while(!openfile.eof())
		{
			openfile>>getdata;
			cout<<getdata<<endl;
		}
	}
	else if(sel==5)
	{       clrscr();
		fstream file;
		cout<<"\nEnter the file to be modified: ";
		cin>>fname;
		file.open(fname,fstream::out|fstream::trunc);
		cout<<"\nOld contents deleted";
		cout<<"\nEnter New details details: ";
		cin>>str;
		file<<str;
		file.close();
	}
	else if(sel==6)
	{
	    break;
	}
	else
	{
	    cout<<"\nEnter correct selection\n";
	}
    }

    getch();
}
