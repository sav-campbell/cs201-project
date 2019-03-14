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

int searchDiagUp(int up, int col, int row, int height, int width, char board[height][width]){
  int tempRow = row;
  int tempCol = col;
  while(board[tempRow][tempCol] == board[tempRow-1][tempCol+2]){
    up++;
    tempRow = tempRow - 1;
    tempCol = tempCol + 2;
  }
  while(board[row][col] == board[row+1][col-2]){
    up++;
    row = row +1;
    col = col -2;
  }

  return up;
}

int searchDiagDown(){
  return 0;
}


int checkWin(int col, int row, int height, int width, char board[height][width], int key){
  int below = 1;
  int winner = 0;
  int across = 1;
  int up = 1;

  across += searchRight(0, col, row, height, width, board) + searchLeft(0, col, row, height, width, board);
  below = searchBelow(below, col, row, height, width, board);
  up = searchDiagUp(up, col, row, height, width, board);
  if(key == 1){
    if(across >= 4)
      winner = 1;
    else if(below >= 4)
      winner = 1;
  }
  else if(key == 2)
  {
    if(across >= 4)
      winner = 2;
    else if(below >= 4)
      winner = 2;
  }


  return winner;
}
