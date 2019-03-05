#include <stdio.h>
#include "setPiece.c"

void fillBoard(int x, int y, char board[x][y]){
  for(int i = 0; i < x; i++){
    for(int j = 0; j <= y; j++){
      if(j%2 == 0)
        board[i][j] = '|';
      else
          board[i][j] = ' ';
    }
  }
}

void printBoard(int x, int y, char print[x][y]){
  for(int i = 0; i < x; i++){
    for(int j = 0; j <= y; j++)
      printf("%c", print[i][j]);
    printf("\n");
  }
}


int generateBoard(void){
  int width, height; //Should these be global variables? bad idea but like maybe

  printf("What is the height of the board?");
  scanf("%d", &height);
  printf("What is the width of the board?");
  scanf("%d", &width);
  int y = width*2;

  char board[height][y];
  int rowNum[width]; //this will help the player know what row they're dropping the piece in
  int num = 1;

  //This loop fills rowNum bc I don't want to make a function for it.
  for(int i = 0; i < width; i++)
  {
    rowNum[i] = num;
    num++;
  }

  fillBoard(height, y, board);
  printBoard(height, y, board);

  //This loop prints the rowNum array bc I don't know how I'm organizing my code yet
  for(int i = 0; i < width; i++)
    printf(" %d", rowNum[i]);

//  playerOne(y, height, board);
  return 0;
}

/*
void playerOne(int width, int height, char board[height][width]){
  placePiece(chooseRow(width), height, width, board);
  printBoard(height, width, board);
}
*/
