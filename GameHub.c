#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PickTheOddNumber.h"
#include "HeadsOrTails.h"
#include "TicTacToe.h"
#include "GuessTheMissingNumber.h"

int main(void) 
{
	int GameIndex;
	int NumberOfGames=4;
	bool loop = false;
	bool PlayAgain = true;
	do{
		do
		{
			system("cls");
			printf("\n\n");
			printf("**************** Welcome To The Games Of Intertainment ****************\n");
			printf("\n\n");
			printf("Please Select One Of The Four Games Availabe\nBy Pressing Its Corresponding Number\n\n");
			printf("Game Number 1: Pick The Odd Number\nGame Number 2: Heads Or Tails\n");
			printf("Game Number 3: Tic Tac Toe\nGame Number 4: Guess The Missing Number\n");
			printf("\n\n");
			printf("Press The Numbers From (1) to (%d) To Select A Game Or Press (Q) To Quit.\n)",NumberOfGames);
			//get the answer index from the user.	
			char ch = getche();	  
			if (isdigit(ch)) 
			{
				GameIndex=ch-'0';
				if(GameIndex>0 && GameIndex<=NumberOfGames)
				{
					loop=false;
				}
				else
				{
					loop=true;
				}
			} 
			else
			{
				if(ch=='q'||ch=='Q')
				{
					GameIndex=ch-'0';
					loop=false;
				}
				else
				{
					loop=true;
				}
			}
		}while(loop);
		switch(GameIndex)
		{
			case 1:
				PlayPickTheOddNumber();
				PlayAgain=true;
				break;
			case 2:
				PlayHeadsOrTails();
				PlayAgain=true;
				break;
			case 3:
				PlayTicTacToe();
				PlayAgain=true;
				break;
			case 4:
				PlayGuessTheMissingNumber();
				PlayAgain=true;
				break;
			case 33:
			case 65:
				PlayAgain=false;
				break;
		}
	}while(PlayAgain);
	system("cls");
    return 0;
}
