#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct information
{
    char namef[20],namel[20], email[30], contact[20];
    int score;
};
struct information b;
char ch;
void test();
void search();
void del();
void Exit();

void gotoxy(int x, int y);

int main()
{
    printf("\t\t\t\t\t\tCES-D Questionnaire\t\t\t\n\n");
    printf("The Center for Epidemiological Studies-Depression (CES-D Questionnaire), originally published by Radloff in 1977,is a 20-item measure that asks caregivers to rate how often over the past week they experienced symptoms associated with depression, such as restless sleep, poor appetite, and feeling lonely.\n");
    system("pause");
    system("cls");
    char num;
    start:
    gotoxy(20,7);
    printf("Menu");
    gotoxy(20,8);
    printf("1.Take a test\n");
    gotoxy(20,9);
    printf("2.Search for a Testee's CES-D index\n");
    gotoxy(20,10);
    printf("3.Delete a Testee's CES-D record\n");
    gotoxy(20,11);
    printf("4.Exit");
    gotoxy(20,12);
    scanf("%c",&num);
    switch(num)
    {
    case '1':
      system ("cls");
      test();
      goto start;
      break;

    case '2':
      system ("cls");
      search();
      goto start;
      break;

    case '3':
      system ("cls");
      del();
      goto start;
      break;
    case '4':
      system ("cls");
      Exit();
      break;
    default:
      printf("Invalid choice.");
      system ("cls");
      goto start;
    }
    getch();
    return 0;
}

void test()
{
    FILE *fp;
    int a[20];
    printf("Enter your first name:");
    scanf("%s",b.namef);
    printf("Enter your last name:");
    scanf("%s",b.namel);
    printf("Enter your email:");
    scanf("%s",b.email);
    printf("Enter your Contact no.:");
    scanf("%s",b.contact);
    system("pause");
    system ("cls");
    printf("Instructions\n");
    printf("The CES-D should take no more than 10 minutes to complete.\n");
    printf("The provided statements about the depression are to be answered on how often you experience them(over a week) by entering a number in the blank after each statement, according to the following scale:\na. 0 = Rarely or none of the time (less than 1 day)\nb. 1 = Some or a little of the time (1-2 days)\nc. 2 = Occasionally or a moderate amount of time (3-4 days)\nd. 3 = Most or all of the time (5-7 days)\n");
    system("pause");
    printf("\nPlease read the statements carefully, some of the statements(d, h, l and p) indicate positive traits(p) for which the following scale applies: \na. 3 = less than 1 day\nb. 2 = 1-2 days \nc. 1 = 3-4 days \nd. 0 = 5-7 days\n");
    system("pause");
    printf("\nDo not take too long over individual questions; there are no \"right\" or \"wrong\" answers (and no trick questions). The first answer that comes into your head is probably the right one for you. If you find some of the questions difficult, please give the answer that is true for you in general or for most of the time. The obtained score will be discarded, when more than four statements remained unanswered or numbers other than the above mentioned are entered.\n");
    system("pause");
    printf("\nThe range of possible scores falls between 0-60.");
    printf(" A cutoff score of 16 or greater reflects individuals at risk for clinical depression. More specifically:\n0-16: No to mild depressive symptomatology\n16-23: Moderate depressive symptomatology\n24-60: Severe depressive symptomatology\n");
    system("pause");
    system("cls");
    printf("Statements:\n");
    printf("a.I was bothered by things that usually don't bother me.\n");
    scanf("%d",&a[0]);
    printf("b.I did not feel like eating; my appetite was poor.\n");
    scanf("%d",&a[1]);
    printf("c.I felt that I could not shake off the blues even with help from my family and friends.\n");
    scanf("%d",&a[2]);
    printf("d.I felt that I was just as good as other people(p).\n");
    scanf("%d",&a[3]);
    printf("e.I had trouble keeping my mind on what I was doing.\n");
    scanf("%d",&a[4]);
    printf("f.I felt depressed.\n");
    scanf("%d",&a[5]);
    printf("g.I felt that everything I did was an effort.\n");
    scanf("%d",&a[6]);
    printf("h.I felt hopeful about the future(p).\n");
    scanf("%d",&a[7]);
    printf("i.I thought my life had been a failure.\n");
    scanf("%d",&a[8]);
    printf("j.I felt fearful.\n");
    scanf("%d",&a[9]);
    printf("k.My sleep was restless.\n");
    scanf("%d",&a[10]);
    printf("l.I was happy(p).\n");
    scanf("%d",&a[11]);
    printf("m.I talked less than usual.\n");
    scanf("%d",&a[12]);
    printf("n.I felt lonely.\n");
    scanf("%d",&a[13]);
    printf("o.People were unfriendly.\n");
    scanf("%d",&a[14]);
    printf("p.I enjoyed life(p).\n");
    scanf("%d",&a[15]);
    printf("q.I had crying spells.\n");
    scanf("%d",&a[16]);
    printf("r.I felt sad.\n");
    scanf("%d",&a[17]);
    printf("s.I felt that people disliked me.\n");
    scanf("%d",&a[18]);
    printf("t.I could not get \"going\".\n");
    scanf("%d",&a[19]);
    b.score=0;
    for(int i=0; i<=19; i++)
    {
        b.score = b.score + a[i];
    }
    system ("cls");
    if (b.score<=16)
    {
        printf("\nYour Depression index is %d which reflects No to Mildly depressive symptomatology.\n",b.score);
    }
    else if(b.score>16 && b.score<=23)
    {
        printf("\nYour Depression index is %d which reflects Moderately depressive symptomatology.\n",b.score);
    }
    else if(b.score>23 && b.score<=60)
    {
      printf("\nYour Depression index is %d which reflects Severely depressive symptomatology.\n",b.score);
    }
    else{
        printf("Invalid score.");
    }
    system("pause");
    printf("\n\nNote: This test is scored so that higher scores indicate greater symptoms of depression. Before interpreting your score, you should know that a high score is not the same thing as a diagnosis of depression. Some people who get high scores are not in fact depressed, and people with low scores can still have a \"depressive disorder\". A full-blown diagnosis of depression depends on other things, such as how long your symptoms have lasted and whether they have some primary source other than depression. A diagnosis can be made only after a thorough interview with a qualified psychologist or psychiatrist.\n");
    system("pause");
    fp = fopen("test.txt","a");
    if(fp==NULL)
    {
        printf("\nFile cannot be created.");
        exit(1);
    }
    fprintf(fp, "\n%s %s  %s  %s  %d", b.namef,b.namel,b.email,b.contact,b.score);
    fclose(fp);
}

void search()
{
char san[20];
start:
system("cls");
printf("Enter Name: ");
scanf("%s",san);
FILE *fp1;
    fp1= fopen("test.txt","r");
    if(fp1==NULL)
    {
        printf("\nFile cannot be created.");
        exit(1);
    }
    while((fgetc(fp1)) !=EOF)
    {
        fscanf(fp1,"%s",b.namef);
        fscanf(fp1,"%s",b.namel);
        fscanf(fp1,"%s",b.email);
        fscanf(fp1,"%s",b.contact);
        fscanf(fp1,"%d",&b.score);
        if(strcmp(san,b.namef) == 0)
        {
        printf("\nDetails:");
        printf("\nName: %s %s \nEmail id: %s\nContact no.: %s\nDepression index: %d\n",b.namef,b.namel,b.email,b.contact,b.score);
        system("pause");
        goto begin;
        }
    }
    if(strcmp(san,b.namef) == 1)
    {
        printf("\nThis name does not exist.");
        begin:
        printf("\nDo you want to search again[Yes(y)/No(n)]?");
        scanf("\n%c",&ch);
        if(ch == 'y')
        {
         goto start;
        }
        else if(ch == 'n')
        {
        goto end;
        }
        else{
            printf("\nInvalid choice.");
            goto begin;
        }
    }
    end:
    fclose(fp1);
}
void del()
{
    char sun[20];
    start:
    system("cls");
    printf("Enter the Testee's name whose record is to be deleted: ");
    scanf("%s",sun);
    FILE *fp2, *fp3;
    fp3 = fopen("temp.txt","w");
    if(fp3==NULL)
    {
        printf("\nFile cannot be created.");
        exit(1);
    }
    fp2 = fopen("test.txt","r");
    if(fp2==NULL)
    {
        printf("\nFile cannot be created.");
        exit(1);
    }
    int d=0;
    while((fgetc(fp2)) !=EOF)
    {
        fscanf(fp2,"%s",b.namef);
        fscanf(fp2,"%s",b.namel);
        fscanf(fp2,"%s",b.email);
        fscanf(fp2,"%s",b.contact);
        fscanf(fp2,"%d",&b.score);
        if(strcmp(sun,b.namef) == 1)
        {
             fprintf(fp3, "\n%s %s  %s  %s  %d", b.namef,b.namel,b.email,b.contact,b.score);
        }
        if(strcmp(sun,b.namef) == 0)
        {
             d=1;
        }
    }
    if(d == 0)
    {
        printf("\nThis name does not exist.");
        begin:
        printf("\nDo you want to try it again[Yes(y)/No(n)]?");
        scanf("\n%c",&ch);
        if(ch == 'y')
        {
         goto start;
        }
        else if(ch == 'n')
        {
        goto end;
        }
        else{
            printf("\nInvalid choice.");
            goto begin;
        }
    }
    end:
    fclose(fp2);
    fclose(fp3);
    remove("test.txt");
    rename("temp.txt","test.txt");
    if (d==1)
    {
    printf("\n  Deleted successfully.\n");
    system("pause");
    }
}
void Exit()
{
    gotoxy(20,8);
    printf("********THANK YOU FOR PARTICIPATING*********\n");
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
