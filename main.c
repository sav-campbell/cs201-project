#include <stdio.h>
#include <ctype.h>
#include "createBoard.c"

int main(void){
  int players, winner;
  int score1 = 0;
  int score2 = 0;
  char answer[10];
  initialize(10, answer);
  char choice[10];
  initialize(10, choice);

  printf("Welcome to Connect Four!! \n\nPlease choose a game type:\n\n");
  printf("1. Player vs. Computer\n");
  printf("2. Player vs. Player\n");
  printf("3. Computer vs. Computer\n");
  while(1){
    printf("\nPlease type \"1\" or \"2\" or \"3\"\n");
    scanf("%9s", choice);
    players = numCheck(strlen(choice), choice);
    if(players == 1){
      printf("\nPlayer vs. Computer Selected. Generating Board.\n\n");
      break;
    }
    else if(players == 2){
      printf("\nPlayer vs. Player Selected. Generating Board.\n\n");
      break;
    }
    else if(players == 3){
      printf("\nComputer vs. Computer Selected. Generating Board.\n\n");
      break;
    }
    else
      printf("\nInvalid entry.");
  }


  while(1){
    winner = generateBoard(players);
    if(winner == 1){
      printf("\nPlayer 1 wins!\n\n");
      score1++;
    }
    else if(winner == 2){
      printf("\nPlayer 2 wins!\n\n");
      score2++;
    }
    else if(winner == 3)
      printf("\nIt's a tie!\n\n");

    printf("\nScore: \nPlayer 1: %d \nPlayer 2: %d", score1, score2);
    printf("\nWould you like to play again (Y/N)?");
    scanf("%9s", answer);
    if(tolower(answer[0]) != 'n' && tolower(answer[0]) != 'y'){
      while(1){
        printf("\nInvalid input. Enter 'y' or 'n'");
        scanf("%9s", answer);
        if(tolower(answer[0]) == 'y')
          break;
        else if(tolower(answer[0] == 'n'))
          break;
      }
    }
    if(tolower(answer[0]) == 'n')
      break;
  }

  return 0;
}
