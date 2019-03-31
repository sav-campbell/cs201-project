/*searchBoard uses a two dimensional array that is used to search for wins
each time that a player places a piece in the board through a DFS. It checks #include
each direction until it finds a character that is not the same as the searched
character and returns any winning values.
*/
#include <stdio.h>

//DFS to the right
int searchRight(int right, int col, int row, int height, int width, char board[height][width]){
  while(board[row][col] == board[row][col+1]){
    if(col == width){
      break;
    }
    right++;
    col = col + 1;
  }

  return right;
}

//DFS to the left
int searchLeft(int left, int col, int row, int height, int width, char board[height][width]){
  while(board[row][col] == board[row][col-1]){
    left++;
    col = col - 1;
  }
  return left;
}

//DFS underneath the current piece
int searchBelow(int below, int col, int row, int height, int width, char board[height][width]){
  while(board[row][col] == board[row+1][col]){
      below++;
      row = row + 1;
    }
    return below;
}

//DFS in a forward slash
int searchDiagUp(int up, int col, int row, int height, int width, char board[height][width]){
  int tempRow = row;
  int tempCol = col;

  while(board[tempRow][tempCol] == board[tempRow-1][tempCol+1]){
    if(tempCol == width){
      break;
    }
    up++;
    tempRow = tempRow - 1;
    tempCol = tempCol + 1;
  }
  while(board[row][col] == board[row+1][col-1]){
    if(col == 0){
      break;
    }
    up++;
    row = row +1;
    col = col -1;
  }

  return up;
}

//DFS in a back slash
int searchDiagDown(int down, int col, int row, int height, int width, char board[height][width]){
  int tempRow = row;
  int tempCol = col;
  while(board[tempRow][tempCol] == board[tempRow-1][tempCol-1]){
    if(tempCol == 0)
      break;
    down++;
    tempRow = tempRow - 1;
    tempCol = tempCol - 1;
  }
  while(board[row][col] == board[row+1][col+1]){
    if(col == width){
      break;
    }
    down++;
    row = row+1;
    col = col+1;
  }


  return down;
}

//This function calls all of the DFS functions and determines if any of them were winning moves.
int checkWin(int col, int row, int height, int width, char board[height][width], int key){
  //The search variables are initialized to 1 so that they count the current piece.
  int below = 1;
  int winner = 0;
  int across = 1;
  int up = 1;
  int down = 1;

  across += searchRight(0, col, row, height, width, board) + searchLeft(0, col, row, height, width, board);
  below += searchBelow(0, col, row, height, width, board);
  up += searchDiagUp(0, col, row, height, width, board);
  down += searchDiagDown(0, col, row, height, width, board);

  if(key == 1){
    if(across >= 4 || below >= 4 || up >= 4 || down >= 4)
      winner = 1;

  }
  else if(key == 2)
  {
    if(across >= 4 || below >= 4 || up >= 4 || down >= 4)
      winner = 2;
  }



  return winner;
}
