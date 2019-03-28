#include <stdio.h>
#include <time.h>
#include "searchBoard.c"

int win(char piece, int height, int width, char board[height][width]){
  int choice = 0; //choice needs to be the col that we want to place it in
  int win;
  for(int j = 0; j < width; j++){
    if(board[0][j] == piece){

    }
  }
  return choice;
}

int block(char piece){
  int choice = 0;

  return choice;
}

int best(char piece, int height, int width, char board[height][width]){
  int choice = 0;
  for(int i = 0; i < width; i++){

  }
  return 0;
}

int checkGreatest(int height, int width, char board[height][width], int key){
  int up, down, across, below;
  int row = height - 1;
  int max = 1;
  char peice;
  if(key == 1)
    peice = 'X';
  else
    peice = 'O';
  time_t t;
  srand((unsigned) time(&t));
  int maxCol = rand() % width;
  printf("%d\n", maxCol);
  for(int j = 0; j < width; j++){
    for(int i = height-1; i >= 0; i--){
      if(board[i][j] != 'X' && board[i][j] != 'O' ){
        row = i;
        i = -1;
      }
    }
    board[row][j] = peice;
    across = searchRight(1, j, row, height, width, board) + searchLeft(0, j, row, height, width, board);
    below = searchBelow(1, j, row, height, width, board);
    up = searchDiagUp(1, j, row, height, width, board);
    down = searchDiagDown(1, j, row, height, width, board);
    printf("across: %d, below: %d, up: %d, down: %d\n", across, below, up, down);
    if(across > max || below > max || up > max || down > max)
      maxCol = j;
    if(across > max)
      max = across;
    if(below > max)
      max = below;
    if(up > max)
      max = up;
    if(down > max)
      max = down;
    board[row][j] = ' ';
  }
  printf("%d\n", maxCol);
  return maxCol;
}


int set(int height, int width, char board[height][width], int key){
  char piece, notPiece;
  int col = checkGreatest(height, width, board, key);
  if(key == 1){
    piece = 'X';
  }
  else{
    piece = 'O';
  }
  return col;
}
