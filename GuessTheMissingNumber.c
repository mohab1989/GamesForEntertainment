#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "GuessTheMissingNumber.h"
void PlayGuessTheMissingNumber() 
{	
		char PlayAgain='n';
		char *end;
		char buf[10];
		do
		{
			int Answer;
			//number of elements to choose the odd number from , you can set it to any integer you want.
			int ElementsCap=4;	
			int NumbersArray[ElementsCap];		
			srand((unsigned int)time(NULL));
			int CaseSelection = rand() % 4;
			do
			{
				NumbersArray[0] = rand() %50+1;
			}while(NumbersArray[0] ==0);
			
			int RandomStepNumber ;
			
			if(CaseSelection==0 || CaseSelection==2)
			{
				// in case of addition or subtraction
				do
				{
					RandomStepNumber = rand() %50+1;
				}while(RandomStepNumber==0||RandomStepNumber==1);
			}
			else
			{
				// in case of multiplication or division
				do
				{
					RandomStepNumber = rand() %9+1;
				}while(RandomStepNumber==0||RandomStepNumber==1);				
			}
						
			
			int RandomIndex = rand() %ElementsCap ;
			
			int i;
			if(CaseSelection==0)
			{
				for(i=1;i<ElementsCap;i++)
				{
					NumbersArray[i]=NumbersArray[i-1]+(RandomStepNumber);				
				}
			}	
			if(CaseSelection==1)
			{
				NumbersArray[i]=NumbersArray[i+1]+(RandomStepNumber);
				for(i=1;i<ElementsCap;i++)
				{
					NumbersArray[i]=NumbersArray[i-1]*(RandomStepNumber);			
				}			 	
			
			}
											 
			if(CaseSelection==2) 
			{
				NumbersArray[ElementsCap-1]=NumbersArray[0];
				for(i=ElementsCap-2;i>=0;i--)
				{
					NumbersArray[i]=NumbersArray[i+1]+(RandomStepNumber);
				}
			}					
			if(CaseSelection==3)
			{
				NumbersArray[ElementsCap-1]=NumbersArray[0];
				for(i=ElementsCap-2;i>=0;i--)
				{
					NumbersArray[i]=NumbersArray[i+1]*(RandomStepNumber);				
				}
			}                                  	   
			
			
	
			do
			{
				system("cls");
				printf("\n\n");
				printf("Guess The Missing Number In The Following Sequence\n");
				int l =0;
				for(l=0;l<ElementsCap;l++)
			    {
			    	if(l!=RandomIndex)
			   	 	{
			   	 		if(l==ElementsCap-1)
			   	 		{
			   	 			printf("%d.\n",NumbersArray[l]);
			   	 		}
			   	 		else
			   	 		{
			   	 			printf("%d , ",NumbersArray[l]);
			   	 		}		   	 		
			   	 	}
					else
					{
						if(l==ElementsCap-1)
			   	 		{
			   	 			printf("?.\n");
			   	 		}
			   	 		else
			   	 		{
			   	 			printf("? , ");
			   	 		}
					}		    	
			    }
				printf("Enter The Missing Number In The Previous Sequence that Is  Indicated By (?)\n");
				if (!fgets(buf, sizeof buf, stdin))
				{
					break;
				}				
				buf[strlen(buf) - 1] = 0;
				Answer = strtol(buf, &end, 10);
				if(Answer==NumbersArray[RandomIndex])
				{
					printf("Correct Answer!");
				}
				else
				{
					printf("Wrong Answer!\nThe Right Answer Is: %d\n",NumbersArray[RandomIndex]);
				}
		    }while(end != buf + strlen(buf));		    
			
			
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

