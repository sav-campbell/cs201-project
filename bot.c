#include <stdio.h>
#include <time.h>
#include "searchBoard.c"

int randCheck = 0;

int win(int height, int width, char board[height][width], int key){
  int up = 0, down = 0, across = 0, below = 0;
  int row = height - 1;
  char peice;
  if(key == 1)
    peice = 'X';
  else
    peice = 'O';
  int col = -1;
  char temp;
  for(int j = 0; j < width; j++){
    for(int i = height-1; i >= 0; i--){
      if(board[i][j] != 'X' && board[i][j] != 'O' ){
        row = i;
        i = -1;
      }
    }
      temp = board[row][j];
    if(board[0][j] != 'X' && board[0][j] != 'O'){

        board[row][j] = peice;
        across = searchRight(1, j, row, height, width, board) + searchLeft(0, j, row, height, width, board);
        below = searchBelow(1, j, row, height, width, board);
        up = searchDiagUp(1, j, row, height, width, board);
        down = searchDiagDown(1, j, row, height, width, board);
    }
    printf("Win: across: %d, below: %d, up: %d, down: %d\n", across, below, up, down);
    if(across == 4 || below == 4 || up == 4 || down == 4){
        col = j;
    }
    board[row][j] = temp;
    if(col != -1)
      break;
  }
  return col;
}

int block(int height, int width, char board[height][width], int key){
  int up = 0, down = 0, across = 0, below = 0;
  int row = height - 1;
  char peice;
  if(key == 2)
    peice = 'X';
  else
    peice = 'O';
  int col = -1;
  char temp;
  for(int j = 0; j < width; j++){
    for(int i = height-1; i >= 0; i--){
      if(board[i][j] != 'X' && board[i][j] != 'O' ){
        row = i;
        i = -1;
      }
    }
          temp = board[row][j];
    if(board[0][j] != 'X' && board[0][j] != 'O'){

        board[row][j] = peice;
        across = searchRight(1, j, row, height, width, board) + searchLeft(0, j, row, height, width, board);
        below = searchBelow(1, j, row, height, width, board);
        up = searchDiagUp(1, j, row, height, width, board);
        down = searchDiagDown(1, j, row, height, width, board);
    }

   printf("Block: across: %d, below: %d, up: %d, down: %d\n", across, below, up, down);
    if(across == 4 || below == 4 || up == 4 || down == 4){
        col = j;
    }
    board[row][j] = temp;
    if(col != -1)
      break;
  }

  return col;
}

void randomize(){
  if(randCheck == 0){
    time_t t;
    srand((unsigned) 100);
    randCheck++;
  }
}

int checkGreatest(int height, int width, char board[height][width], int key){
  int up = 0, down = 0, across = 0, below = 0;
  int row = height - 1;
  int max = 1;
  randomize();
  char peice;
  if(key == 1)
    peice = 'X';
  else
    peice = 'O';
  int maxCol = rand() % width;
  printf("%d\n", maxCol);
  char temp;
  for(int j = 0; j < width; j++){
    for(int i = height-1; i >= 0; i--){
      if(board[i][j] != 'X' && board[i][j] != 'O' ){
        row = i;
        i = -1;
      }
    }
    temp = board[row][j];
    if(board[0][j] != 'X' && board[0][j] != 'O'){
      board[row][j] = peice;
      across = searchRight(1, j, row, height, width, board) + searchLeft(0, j, row, height, width, board);
      below = searchBelow(1, j, row, height, width, board);
      up = searchDiagUp(1, j, row, height, width, board);
      down = searchDiagDown(1, j, row, height, width, board);
    }
//    printf("checkGreatest: across: %d, below: %d, up: %d, down: %d\n", across, below, up, down);
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
    board[row][j] = temp;
  }
  printf("%d\n", maxCol);
  return maxCol;
}


int set(int height, int width, char board[height][width], int key){
  char piece, notPiece;
  int col = 0;
  col = win(height, width, board, key);
  if(col == -1)
    col = block(height, width, board, key);
  if(col == -1)
    col = checkGreatest(height, width, board, key);

  if(key == 1){
    piece = 'X';
  }else{
    piece = 'O';
  }
  return col;
}
