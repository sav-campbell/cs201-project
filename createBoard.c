/*Savannah Campbell sjcampbell3@crimson.ua.edu
The createBoard class is used to create the board that the player will see and
transfer the necessary information that it takes in to the class that checks
for wins and creates the actual game mechanics. This class makes the UI easier
to maintain rather than working through the search functions each time.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "setPiece.c"

//This function initializes the board array that the user will see.
void fillBoard(int x, int y, char board[x][y]){
  for(int i = 0; i < x; i++){
    for(int j = 0; j <= y; j++){
        board[i][j] = ' ';
    }
  }
}

//This function prints the board whenever it is called.
void printBoard(int x, int y, char print[x][y]){

  for(int i = 0; i < x; i++){
    if(i == 0)
      printf("\n\n***\tCONNECT FOUR!\t***\n\n");
    for(int j = 0; j < y; j++){
      /*Check if(j == 0)
        printf("%d ", i);*/
      printf("| ");
      printf("%c ", print[i][j]);
      if(j == y-1)
        printf("|");
    }
    printf("\n");
  }
}


//This function prints an array that is the width of the board.
//The num array makes it easier for users to choose the row they are placing in.
void printNum(int x, int print[x]){
//  printf(" ");
  for(int i = 0; i < x; i++){
    if(i < 10)
      printf("  %d ", print[i]);
    else
      printf(" %d ", print[i]);

  }
}

/*The generateBoard function controls the UI of the game while it's being played.
It initializes the board and passes the game type and user inputs into the
searchBoard, setPiece, and bot functions. It controls the actual game.*/
int generateBoard(int playType){
  int width, height;

  //This loop gets a valid size for the board
  while(1){
    char answer[10];
    initialize(10, answer);
    char input[50];
    initialize(50, input);
    printf("\nWhat is the height of the board?");
    scanf("%49s", input);
    height = numCheck(strlen(input), input);
    printf("\nWhat is the width of the board?");
    scanf("%49s", input);
    width = numCheck(strlen(input), input);
    if(height < 4 || width < 4)
      printf("\nThe height and width must be greater than or equal to 4.\nTry again.\n");
    else if(height > 40 || width > 40){
      printf("\nBoard sizes greater than 40x40 will have unweildy screen handling.");
      printf("\nDo you wish to continue anyway (Y/N)?");
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
      else if(tolower(answer[0]) == 'y')
        break;
    }
    else
      break;
  }

  char board[height][width];
  int rowNum[width]; //this will help the player know what row they're dropping the piece in
  int num = 1;

  //This loop fills rowNum bc I don't want to make a function for it.
  for(int i = 0; i < width; i++)
  {
    rowNum[i] = num;
    num++;
  }

  fillBoard(height, width, board);
  int win = 0;
  int pieces = 0;

  /*This switch statment controls the game type and the actual game play of
  connect four by passing the information into the other classes.*/
  switch(playType){
    case 1:
    while(win == 0){
      printBoard(height, width, board);
      printNum(width, rowNum);
      printf("\nPlayer One's Turn:");
      win = placePiece(chooseRow(width), height, width, board, 1, 1);
      pieces++;
      if(pieces == width*height)
        win = 3;
      if(win != 0)
        break;
      printBoard(height, width, board);
      printNum(width, rowNum);
      printf("\nPlayer Two's Turn: \n");
      win = placePiece(compChoice(height, width, board, 2), height, width, board, 2, 2);
      pieces++;
      if(pieces == width*height)
        win = 3;
    } break;
    case 2:
    while(win == 0){
      printBoard(height, width, board);
      printNum(width, rowNum);
      printf("\nPlayer One's Turn:\n");
      win = placePiece(chooseRow(width), height, width, board, 1, 1);
      pieces++;
      if(pieces == width*height)
        win = 3;
      if(win != 0)
        break;
      printBoard(height, width, board);
      printNum(width, rowNum);
      printf("\nPlayer Two's Turn:\n");
      win = placePiece(chooseRow(width), height, width, board, 2, 1);
      pieces++;
      if(pieces == width*height)
        win = 3;
    } break;
    case 3:
    while(win == 0){
      printBoard(height, width, board);
      printNum(width, rowNum);
      printf("\nPlayer One's Turn:\n");
      win = placePiece(compChoice(height, width, board, 1), height, width, board, 1, 2);
      pieces++;
      if(pieces == width*height)
        win = 3;
      if(win != 0)
        break;
      printBoard(height, width, board);
      printNum(width, rowNum);
      printf("\nPlayer Two's Turn:\n");
      win = placePiece(compChoice(height, width, board, 2), height, width, board, 2, 2);
      pieces++;
      if(pieces == width*height)
        win = 3;
    } break;
    default: break;
  }


  printBoard(height, width, board);
  printNum(width, rowNum);
  return win;
}
