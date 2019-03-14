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

int searchLeft(int match, int height, int width, int search[height][width], int index){
  return match;
}

int searchRight(int match, int col, int row, int height, int width, char board[height][width]){
    if(board[row][col] == board[row][col+2])
      match++;
    else
      match = -1;
    return match;
}

int searchBelow(){
    int match = 0;
    return match;
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
  int match = 1;
  int winner = 0;
  while(match < 4 && match != -1){
      match = searchRight(match, col, row, height, width, board);
      col = col + 2;
  }
  printf("%d", match);
  if(match == 4)
    winner = 1;

  return winner;
}
