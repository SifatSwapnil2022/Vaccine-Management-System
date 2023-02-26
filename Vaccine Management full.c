#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>
#include<time.h>


void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
void secondpage();



struct people
{
    char name[20];
    char mobile[20];
     char address[20];
    char  nidno[9];
    char gender[5];
    char injected[20];
};



int main(){
          generateOTP ();
          getch();

 passwords();
getch();
return 0;
}



void generateOTP ()
{
          char otp[5] , votp[5];
          int k,a;
          printf("    Hi  !!    Please , use the OTP code to enter the page .\n\n\n");
          srand((unsigned)time(NULL)); //srand(time(NULL));
//makes use of the computer's internal clock to control the choice of the seed.
// Since time is continually changing, the seed is forever changing.
// Remember, if the seed number remains the same, the sequence of numbers
// will be repeated for each run of the program.

          for(k=0 ; k<4 ; k++)
          {
                    a = rand()%10 + 48;  //48 means character value zero
                                          //rand() use for random numbers
                    otp[k]=a;
          }
          otp[k]='\0';   //storing null in the end
          printf("OTP Generated : %s",otp);
          printf("\n\nVerify OTP : ");
          scanf("%s",&votp);
          if(strcmp(otp,votp)==0)
          {
                    printf("OTP Verified.  Welcome !!  \n");
                    printf("press any key to enter the next page........");
          }
          else
          {
                   printf(" Warning !! OTP Not Verified. Please try again.............\n");
          }

}











void secondpage()
{
    system("cls");



    printf("                    ************************************** ");

    printf("\n                 *                                       *");

    printf("\n                 *               WELCOME                 *");

    printf("\n                 *                 TO                    *");

    printf("\n                 *            OUR SYSTEM  !!             *");

    printf("\n                 *                                       *");

    printf("\n                 *                                       *");

    printf("\n                 *                                       *");

    printf("\n                  *************************************** ");

    printf(" \n\n\n     powered by \tKM FAZLE RABBI AND MD SIFATULLAH SHEIKH.\n\n\n\n\n");


    gotoxy(25,15);
    printf("\t\t<<<------: Vaccine Record Management System :----->>>");
    gotoxy(30,25);
    printf(" # Press any key to continue..........");
    getch();
    menu();
    return 0;
}


void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void passwords(void)
{
system("cls");
char pass[10],ch,password2[10]="admin";
int i=0;
gotoxy(25,2);
printf("==== 'VACCINE' MANAGEMENT SYSTEM ====");
gotoxy(20,5);
printf("Enter the password to Login:");
//scanf("%s",pass);
while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8)
{
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';


if(strcmp(pass,password2)==0){
gotoxy(13,8);
    printf("Password Matched!!");
    gotoxy(14,9);
    printf("Loading ");
for(i=0;i<=6;i++)
        {
            fordelay(100000000);

            printf(".");
        }
                system("cls");
            menu();
        }
        else
        gotoxy(15,13);
        printf("Password is invalid!!\a");
        printf("\tENTER correct password");
        getch();
        main();
}








void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4 : Modify Record.");
    gotoxy(10,11);
    printf("5 : Delete.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct people std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");

        gotoxy(10,5);
        printf("Enter details of people."); //people


        gotoxy(10,7);
        printf("Enter Name : ");
        gets(std.name);

        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(std.mobile);

        gotoxy(10,9);
        printf("Enter NID No : ");
        gets(std.nidno);   //nidno
        fflush(stdin);

        gotoxy(10,10);
        printf("Enter Gender [M|F] : ");
        gets(std.gender);    //gender

        gotoxy(10,11);
        printf("Enter the vaccine injected  : ");
        gets(std.injected);   //injected

        gotoxy(10,12);
       printf("Enter your permanent Address : ");
       gets(std.address);    //address

        fwrite(&std,sizeof(std),1,fp);

        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);

        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct people std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   Name of people        Mobile No     NID No    Gender        Injected      Address ");
    gotoxy(10,6);
    printf("-----------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-13s%-13s%-13s%-11s%-11s",i,std.name,std.mobile,std.nidno,std.gender,std.injected,std.address);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct people std;
    char stname[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of people : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,8);
            printf("Name : %s",std.name);
            gotoxy(10,9);
            printf("Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("NID No : %d",std.nidno);
            gotoxy(10,11);
            printf("Gender : %s",std.gender);
            gotoxy(10,12);
            printf("Injected : %s",std.injected);
            gotoxy(10,13);
            printf("Permanent Address : %s",std.address);

        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct people std;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,7);
            printf("Enter name: ");
            gets(std.name);
            gotoxy(10,8);
            printf("Enter mobile number : ");
            gets(std.mobile);
            gotoxy(10,9);
            printf("Enter NID no : ");
            gets(std.nidno);
            gotoxy(10,10);
            printf("Enter Gender : ");
            fflush(stdin);
            gets(std.gender);
            gotoxy(10,11);
            printf("Enter Injected : ");
            fflush(stdin);
            gets(std.injected);
             gotoxy(10,12);
             printf("Enter Permanent Address: ");
            fflush(stdin);
            gets(std.address);

            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct people std;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt", "record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


