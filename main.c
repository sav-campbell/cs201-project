#include <stdio.h>
#include <ctype.h>
#include "createBoard.c"

int main(void){
  int players, winner;
  int score1 = 0;
  int score2 = 0;
  char answer;

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

  while(1){
    winner = generateBoard();
    if(winner == 1){
      printf("\nPlayer 1 wins!\n\n");
      score1++;
    }
    else{
      printf("\nPlayer 2 wins!\n\n");
      score2++;
    }
    printf("\nScore: \nPlayer 1: %d \nPlayer 2: %d", score1, score2);
    printf("\nWould you like to play again (Y/N)?");
    scanf(" %c", &answer);
    answer = tolower(answer);
    if(answer == 'n')
      break;
  }
  return 0;
}
