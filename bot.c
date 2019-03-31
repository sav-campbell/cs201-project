/*The bot class uses the DFS functions in the serachBoard class to determine
the best move. It first checks for any winning moves and then any blocking moves.
If there is neither a winning or blocking move, it will take a move that creates
the longest string of it's pieces. Therefore prioritizing more important moves.*/
#include <stdio.h>
#include "searchBoard.c"

int randCheck = 0;

void randomize(){
  if(randCheck == 0){
    srand((unsigned) 100);
    randCheck++;
  }
}

//This uses the DFS functions to determine if any placement will give a 4 in a row for the current player.
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
  //Check  printf("Win: across: %d, below: %d, up: %d, down: %d\n", across, below, up, down);
    if(across == 4 || below == 4 || up == 4 || down == 4){
        col = j;
    }
    board[row][j] = temp;
    if(col != -1)
      break;
  }
  return col;
}

//This uses the DFS functions to determine if any placement will give a 4 in a row for the opposing player.
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

//Check   printf("Block: across: %d, below: %d, up: %d, down: %d\n", across, below, up, down);
    if(across == 4 || below == 4 || up == 4 || down == 4){
        col = j;
    }
    board[row][j] = temp;
    if(col != -1)
      break;
  }

  return col;
}

//This function checks for the longest string of like characters possible.
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
// Check   printf("checkGreatest: across: %d, below: %d, up: %d, down: %d\n", across, below, up, down);
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

//The set functions searches for the best move in an appropriate priority structure. (Win, block, best)
int set(int height, int width, char board[height][width], int key){
  int col = 0;
  col = win(height, width, board, key);
  if(col == -1)
    col = block(height, width, board, key);
  if(col == -1)
    col = checkGreatest(height, width, board, key);

  return col;
}
