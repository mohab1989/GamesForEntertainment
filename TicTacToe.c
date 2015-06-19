#include <stdio.h>
#include <stdbool.h>
#include "TicTacToe.h"
void PlayTicTacToe()
{
	char PlayAgain='n';
	bool loop=false;	
		do
		{
		    int i = 0;
		    int player = 0;
		    int go = 0;
		    int row = 0; 
		    int column = 0;
		    int line = 0;
		    int winner = 0;
		    char board[3][3] = 
		    {
		        {'1','2','3'},
		        {'4','5','6'},
		        {'7','8','9'}
		    };
		    
		    for( i = 0; i<9 && winner==0; i++)
		    
		    {
		    	system("cls");
		        printf("\n\n");
		        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
				printf("-----------\n");
		        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
				printf("-----------\n");
		        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
		        
		        player = i%2 + 1;
		        
		        do
		        {
		        	if(board[row][column]>'9' || loop)
		        	{
		        		system("cls");
		        		printf("\n\n");
				        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
						printf("-----------\n");
				        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
						printf("-----------\n");
				        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
		        	}
					printf("\nPlayer %d, please enter the number of the square "
		                   "where you want to place your %c: ", player,(player==1)?'X':'O');
			        char ch = getche();	  
					if (isdigit(ch)) 
					{
						go=ch-'0';
						if(go>0 && go<=9)
						{
							row = --go/3;
			            	column = go%3;
							loop=false;
						}
						else
						{
							loop=true;
						}
					} 
					else
					{
						loop=true;
					}
		        }
		        while(loop || board[row][column]>'9');
		        
		        board[row][column] = (player == 1) ? 'X' : 'O';
		        //check for win if the diagonals are matching
		        //the or in the condition makes sure to check the two diagonals of the board
		        if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
		           (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
		            winner = player;
		        else
		            // the for loop to check each row or column
		            for(line = 0; line <= 2; line ++)
		                //the or in the condition makes sure it checks rows and columns
		                if((board[line][0] == board[line][1] && board[line][0] == board[line][2])||
		                   (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
		                    winner = player;
		        
		    }
		    system("cls");
		    printf("\n\n");
		    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
			printf("-----------\n");
		    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
			printf("-----------\n");
		    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
		    
		    if(winner == 0)
		        printf("\nDraw\n");
		    else
		printf("\nplayer %d, YOU WON!\n", winner);
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
