#include <stdio.h>
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
  int count = 0;
  for(int i = height; i >= 0; i++){
    for(int j = 1; j < width; j = j+2){
      if(board[i][j] == piece){
        choice = checkGreatest(i, j, height, width, board);
      }
      switch(choice){
        case 1: choice = searchRight + searchLeft;
        if(choice >= 3){
          choice = searchRight;
          if(board[i][j + choice ])
        }
        case 2: choice = searchBelow(1, i, j, height, width, board);
        if(choice >= 3) return j;
        break;
        case 3:
        case 4:
        default: break;
      }
    }
  }
  return 0;
}

void set(int key){
  char piece, notPiece;
  if(key == 1){
    piece = 'X';
  }
  else{
    piece = 'O';
  }
}
