#include <stdio.h>

int chooseRow(int width){
  int choice;
  while(1)
  {
    printf("what column would you like to place a piece in?\n");
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
//place the new piece accordingly
void placePiece(int num, int height,int width, char board[height][width]){
  for(int i = 0; i < height; i++){

  }
}

int setPiece(void){
  chooseRow(7);
  return 0;
}
