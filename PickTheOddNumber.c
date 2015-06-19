#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "PickTheOddNumber.h"
void PlayPickTheOddNumber() 
{	
		char PlayAgain='n';
		do
		{
			int AnswerIndex;
			//number of elements to choose the odd number from , you can set it to any integer you want.
			int ElementsCap=3;	
			int NumbersArray[ElementsCap];
			int ElementsCount=0;		
			bool OddNumberInserted=false;
			bool loop=false;
			srand((unsigned int)time(NULL));
			//while loop to create the list of numbers with only one odd number.
			while ((OddNumberInserted==false) || (ElementsCount<ElementsCap)) 
			{
				int RandomNumber=0;
				RandomNumber = rand() % 100 + 1;
				if(RandomNumber%2 != 0)
			    {
			    	if(OddNumberInserted==false)
			    	{
			    		NumbersArray[ElementsCount]=RandomNumber;
			    		OddNumberInserted=true;
			    		ElementsCount++;
			    	}				
			    }
			    else
			    {
			    	if(ElementsCount<(ElementsCap-1) || (ElementsCount==(ElementsCap-1) && OddNumberInserted==true))
			    	{
			    		NumbersArray[ElementsCount]=RandomNumber;
			    		ElementsCount++;
			    	}
			    }
	    	}	

		    do
			{
				system("cls");
				printf("\n\n");
				printf("which one of the following numbers is the odd number?\n");
		    	int i =0;
				for(i=0;i<ElementsCap;i++)
		   		 {
		    		printf("Answer Number %d = %d\n",i+1,NumbersArray[i]);
		   		 }
				printf("Press The Key Number That Corresponds To The Correct Answer\n");
			    //get the answer index from the user.	
				char ch = getche();	  
				if (isdigit(ch)) 
				{
					AnswerIndex=ch-'0';
					if(AnswerIndex>0 && AnswerIndex<=ElementsCap)
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
					loop=true;
				}
		    }while(loop);
		    
			
			//check if it qualifies as an answer.
			if (NumbersArray[AnswerIndex-1]%2 == 0)
			{
				printf("\n\n");
			    printf("Wrong Answer\n");
			}      
			else
		    {
		    	printf("\n\n");
			   	printf("Correct Answer\n");	
			}
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
