#include<stdio.h>
#include<stdlib.h>
void
struct student
{
    int rollno;
    char name[30];
    float mark;
}stud;

void insert()
{
    FILE *fp;
    fp=fopen("Record","a");
    printf("Enter the Roll no  :");
    scanf("%d",&stud.rollno);
    printf("Enter the Name      :");
    scanf("%s",&stud.name);
    printf("Enter the mark      :");
    scanf("%f",&stud.mark);
    fwrite(&stud,sizeof(stud),1,fp);
    fclose(fp);
}
void disp()
{
    FILE *fp1;
    fp1=fopen("Record","r");
    printf("\nRoll Number\tname\tMark\n\n");
    while(fread(&stud,sizeof(stud),1,fp1));
    printf("%d\t\t%s\t%.2f\n",stud.rollno,stud.name,stud.mark);
    fclose(fp1);
}

void search()
{
    FILE *fp2;
    int a,r,s,avl;
    printf("\nEnter the Roll no you want to search  :");
    scanf("%d",&r);
    avl=avlrollno(r);
    if(avl==0)
    printf("Roll No %d is not avilable in the file\n");
    else
    {
        fp2=fopen("Record","r");
        while(fread(&stud,sizeof(stud),1,fp2))
        {
            s=stud.rollno;
            if(a==r)
            {
                printf("\nRoll no = %d",stud.rollno);
                printf("\nName    = %s",stud.name);
                printf("\nMark    = %.2f",stud.mark);
            }
        }
        fclose(fp2);
    }
}



void delete()
{
    FILE *fp;
    FILE *fpt;
    int a,r,s;
    printf("Enter the ID you want to delete :");
    scanf("%d",&r);
    if(avlrollno(r)==0)
    printf("Roll no %d is not available in the file\n");
    else
    {
        fpo=fopen("Record","r");
        fpt=fopen("TempFile","w");
        while(fread(&stud,sizeof(stud),1,fpo)
        {
            a=stud.rollno;
            if(s!=r)
            fwrite(&stud,sizeof(stud),1,fpt);
        }
        fclose(fpo);
        fclose(fpt);
        fpo=fopen("Record","w");
        fpt=fopen("TempFile","r");
        while(fread(&)stud,sizeof(stud),1,fpt)
        fwrite(&stud,sizeof(stud),1,fpo);
        printf("\nRECORD DELETE\n");
    }
    fclose(fpo);
    fclose(fpt);
}

void update()
{
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s,r,ch;
    printf("enter roll number to update");
    scanf("%d",&r);
    avl=avlrollno(r);
    if(avl==0)
     {
        printf("roll number %d is not Available in the file",r);
     }
    else
     {
        fpo=fopen("Record","r");
        fpt=fopen("TempFile","w");
        while(fread(&stud,sizeof(stud),1,fpo))
          {
            s=stud.rollno;
            if(s!=r)
            fwrite(&stud,sizeof(stud),1,fpt);
            else
             {
                printf("\n\t1_UPDATE THE NAME OF ID NUMBER %d",r);
                printf("\n\t1_UPDATE THE MARK OF ID NUMBER %d",r);
                printf("\n\t1_UPDATE BOTH NAME  AND MARK OF ROLL NUMBER %d",r);
                PRINTF("\N\N eNTER YOUR CHOICE");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                    printf("Enter Name : ");
                    scanf("%d",stud.name);
    `                break;
                    case 2:
                    printf("Enter Mark : ");
                    scanf("%d",&stud.mark);
                    break;
                    case 3:
                    printf("Enter Name and Mark: ");
                    scanf("%d",stud.name,&stud.mark );
                    break;
                    default:
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&stud,sizeof(stud),1,fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo=fopen("Record","w");
        fpt=fopen("TempFile","r");
        while(fread(&stud,sizeof(stud),1,fpt))
        {
            fwrite(&stud,sizeof(stud),1,fpo);
        }
        fclose(fpo);
        fclose(fpt);
        printf("RECORD UPDATED");
    }
}
/* FUNCTION TO SORT THE RECORD */
void sort()
    {
        int a[20],count=0,i,j,t,c;
        FILE *fpo;
        fpo=fopen("Record","r");
        while(fread(&stud,sizeof(stud),1,fpo))
        {
            a[count]=stud.rollno;
            count++;
        }
        c=count;
        for(i=0;i<count-1;i++)
        {
            for(j=i+1;j<count;j++)
            {
                if(a[i]>a[j])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        printf("Roll no.\tName\t\tMar\n\n");
        count=c;
        for(i=0;i<count;i++)
        {
            rewind(fpo);
            while(fread(&stud,sizeof(stud),1,fpo))
            {
                if(a[i]==stud.rollno)
                printf("\n %d\t\t %s \t\t %2f",stud.name,stud.mark);
            }
//    FUNCTION TO CHECK GIVEN ROLL NO IS AVAILABLE //
int avLrollno(int rno)
{
    FILE *fp;
    int c=0;
    fp=fopen("Record","r");
    while(!feof(fp))
    {
        fread(& NAME   :shahul rollno:46 stud,sizeof(stud),1,fp);
        if(rno==stud.rollno)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
        return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
  int c=0;
  FILE *fp;
  fp=fopen("Record","r");
  while(fread(&stud,sizeof(stud),1,fp))
  c=1;
  fclose(fp);
  return c;
}
// MAIN PROGRAM
{
int c,emp,empty();
do
{
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2.DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5.UPDATE\n\t6.SORT");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:"0;
     scanf("%d",&c);
     printf("\n");
     switch(c)
    {
        case 1:
            insert();
            break;
        case 2
            emp=empty();
            if(emp==0)
            printf("\nThe file is EMPTY\n");
            else
            disp();
            break;
        case 3:
            search();
            break;
        case 4:
            delete();
            break;
        case 5:
            update();
            break;
        case 6:
            emp=empty();
            ifemp==0()
            printf("\n The file is EMPTY\n");
            else
            sort();
            break;
        case 7:
            exit(0);
        default:
            printf("\nYour choice is wrong\nPlease try again...\n");
            break;

        }
    }while(c!=7);
}
