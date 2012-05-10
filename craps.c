//////////////////////////////////////////////////
// Jeff Parvin
// System Software
// Project 1a: Craps.c
// 20 Jan 2012
//////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

int main(){

	//instantiate vars
	char name[100];
	char play_ans[100];
	int play_var = 0;
	int point_var;
	int dice1;
	int dice2;
	int dice_total;
	int point;
	
	// Welcome and get name...
	printf("Welcome to Jeff's Casino!\n");
	printf("Please enter your name:  ");
	scanf("%s", name);
	
	// Do you want to play?
	printf("%s, would you like to Play or Quit?  ", name);
	scanf("%s",play_ans);
	if(strcasecmp(play_ans,"play")==0){		//if user answer is "play", then while loop is entered
		play_var=1;
		srand((unsigned int)time(NULL));	//seed random number gen once
	}
	
	// Play loop
	while(play_var==1){
	
		printf("---------------------------------------------\n");
		point_var=1;	//reset point variable
		
		//dice roll
		dice1 = rand() % (6 - 1 + 1) + 1;
		dice2 = rand() % (6 - 1 + 1) + 1;
		dice_total = dice1+dice2;
		
		printf("\nYou have rolled %d + %d = %d\n", dice1, dice2, dice_total);
		
		//check immediate win conditions
		if(dice_total==7 || dice_total==11){
			printf("You Win!\n");
			point_var=0;
		}
		
		//check immediate lose conditions
		if(dice_total==2 || dice_total==3 || dice_total==12){
			printf("You Lose :(\n");
			point_var=0;
		}

		//check for point condition
		if(point_var==1){
			point = dice_total;
			printf("%d is now the point.\n", point);
		}
		
		//point loop
		while(point_var==1){
		
			//dice roll
			dice1 = rand() % (6 - 1 + 1) + 1;
			dice2 = rand() % (6 - 1 + 1) + 1;
			dice_total = dice1+dice2;
			printf("\nYou have rolled %d + %d = %d\n", dice1, dice2, dice_total);
					
			if(dice_total==7){
				printf("You Lose :(\n");
				point_var=0;
			}
			
			if(dice_total==point){
				printf("You Win!\n");
				point_var=0;
			}
			
			
		}	
		
		printf("\nWould you like to play again? (yes or no) ");
		scanf("%s",play_ans);
		if(strcasecmp(play_ans,"yes")!=0){	//if user answer is not "yes", then exit while loop
			play_var=0;
		}
	}
	
	printf("\nGoodbye %s!\n\n", name);
	return 0;
}
