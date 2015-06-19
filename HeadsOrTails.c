#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include"HeadsOrTails.h"
void PlayHeadsOrTails() 
{
		char PlayAgain='n';
		bool loop = false;
		do
		{
			system("cls");
			char LowerCaseCorrectAnswer;
			char HigherCaseCorrectAnswer;	
			char UserAnswer;
			printf("\n\n");
			printf("Press AnyKey To Flip The Coin\n");
			getch();
			srand((unsigned int)time(NULL));
			int RandomNumber = rand() % 2;
			if(RandomNumber==0)
			{
				LowerCaseCorrectAnswer='h';
				HigherCaseCorrectAnswer='H';
			}
			else
			{
				LowerCaseCorrectAnswer='t';
				HigherCaseCorrectAnswer='T';
			}
			printf("\n\n");
			printf("press (H) to choose Heads Or (T) to choose Tails\n");
			do
			{				
				char ch = getche();
				UserAnswer=ch;
				// in case answer is right
				if(UserAnswer==LowerCaseCorrectAnswer||UserAnswer==HigherCaseCorrectAnswer)
				{
					if(UserAnswer=='h'||UserAnswer=='H')
					{
						printf("\n\n");
						printf("It Is Heads, You Win!\n");
					}
					else
					{
						printf("\n\n");
						printf("It Is Tails, You Win!\n");
					}	
					loop = false;		
				}
				//in case answer is wrong
				else
				{
					if(UserAnswer=='h'||UserAnswer=='H')
					{
						printf("\n\n");
						printf("Sorry It Was Tails, You Lose!\n");
						loop = false;
					}
					else if(UserAnswer=='t'||UserAnswer=='T')
					{
						printf("\n\n");
						printf("Sorry It Was Heads, You Lose!\n");
						loop = false;
					}
					else
					{
						system("cls");
						printf("\n\n");
						printf("Please Pick Heads Or Tails By Pressing H Or T keys \n");
						loop=true;
					}			
				}
			}while(loop);
			do
			{
				// ask user if he wants to play again.
				printf("\n\n");
				printf("Do You Want To Play Again?(Y/N) \n");		   		  		
		  		char ch = getche();
				PlayAgain=ch;
				system("cls");
			}while(((PlayAgain !='n')&&(PlayAgain!='N')) && ((PlayAgain !='y')&&(PlayAgain!='Y')));
	}while(PlayAgain=='y'||PlayAgain=='Y');
}
