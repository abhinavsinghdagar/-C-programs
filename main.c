#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ncurses.h>
#include <stdlib.h>
 int getabhi();
 int getabhi()
{
    int c;
    scanf("%d",&c);
    return c;
}

void errorcol(); // ANSI codes
void successcol();
void reset();
void errorcol()
{
  printf("\033[1;31m");

}

void successcol()
{

  printf("\033[1;32m");
}
void reset()
{

printf("\033[1;33m");
}
void menu();
void add();
void search();
void list();
void deleterec();
void modify();
FILE *f1;
struct contact
{
    char name[30];
    long int pn;
    char addr[40];
    long int aadhar;
    char sex[8];
    char mail[100];
    char father_name[35];
    char mother_name[30];
};
void menu()
{
    int c;
    system("clear");
    reset();

    printf("***************************************AB's PHONEBOOK**********************************************************************************************\n");
    printf("\t\t\t\t\t\t  MENU\n\t\t\t\t\t\t  1.Add\n\t\t\t\t\t\t  2.Search\n\t\t\t\t\t\t  3.Modify\n\t\t\t\t\t\t  4.Delete\n\t\t\t\t\t\t  5.List\n\t\t\t\t\t\t  6.Exit\n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d",&c);

    switch(c)
    {
    case 1:
        add();
        break;
    case 2:
        search();
        break;
    case 3:
        modify();
        break;
    case 4:
        deleterec();
        break;
    case 5:
        list();
        break;
    case 6:
        exit(0);
    default:
       {
        errorcol();
                printf("INVALID CHOICE ! enter a valid choice");
        printf("\n Press any key to continue ");
        getabhi();
        menu();
       }
    }
}
void add()
{
    fflush(stdin);
    fflush(stdin);
    system("clear");
    fflush(stdin);
    f1=fopen("/home/abhinav/Desktop/C program/pho/phab.dat","ab");
    struct contact c1;
    system("clear");
    printf("Enter the following data :\n");
     fflush(stdin);
    printf("Enter Contact name :");//i am out ideas
    fflush(stdin);
    //scanabhi(c1.name);
    scanf("%s",c1.name);
    fflush(stdin);
    printf("\nEnter Contact no. : ");
    scanf("%ld",&c1.pn);
    fflush(stdin);// yeh coede dsai hai bas end se faltu record hata de manually

    printf("Enter Sex : ");
    scanf("%s",c1.sex);//getabhi just doesnt work here dunno why.it works perfectly fine in another file but not here.reason is beyond the scope of my knowledge
    //that doesnt matter

    fflush(stdin);
    printf("Enter Email-id : ");
    scanf("%s",c1.mail);
    fflush(stdin);
    printf("Enter Father's name : ");
    scanf("%s",c1.father_name);
    fflush(stdin);
    printf("Enter Mother's name : ");
    scanf("%s",c1.mother_name);
    fflush(stdin);
    printf("\nEnter Aadhar no. : ");
    scanf("%ld",&c1.aadhar);
     fflush(stdin);
    printf("\nEnter Address : ");
    fflush(stdin);
    scanf("%s",c1.addr);
    //scanabhi(c1.addr);
    fflush(stdin);
    fwrite(&c1,sizeof(c1),1,f1);
    system("clear");
    successcol();
    printf("\aRECORD ADDED SUCCESSFULLY!");
    fclose(f1);
    printf("\n Press any key to continue ");
   getabhi();
    menu();
}
void modify()
{
int flag=0,e=0;
char name[30];
struct contact s,c1;
f1=fopen("/home/abhinav/Desktop/C program/pho/phab.dat","rb+"); // rb+ mode means read & open
if(f1==NULL)
{
    errorcol();
    printf("\a\a\aDATA HAS NOT BEEN ADDED YET !");
    printf("\n Press any key to continue ");
    getabhi();
    menu();
}
else
    {
            system("clear");
            printf("Enter name of contact which has to be modified : ");
             fflush(stdin);
            scanf("%s",name);
            fflush(stdin);

            while(fread(&s,sizeof(struct contact),1,f1))
            {
                if(strcmp(s.name,name)==0)
                {
                        flag=1;
                        printf("Enter the new data for this record : \n");
                        printf("Enter Contact name : ");
                        scanf("%s",c1.name);
                        fflush(stdin);
                        printf("\nEnter Contact no. : ");
                        scanf("%ld",&c1.pn);
                        fflush(stdin);
                        printf("Enter Sex : ");
                        scanf("%s",c1.sex);
                        fflush(stdin);
                        printf("Enter Email-id : ");
                        scanf("%s",c1.mail);
                        fflush(stdin);
                        printf("Enter Father's name : ");
                        scanf("%s",c1.father_name);
                        fflush(stdin);
                        printf("Enter Mother's name : ");
                        scanf("%s",c1.mother_name);
                        fflush(stdin);
                        printf("\nEnter Aadhar no. : ");
                        scanf("%ld",&c1.aadhar);
                        fflush(stdin);
                        printf("\nEnter Address : ");
                        scanf("%s",c1.addr);
                        fflush(stdin);
                        fseek(f1,-sizeof(c1),SEEK_CUR);
                        fwrite(&c1,sizeof(c1),1,f1);
                        fclose(f1);
                        system("clear");
                        successcol();
                        printf("\aRECORD MODIFIED SUCCESSFULLY!");
                         printf("\n Press any key to continue ");
                    getabhi();
                    menu();


                }
                else
                    e++;
            }
            if(flag==0)
            {
                    errorcol();
                printf("\a\a\aNo Such record found!");
                fclose(f1);
                printf("\n Press any key to continue ");
                    getabhi();
                    menu();

            }

    }

}
void deleterec()
{
    struct contact p;
	int flag=0;
	char name[100];
	FILE *f2;
	f1=fopen("/home/abhinav/Desktop/C program/pho/phab.dat","rb");
	if(f1==NULL)
		{
    fclose(f1);
   errorcol();
    printf("\a\a\aDATA HAS NOT BEEN ADDED YET !");
    printf("\n Press any key to continue ");
    getabhi();
    menu();

		}
	else
	{
		f2=fopen("/home/abhinav/Desktop/C program/pho/temp.dat","wb+");
		printf("\nEnter CONTACT'S NAME: ");
		fflush(stdin);
		scanf("%s",name);
		fflush(stdin);
		while(fread(&p,sizeof(p),1,f1))
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,f2);
			if(strcmp(p.name,name)==0)
                flag=1;
		}
	fclose(f1);
	fclose(f2);
	if(flag!=1)
	{
	    errorcol();
		printf("\n\a\a\aNO CONACT'S RECORD TO DELETE.");
		remove("/home/abhinav/Desktop/C program/pho/temp.dat");
	}
		else
		{
			remove("/home/abhinav/Desktop/C program/pho/phab.dat");
			rename("/home/abhinav/Desktop/C program/pho/temp.dat","/home/abhinav/Desktop/C program/pho/phab.dat");
            successcol();
			printf("\n\a\a\aRECORD DELETED SUCCESSFULLY.");

		}

}
 printf("\nEnter Any Key to continue");

	 getabhi();
    system("clear");
menu();
}

void list()
{
    struct contact p;
f1=fopen("/home/abhinav/Desktop/C program/pho/phab.dat","rb");
if(f1==NULL)
{
errorcol();
fclose(f1);
printf("\a\a\aFile contains 0 records:");
    printf("\n Press any key to continue ");
    getabhi();
    menu();
}
else
{
while(fread(&p,sizeof(p),1,f1)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
    printf("\nName: %s\nAdress: %s\nFather Name: %s\nMother Name: %s\nMobile Number: %ld\nGender: %s\nE-Mail: %s\nAadhar No: %ld",p.name,p.addr,p.father_name,p.mother_name,p.pn,p.sex,p.mail,p.aadhar);
    printf("\nPress any key to view the next record ");
	 getabhi();
	 system("clear");
}
}
fclose(f1);
    printf("\a\a\aPress any key to continue ");
    getabhi();
    menu();
}
void search()
{
int ct=0;
struct contact p;
char name[100];

f1=fopen("/home/abhinav/Desktop/C program/pho/phab.dat","rb");
if(f1==NULL)
{
    errorcol();
printf("\a\a\aFile contains 0 records:");
fclose(f1);
    printf("\n Press any key to continue ");
    getabhi();
    menu();
}
printf("\nEnter Name of the Person to Search\n");
fflush(stdin);
scanf("%s",name);
while(fread(&p,sizeof(p),1,f1)==1)
{
    if(strcmp(p.name,name)==0)
    {
        ct=1;
        printf("\n\n\n YOUR RECORD IS\n\n ");
    printf("\nName: %s\nAdress: %s\nFather Name: %s\nMother Name: %s\nMobile Number: %ld\nGender: %s\nE-Mail: %s\nAadhar No: %ld",p.name,p.addr,p.father_name,p.mother_name,p.pn,p.sex,p.mail,p.aadhar);
    printf("\n Press any key to continue ");
                    getabhi();
                    menu();

    }

}
if(ct==0)
            {
                    errorcol();
                    fclose(f1);
                printf("\a\a\aNo Such record found!");
                printf("\n Press any key to continue ");
                    getabhi();
                    menu();

            }
}
int main()
{

    char title[]="***************************************\t\tAB's PHONEBOOK\t\t***********************************************\n";
     reset();
    menu();
    return 0;
}
