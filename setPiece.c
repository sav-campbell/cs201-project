#include <stdio.h>

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
  choice = choice + (choice - 1);
  return choice;
}

//This function needs to check if there are any pieces already in the board
//and place the new piece accordingly
int placePiece(int num, int height, int width, char board[height][width], int win){
  for(int i = height-1; i >= 0; i--){ //This loop places the piece where it needs to be
    if(board[i][num] != 'X'){
      board[i][num] = 'X';
      i = -1;
      win = 0;
      //printf("\ncheck 1\n");
    }
    else if((i == 0) && (board[i][num] == 'X')){ //This loop will break out of the while in createBoard if we're done so that the game can end.
    //printf("\ncheck 2\n");
      win = 1;
    }
  }
  return win;
}

int setPiece(void){ //his function is used so that this class can be checked on its own.
  chooseRow(7);
  return 0;
}
