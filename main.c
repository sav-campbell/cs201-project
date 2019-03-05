#include <stdio.h>
#include "createBoard.c"

int main(void){
  int players;

  printf("Welcome to Connect Four!! \n\nPlease choose a game type:\n\n");
  printf("1. Player vs. Computer\n");
  printf("2. Player vs. Player\n");
  printf("3. Computer vs. Computer\n");
  printf("\nPlease type \"1\" or \"2\" or \"3\"\n");
  scanf("%d", &players);
  if(players == 1)
    printf("\nPlayer vs. Computer Selected. Generating Board.\n\n");
  if(players == 2)
    printf("\nPlayer vs. Player Selected. Generating Board.\n\n");
  if(players == 3)
    printf("\nComputer vs. Computer Selected. Generating Board.\n\n");

  generateBoard();


  return 0;
}
