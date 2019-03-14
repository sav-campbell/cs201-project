#include <stdio.h>
#include "searchBoard.c"

int chooseRow(int width){
  int choice;
  while(1)
  {
    printf("\n\nWhat column would you like to place a piece in?\n");
    scanf("%d", &choice);
    if(choice > width)
      printf("Invalid choice. Try again.\n");
    else
      break;
  }
  choice = (choice + (choice - 1));
  return choice;
}

//This function needs to check if there are any pieces already in the board
//and place the new piece accordingly
int placePiece(int num, int height, int width, char board[height][width], int win){
  int row = height-1;
  win = 0;
  for(int i = height-1; i >= 0; i--){ //This loop places the piece where it needs to be
    if(board[i][num] != 'X'){
      board[i][num] = 'X';
      row = i;
      i = -1;
    }
  }
  //printf("%d", row);
  win = checkWin(num, row, height, width, board);
  //printf("\ncheck2\n");
  return win;
}

int setPiece(void){ //This function is used so that this class can be checked on its own.
  chooseRow(7);
  return 0;
}
