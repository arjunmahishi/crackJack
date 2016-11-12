#include <stdio.h>
#include <stdlib.h>

void Menu();
void name();
void delete();
void export();

struct element{
    char name[20];
    char gender[20];
    char crime[20];
}profile;

int main(void){
    int a;

    for(a=0;a<4;a++){
       Menu();
    }
    return 0;
}

void Menu()
{
    int n;
    printf("\nMAIN MENU-STAFF INFORMATION SYSTEM");
    printf("\n1. Add profile villain Profile");
    printf("\n2. Delete villain Profile");
    printf("\n3. Export All Profiles to 'vidheesh.txt'");
    printf("\n4. Exit");
    printf("\nPlease enter your option");
    scanf("%d", &n);

    switch(n){
    case 1:
	name();
	break;
    case 2:
	delete();
	break;
    case 3:
	export();
	break;
    case 4:
	printf("\nThanks");
	exit(0);
	break;
    default:
	printf("\nError! Wrong Number is Entered\nPlease Try Again");
	break;
    }
}

void name()
{
    int x;
    struct element profile;

    printf("\n\nPlease enter the following criminal information.");

    printf("\n\ncity: ");
    scanf("%s", &profile.name);

    printf("Name\t: ");
																																																																																																												    fflush(stdin);
    fgets(profile.name,20,stdin);

    for(x=0 ; x<20 ; x++)
    {
    if(profile.name[x] == '\n')
	profile.name[x] = '\0';
    }

    printf("Gender\t: ");
    scanf("%s", &profile.crime);


    printf("\nSYSTEM: New criminal Profile is Added Successfully.");

}

void delete()
{
    FILE *fRead, *fWrite;
    char *TextFile;
    char c;
    int Delete, temp = 1;

    TextFile="vidheesh.txt";

    fRead = fopen(TextFile, "r");
    c = getc(fRead);

    while (c != EOF){
    printf("%c", c);
    c = getc(fRead);
    }

    rewind(fRead);

    printf("\nDelete criminal");
    scanf("%d", &Delete);

    Delete=Delete+1;

    fWrite = fopen("copy.c", "w");
    c = getc(fRead);
    while (c != EOF) {
    c = getc(fRead);
    if (c == '\n')
    temp++;
    if (temp != Delete)
    {
    putc(c, fWrite);
       }
    }

    fclose(fRead);
    fclose(fWrite);

    remove(TextFile);

    rename("copy.c", TextFile);
    printf("\nThe contents of file after being modified are as follows:\n");

    fRead = fopen(TextFile, "r");
    c = getc(fRead);
    while (c != EOF) {
    printf("%c", c);
    c = getc(fRead);
    }

    fclose(fRead);
}

void export()
{
    struct element profile;

    FILE *fPtr;
    FILE *fPtr1;
    fPtr=fopen("vidheesh.txt","w");
    fPtr1=fopen("vidheesh.txt","a+");

    if (fPtr == NULL)
    printf("Error in opening file\n");
    if (fPtr1 == NULL)
    printf("Error in opening file\n");

    fprintf(fPtr,"%10s ",
	     name);

    fprintf(fPtr1,"\n%10s %10s" , profile.name,profile.gender);

    printf("\n%10s %10s","Name","Gender");
    printf("\n% %10s %10s", profile.name, profile.gender);

    printf("\nSYSTEM: All crime profile have been exported to output.txt file");

    fclose(fPtr);
    fclose(fPtr1);
}
