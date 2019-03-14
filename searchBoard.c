/*searchBoard creates a two dimensional array that is used to search for wins
each time that a player places a piece in the board.
*/
#include <stdio.h>

void Graph(int height, int width, int search[height][width]){
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++)
      search[i][j] = 0;
  }
}

int searchRight(int right, int col, int row, int height, int width, char board[height][width]){
    while(board[row][col] == board[row][col+2]){
        right++;
        col = col + 2;
    }

    return right;
}

int searchLeft(int left, int col, int row, int height, int width, char board[height][width]){
  while(board[row][col] == board[row][col-2]){
    left++;
    col = col - 2;
  }
  return left;
}

int searchBelow(int below, int col, int row, int height, int width, char board[height][width]){
  while(board[row][col] == board[row+1][col]){
      below++;
      row = row + 1;
    }
    return below;
}

int seachDiagLeft(){
    int match = 0;
    return match;
}

int searchDiagRight(){
    int match = 0;
    return match;
}

int checkWin(int col, int row, int height, int width, char board[height][width]){
//  int match = 1;
  int right = 1;
  int left = 0;
  int below = 1;
  int winner = 0;

  right = searchRight(right, col, row, height, width, board);
  left = searchLeft(left, col, row, height, width, board);
  below = searchBelow(below, col, row, height, width, board);
//printf("\nr: %d l: %d b: %d\n", right, left, below);
  if(right >= 4)
    winner = 1;
  else if(left >= 4)
    winner = 1;
  else if((left+right) >= 4)
    winner = 1;
  else if(below >= 4)
    winner = 1;

  return winner;
}
