#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "searchBoard.c"
#include "bot.c"
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
  //choice = (choice + (choice - 1));
  return (choice-1);
}

int compChoice(int height, int width, char board[height][width], int key){ //randomly chooses a col for the piece to go in
  int choice = 0;
  choice = set(height, width, board, key);
  return choice;
}

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
  while(board[0][num] == 'X' || board[0][num] == 'O'){
    printf("Invalid choice. Try again.\n");
    if(type = 1)
      num = chooseRow(width);
    else
      num = compChoice(height, width, board, key);
  }

  if(key == 1)
    row = playerOne(num, height, width, board);
  else if(key == 2)
    row = playerTwo(num, height, width, board);

  win = checkWin(num, row, height, width, board, key);
  return win;
}
