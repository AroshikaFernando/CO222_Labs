/*
	CO222-2016 Lab05
	Author: E13101

	TicTacToe game
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

void scanBoard(int a[SIZE][SIZE]);
void printBoard(int b[SIZE][SIZE]);
int getWinner(int b[SIZE][SIZE]);

int main(){

	int inBoard[SIZE][SIZE];	//declaring an array

	printf("Please enter the board:\n");
	scanBoard(inBoard);	//scanBoard
    printf("Here is the board:\n");
	printBoard(inBoard);	//printBoard
	if(getWinner(inBoard)==0)	
		printf("Noughts win\n");
	else if(getWinner(inBoard)==1)
		printf("Crosses win\n");
	else
		printf("There are no winners\n");
	
	return 0;
    return 0;
}


//scan function
void scanBoard(int board[SIZE][SIZE]){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            scanf("%d",&board[i][j]);
            if((board[i][j]==1)||(board[i][j]==0)||(board[i][j]==2)){

            }else{
                printf("Enter valid input.");
                exit(-1);
            }
        }

    }
}
void printBoard(int board[SIZE][SIZE]){
   int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(board[i][j]==1){
                printf("x");
            }
            if(board[i][j]==0){
                printf("o");
            }
            if(board[i][j]==2){
                printf(".");
            }
            printf(" ");
        }
       printf("\n");
    }
}
int getWinner(int board[SIZE][SIZE]){
	// 
	int winner = 2;
	int i,j;
	// chacking by row to row---
	int sum=0;
	int prod=1;
    for(j=0;j<SIZE;j++){
           sum=0;
           prod=1;
           for(i=0;i<SIZE;i++){
          sum=sum+board[j][i];
          prod=prod*board[j][i];

         } // assign winner if there is one..
       if(sum==0){
		   winner=0;
		   }else if(prod==1){
			   winner=1;
			   }
       
	}
 // checking by column to column---
    for(j=0;j<SIZE;j++){
           sum=0;
           prod=1;
           for(i=0;i<SIZE;i++){
          sum=sum+board[i][j];
          prod=prod*board[i][j];

         } // assign winner if there is one..
       if(sum==0){
		   winner=0;
		   }else if(prod==1){
			   winner=1;
			   }
       
	}

// Diagonal entry--
 sum=0;
 prod=1;
	for(j=0;j<SIZE;j++){
		  sum=sum+board[j][j];
          prod=prod*board[j][j];
		} // assign winner if there is one..
        if(sum==0){
		   winner=0;
		   }else if(prod==1){
			   winner=1;
			   }
// other side of the diagonal--			   
 sum=0;
 prod=1;			   
	for(j=0;j<SIZE;j++){

		  sum=sum+board[j][SIZE-(j+1)];
          prod=prod*board[j][SIZE-(j+1)];

		
		}// assign winner if there is one..
		if(sum==0){
		   winner=0;
		   }else if(prod==1){
			   winner=1;
			   }		   


	return  winner;
}




