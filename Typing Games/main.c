#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>

    static int x=1;
    #define pos gotoxy(33,x++)
    #define ln  printf(".......................");

    COORD coord={0,0};

    void gotoxy(int x,int y)
    {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }

    int t=30;
    int c=0;


char name[15];
void getscore(int score,int speed,int level);
void startgame();
void scorecard();
void help();
void set_time();

int main()
{
    int ch;
	time_t t;
	time(&t);
    //	rectangle(0,0,70,15);
	x=1;
	system("cls");
	pos;
	printf("welcome to typing game ");
	pos;
	printf("%s",ctime(&t));
	pos;
    ln pos;
	if(c==0)
	   {
        printf("Enter player's name::");
		gets(name);
	   }
	   c++;
        pos;
        ln
        pos;
		printf("#..MAIN MENU..#");pos;
		ln
		pos;
		printf("1.startgame");
		pos;
		printf("2.scorecard");
		pos;
		printf("3.Help");
		pos;
		printf("0.exit");
		pos;
		printf("Enter your choice::");
		scanf("%d",&ch);
		pos;
		switch(ch)
		{
		    case 1:
		        startgame();break;
			case 2:
			    scorecard();break;
			case 3:
			    help();break;
			case 0:
                    system("cls");
                    Sleep(1000);
                    pos;
                    exit(1);
			default:
			    main();
		}

getch();
}


void startgame()
{
    printf("Set the Time");
    set_time();
    int score=0,level=1,range=100,count=0;
	clock_t begin;
	int time_spent,speed;

	int r,letter,ch;
	int cnt = 0;

	Sleep(500);
	system("cls");
	srand(time(NULL));
	x=2;
	pos;
	printf("#........select the Mode......#");
	pos;
	ln
	pos;
	printf(" 1 -> Easy mode");
	pos;
	printf(" 2 -> Normal mode");
	pos;
	printf(" 3 -> Hard mode");
	pos;
	printf(" 4 -> Main menu");
	pos;
	scanf("%d",&level);
	if(level==4)
	main();

	else

	{
	    if(level==1)
        range=65;
	     if(level==2)
		range=97;
	     if(level==3)
		range=120;
		begin=clock();

		while(1)
        {

            system("cls");
			time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;
			if(time_spent>=t)
			break;

			r=rand()%1000;
			r=r%26+range;
			gotoxy(20,8);
			printf("....Type the following character....");
			gotoxy(36,11) ;
			printf(" %c",r);
			gotoxy(36,12);
			letter=getche();
			if(letter!=r)
            {
                ++cnt;
                score -=10;
				gotoxy(28,9);
				printf("score = %d ",score);//prints score
				gotoxy(28,10);
				printf("time_spent=%d sec",time_spent);//prints time spent during game
				if(level==1)
				Sleep(400);
				if(level==2)
				Sleep(200);
				if(level==3)
				Sleep(100);
            }

			else
			{
                ++count;
				score += 10;
				gotoxy(28,9);
				printf("score = %d ",score);//prints score
				gotoxy(28,10);
				printf("time_spent=%d sec",time_spent);//prints time spent during game
				if(level==1)
				Sleep(400);
				if(level==2)
				Sleep(200);
				if(level==3)
				Sleep(100);

			}
		}
		gotoxy(26,x);

		Sleep(400);
		++x;
		pos;
		printf("Correctly typed -> %d",count);
		pos;
		printf("Incorrectly typed -> %d",cnt);
		pos;
		speed=(abs(count-cnt)*60)/time_spent ;

        printf("Times up !!!");
        pos;
        pos;
        int d;
        if(score<=0)d=0;
        else
            d = 1;
        if(d==1)
        {
            if((speed>=25)&&(speed<=45))
			{
			    printf("Good Work !Keep it up!");pos;

				printf("Your Adjusted Typing Speed is -> AVERAGE");
			}
			else if(speed>45&&speed<=60)
            {
			    printf("Good Work !Keep it up!");pos;

				printf("Your Adjusted Typing Speed is -> FLUENT");
			}
			else if(speed>60)
			{
				printf("Nice work!!! ");
				pos;
				printf("Your Adjusted Typing Speed is -> FAST");
			}
			else
			{
			    printf("you need to practice..!!!");
			    pos;
				printf("Your Adjusted Typing Speed is -> SLOW");
			}
			pos;
            printf("Total score is ::%d",score);
            pos;

            printf("Your net speed = %d letter per minute",speed);
        }
        else
        {
            pos;
            printf("Total score is ::%d",score);
            pos;
            printf("Your net speed = 0");
        }



		getscore(score,speed,level);
		pos;
		printf("1.# play again #");
		pos;
		printf("2.# main menu #");
		pos;
		printf("3.exit"); pos;
		printf("Enter your choice::");

		scanf("%d",&ch);
		switch(ch)
		{
		      case 1:startgame();break;//recursive call
		      case 2:main();break;
		      case 3:system("cls");
                    gotoxy(17,10);
                    Sleep(1000);
                    exit(1);
		      default:
		          pos;
		          printf("wrong choice!");
		          pos;
				main();
		}

	}

}
//......................end of start game function..........................


//...........................sett function starts..........................
void set_time()
{
	int ch;
	system("cls");
	x=5;
	pos;
	printf("Set the time limit for game in minute::");
	pos;
	ln
	pos;
	printf("press 0 for half minute");
	pos;
	printf("press 1 for 1 minute");
	pos;
	printf("press 2 for 2 minute");
	pos;
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:t=30;break;
		case 1:t=60;break;
		case 2:t=120;break;
		default:main();
	}
}
//....................sett function ends....................................


void help()
{
	system("cls");
	gotoxy(7,5);

	printf("#......Rules of the Game......#");
	gotoxy(7,6);
	printf("=>Enter your name as player name");
	gotoxy(7,7);
	printf("=>Set the time limit under option 3 in main menu(default limit is 30 sec)");
	gotoxy(7,8);
	printf("=>select the level and get started :");
	gotoxy(7,9);
	printf("=>Characters are displayed and you have to type them as fast as you can..");
	gotoxy(7,10);
	printf("=>Avoid incorrect typing otherwise game will be over..");
	int l;
	l = getche();
	if(l==13)
	main();
}

void getscore(int score,int speed,int level)
{
	FILE *fp;
	fp=fopen("file.txt","a");
	pos;
	if(fp==NULL)
	printf("error in opening file");
	fprintf(fp,"\nname=%s   score=%d    speed=%d    level=%d",name,score,speed,level);
	fclose(fp);
	pos;
	printf("scorecard updated");
}
void scorecard()
{       int ch;
    int l;
	FILE *fp;
	system("cls");
	x=3;
	printf("\t\t\t....The scores are...\n");

	fp=fopen("file.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{	printf("%c",ch);
	}
	l = getche();
	if(l==13)
	main();
}


