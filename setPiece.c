#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "bot.c"

//This checks any user input that needs to be an int to make sure that it is,
//so that invalid input does not break my code.
int numCheck(int x, char val[x]){
  int choice = 0;
  for(int i = 0; i < x; i++){
    if(!isdigit(val[i]))
      choice = -1;
  }
  if(choice != -1)
    choice = atoi(val);
  else{
    while(choice == -1){
      printf("\nPlease enter a valid input. (Integer input)");
      scanf("%49s", val);
      choice = numCheck(strlen(val), val);
    }
  }
  //Check printf("choice: %d ", choice);
  return choice;
}

//This initializes any character arrays in the code that I use.
void initialize(int x, char arr[x]){
  for(int i = 0; i < x; i++)
    arr[i] = ' ';
}

//Obtains a valid row placement for the piece.
int chooseRow(int width){
  int choice;
  char answer[20];
  initialize(20, answer);
  while(1)
  {
    printf("\n\nWhat column would you like to place a piece in?\n");
    scanf("%19s", answer);
    choice = numCheck(strlen(answer), answer);
    if(choice > width || choice <= 0)
      printf("Invalid choice. Try again.\n");
    else
      break;
  }
  //choice = (choice + (choice - 1));
  return (choice-1);
}

//This passes the board into the bot class to choose the best move through DFS
int compChoice(int height, int width, char board[height][width], int key){ //randomly chooses a col for the piece to go in
  int choice = 0;
  choice = set(height, width, board, key);
  return choice;
}

//Places an X in a column for player 1.
int playerOne(int num, int height, int width, char board[height][width]){
  int row = height - 1;
  for(int i = height-1; i >= 0; i--){
    if(board[i][num] != 'X' && board[i][num] != 'O'){
      board[i][num] = 'X';
      row = i;
      //printf("\ni = %d ; num = %d ; row = %d\n", i, num, row);
      i = -1;
      //printf("\ni = %d ; num = %d ; row = %d\n", i, num, row);
    }
  }
  return row;
}

//Places an 'O' in a column for player two.
int playerTwo(int num, int height, int width, char board[height][width]){
  int row = height - 1;
  for(int i = height-1; i >= 0; i--){
    if(board[i][num] != 'O' && board[i][num] != 'X'){

      board[i][num] = 'O';
      row = i;
    //  printf("\ni = %d ; num = %d ; row = %d\n", i, num, row);
      i = -1;
    //  printf("\ni = %d ; num = %d ; row = %d\n", i, num, row);
    }
  }
  return row;
}


//This function determines which player is playing and checks for a win.
int placePiece(int num, int height, int width, char board[height][width], int key, int type){
  int row = height-1;
  int win = 0;
  if(type == 1){
    while(board[0][num] == 'X' || board[0][num] == 'O'){
      printf("Invalid choice. Try again.\n");
      num = chooseRow(width);
    }
  }

  if(key == 1)
    row = playerOne(num, height, width, board);
  else if(key == 2)
    row = playerTwo(num, height, width, board);

  win = checkWin(num, row, height, width, board, key);
  return win;
}
