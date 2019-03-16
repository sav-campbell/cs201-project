#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "searchBoard.c"
//Obtains a valid row placement for the piece.
int chooseRow(int width){
  int choice;
  while(1)
  {
    printf("\n\nWhat column would you like to place a piece in?\n");
    scanf("%d", &choice);
    if(choice > width || choice <= 0)
      printf("Invalid choice. Try again.\n");
    else
      break;
  }
  choice = (choice + (choice - 1));
  return choice;
}

int compChoice(int width){ //randomly chooses a col for the piece to go in
  int choice;
  time_t t;
  srand((unsigned) time(&t));
  choice = rand() % width;
  choice = choice + (choice - 1);
  return choice;

}

int playerOne(int num, int height, int width, char board[height][width]){
  int row = height - 1;
  for(int i = height-1; i >= 0; i--){
    if(board[i][num] != 'X' && board[i][num] != 'O'){
      board[i][num] = 'X';
      row = i;
      i = -1;
    }
  }
  return row;
}

int playerTwo(int num, int height, int width, char board[height][width]){
  int row = height - 1;
  for(int i = height-1; i >= 0; i--){
    if(board[i][num] != 'O' && board[i][num] != 'X'){
      board[i][num] = 'O';
      row = i;
      i = -1;
    }
  }
  return row;
}


//This function determines which player is playing and checks for a win.
int placePiece(int num, int height, int width, char board[height][width], int key){
  int row = height-1;
  int win = 0;
  if(key == 1)
    row = playerOne(num, height, width, board);
  else if(key == 2)
    row = playerTwo(num, height, width, board);

  win = checkWin(num, row, height, width, board, key);
  return win;
}
