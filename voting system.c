#include <stdlib.h>
#include<stdio.h>
#include<string.h>


int session = 0;
int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0;
char CANDIDATE1[25]="EMPTY";
char CANDIDATE2[25]="EMPTY";
char CANDIDATE3[25]="EMPTY";
char CANDIDATE4[25]="EMPTY";
char user[10]="admin";//username == admin
char password[10]="admin1";//password == admin1


char adminE(){
    int choice;
    int tries;
    char cad1[25];
    char cad2[25];
    char cad3[25];
    char cad4[25];
    printf("\nWhich Candidate name do you want to change/edit?(1-4) : ");
    scanf("%d", &choice);
    if (choice==1)
    {
        fflush(stdin);
        printf("Enter/modify the name of the cadidate : ");
        gets(cad1);
        strcpy(CANDIDATE1,cad1);

    }
    else if (choice == 2)
    {
        fflush(stdin);
        printf("Enter/modify the name of the cadidate : ");
        gets(cad2);
        strcpy(CANDIDATE2,cad2);
    }
     else if (choice == 3)
    {
        fflush(stdin);
        printf("Enter/modify the name of the cadidate : ");
        gets(cad3);
        strcpy(CANDIDATE3,cad3);
    }
     else if (choice == 4)
    {
        fflush(stdin);
        printf("Enter/modify the name of the cadidate : ");
        gets(cad4);
        strcpy(CANDIDATE4,cad4);
    }
    else
    {
        printf("invalid input!!");
    }
}

void changecount(){
    int choice;
    int chang = 0;
    printf("Enter the cadidate of you want to change the vote count for : CADIDATE(1-4) ");
    scanf("%d", &choice);
    if (choice<=4 && choice >=1)
    {
        printf("enter the changes you wan to make to the number of votes : ");
        scanf("%d",&chang);

        if (choice == 1)
        {
            if (chang >= 0 )
            {
                votesCount1 = votesCount1 + chang;
            }
            else if (chang <= -1) // try to do something cool and this is what you end up with, fan-fucking-tastic
            {
                votesCount1 = votesCount1 - chang;
            }
        }
        if (choice == 2)
        {
            if (chang >= 0 )
            {
                votesCount2 = votesCount2 + chang;
            }
            else if (chang<= -1 )
            {
                votesCount2 = votesCount2 - chang;
            }
        }
        if (choice == 3)
        {
            if (chang >= 0 )
            {
                votesCount3 = votesCount3 + chang;
            }
            else if (chang<= -1)
            {
                votesCount3 = votesCount3 - chang;
            }
        }
        if (choice == 4)
        {
            if (chang >= 0 )
            {
                votesCount4 = votesCount4 + chang;
            }
            else if (chang<= -1)
            {
                votesCount4 = votesCount4 - chang;
            }
        }
    }
    else
    {
        printf("invalid choice!");
    }


}

void clearv()
{
    FILE *fptr;
    fptr=fopen("E:\\Voting.txt", "a+");
    int choice;
    int choice2;
    printf("Which canidates votes do you want to clear ? ");
    scanf("%d",&choice);
    if (choice == 1)
    {
        printf("ARE YOU SURE THAT YOU WANT TO CLEAR THE VOTES OF THIS CANDIDAE?       (1) for yes       (0) for no  : ");
        scanf("%d",&choice2);
        if (choice2 == 1)
        {
            votesCount1=0;
            printf("vote for %s have been cleared ", CANDIDATE1);
            fprintf(fptr,"\n\t\tvotes for %s have been cleared\t\t\n",CANDIDATE1);
        }
        else if (choice2==0)
        {
            return;
        }
    }
    if (choice == 2)
    {
        printf("ARE YOU SURE THAT YOU WANT TO CLEAR THE VOTES OF THIS CANDIDAE?(Y/N) ");
        scanf("%d",&choice2);
        if (choice2 ==1)
        {
            votesCount2=0;
            printf("vote for %s have been cleared ", CANDIDATE2);
            fprintf(fptr,"\n\t\tvotes for %s have been cleared\t\t\n",CANDIDATE2);
        }
        else if (choice2==0)
        {
            return;
        }
    }
    if (choice == 3)
    {
        printf("ARE YOU SURE THAT YOU WANT TO CLEAR THE VOTES OF THIS CANDIDAE?(Y/N) ");
        scanf("%d",&choice2);
        if (choice2 ==1)
        {
            votesCount3=0;
            printf("vote for %s have been cleared ", CANDIDATE3);
            fprintf(fptr,"\n\t\tvotes for %s have been cleared\t\t\n",CANDIDATE3);
        }
        else if (choice2==0)
        {
            return;
        }
    }
    if (choice == 4)
    {
        printf("ARE YOU SURE THAT YOU WANT TO CLEAR THE VOTES OF THIS CANDIDAE?(Y/N) ");
        scanf("%d",&choice2);
        if (choice2 ==1)
        {
            votesCount4=0;
            printf("vote for %s have been cleared ", CANDIDATE4);
            fprintf(fptr,"\n\t\tvotes for %s have been cleared\t\t\n",CANDIDATE4);
        }
        else if(choice2==0)
        {
            return;
        }
    }
    if (choice <1 && choice > 4)
    {
        printf("invalid choice!!");
        clearv();
    }
    fclose(fptr);
}

int susses()
{
    int press;
    printf("If you want to suspend the current voting session please press (1) or if you want to resume the current session please press (0) : ");
    scanf("%d",&press);
    if (press == 1)
    {
        session = 1;
    }
    else if (press == 0)
    {
        session = 0;
    }
    else
    {
        printf("You have entered a invalid number!!");
    }
}

void castVote()
{
int choice;
FILE *fptr;
fptr=fopen("E:\\Voting.txt", "a+");
char ch[20];
char CNIC[13];
printf("\n enter in your CNIC");
fclose(fptr);
if (session == 0)
{

    printf("\n\n\t\t Please choose your Candidate \t\t\n\n");
    printf("\n 1. %s", CANDIDATE1);
    printf("\n 2. %s", CANDIDATE2);
    printf("\n 3. %s", CANDIDATE3);
    printf("\n 4. %s", CANDIDATE4);
    printf("\n 5. %s", "None of These");

    printf("\n\n Input your choice (1 - 4) : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: votesCount1++; fprintf(fptr, "vote cast for %s\n",CANDIDATE1); break;
        case 2: votesCount2++; fprintf(fptr, "vote cast for %s\n",CANDIDATE2); break;
        case 3: votesCount3++; fprintf(fptr, "vote cast for %s\n",CANDIDATE3); break;
        case 4: votesCount4++; fprintf(fptr, "vote cast for %s\n",CANDIDATE4); break;
        case 5: spoiledtvotes++; break;
        default: printf("\n Error: Wrong Choice !! Please retry");
        getchar();
    }

    printf("\n thanks for vote !!");
    fclose(fptr);
}
else if (session == 1)
{
    printf("Voting session has currently been suspended by the admin\n\t\t sorry for any inconvenience caused");
}

}

int votesCount()
{
    printf("\n\n \t\t Voting Statics \t\t");
    printf("\n %s - %d ", CANDIDATE1, votesCount1);
    printf("\n %s - %d ", CANDIDATE2, votesCount2);
    printf("\n %s - %d ", CANDIDATE3, votesCount3);
    printf("\n %s - %d ", CANDIDATE4, votesCount4);
    printf("\n %s - %d ", "Spoiled Votes  ", spoiledtvotes);
}

void getLeadingCandidate()
{
    printf("\n\n\t\tLeading Candiate\t\t\n\n");
    if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4)
    {
        printf("[%s]",CANDIDATE1);
    }
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1)
    {
        printf("[%s]",CANDIDATE2);
    }
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1)
    {
        printf("[%s]",CANDIDATE3);
    }
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3)
    {
        printf("[%s]",CANDIDATE4);
    }
    else
    printf("\t\t No-win situation  \t\t");

}


void userandpass ()
{
    static int i=3;
    char euser[10];
    char epass[10];
    do
    {
    printf("\nUsername : ");
    scanf("%s",euser);
    printf("\nPassword : ");
    scanf("%s",epass);
    if (strcmp(euser,user)==0 && strcmp(epass,password)==0)
    {
        return ;
    }
    else
    {
        i--;
        printf("invalid username and/or password\nplease try again\nTries remaing : %d",i);
    }

    } while (i>0);
    abort();
}


int main()
{
int i;
int choice2;
int choice1;
int choice3;
jump:
printf("\n\n\t\tWelocme to the election portal\t\t\n\n\n1)ADMIN\n\n2)VOTER\n\nEnter your choice : ");
scanf("%d",&choice1);

if (choice1 == 1) {
    userandpass();
    do
    {
        printf("\n\n\t\tWelcome to the admin portal\t\t\n\n");
        printf("Selct from the folowing actions : ");
        printf("\n1) Enter in Cadinates \n2) Change The vote counts \n3) Suspend the voting session \n4) Clear the number of votes\n5) End the Voting Session\n0) Exit Admin console\n");
        printf("\n\nPlease enter your choice : ");
        scanf("%d",&choice3);

        switch (choice3)
        {
            case 1: adminE();
                break;
            case 2: changecount();
                break;
            case 3: susses();
                break;
            case 4: clearv();
                break;
            case 5: printf("voting session has ended\n");
                getLeadingCandidate();
                return 0;
                break;
            case 0: break;

            default:printf("Invalid choice");
                break;
        }
    } while (choice3!=0);
    if (choice3==0)
    {
        main();
    }
}

else if(choice1 == 2){
    do{
        printf("\n\n\t\t Welcome to Election/Voting 2020 \t\t\n\n");
        printf("\n\n 1) Cast the Vote");
        printf("\n 2) Find Vote Count");
        printf("\n 3) Find leading Candidate");
        printf("\n 0) Exit");

        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice2);


        switch(choice2)
        {
            case 1: castVote();break;
            case 2: votesCount();break;
            case 3: getLeadingCandidate();break;
            case 0: break;


            default: printf("\n Error: Invalid Choice");
        }
    }while(choice2!=0);
    if (choice2 == 0)
    {
        main();
    }

}
if (choice3==5)
{
    printf("Current Voting session has ended");
}
getchar();

return 0;
}

