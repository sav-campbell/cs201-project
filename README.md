This code is written by Savannah Campbell for CS 201 at The University of Alabama.
It is a Connect 4 game with three different game modes!

This Connect 4 game follows the basic rules of Connect 4. First, the main menu lets the user choose one of three game modes
(1) Player vs. Computer, (2) Player vs. Player, or (3) Computer vs. Computer. Then, the user is allowed to enter an appropriate
board size for the game. They cannot enter a board with dimensions less than 4x4 due to the nature of Connect 4. If the user 
attempts to enter less than a 4x4, they will be prompted to re-enter the dimensions. Alternatively, if the user attempts
to enter dimensions greater than 40x40, the program will tell the user that large board sizes are unweildy and gives them the option
of entering a different board size. 

Once the user has chosen the board size, the board is generated and printed to the screen, allowing the user to start the game!
The user(s) enter the column that they would like to place their piece in and, on each entry, the computer checks for a win 
through a Depth First Search. It checks each direction of the board until it reaches a peice that is not equal to the current
peice value (either an 'X' or 'O') and returns the length of the search. Searches greater than or equal to four result in a 
win for the player.

Once there has been a win or a tie, the user is shown the player scores and asked if they would like to play again. If they choose 
to play again, they will have the option of changing the board size. Any wins recorded before the user exits the game, are added to
the overall player scores. 

You can view a YouTube video of me walking through the program and its game types here:
https://youtu.be/xH4CkU3phHw 

In order to play Connect 4, follow these steps:
1. Download the zip file from github
2. Type "gcc -Wall main.c -std=c11 -o connect4" (capitalization matters!)
3. Type "./connect4" (once again, capitalization matters!)
4. Enjoy the game!

General Information:
1. Depth First Search
For this program, I implemented some Depth First Search functions to both check for user wins and determing the computer's next move.
The functions check in a given direction until they find a piece that is not equal to the inital search piece. It then returns
the length of the search. For the check for user wins, if any of the searches return a number greater than or equal to 4, the
program returns a win for the user that placed the last piece. 

2. How does the computer choose a move?
The computer chooses a move through the same depth first search functions that check for wins. The computer has three functions
for choosing a move that are ordered by priority. The computer first checks for any chances of winning, and, if there is 
a winning move available, will take that move. If there is not a winning move, the computer checks for a chance to block the 
other player from winning. If the other user has a three in a row (a chance for them to win on the next turn), the computer
will use their move to block the other user from winning. The last choice for the computer, if there was not a winning or 
blocking move, is to take the move that gives them the longest string of pieces. It uses the DFS functions to get the values for
each direction for each possible location on the board, and returns the column that would give them the max search.

3. Computer vs. Computer
I have implemented a computer vs. computer mode for Connect 4! The bots are evenly matched as they use the same algorithm to check
for their move. The only randomization is for the first choice of column in which the bot will randomly generate a first choice
and will then choose their actual placement from the functions listed above. This allows the computer to make a move other than
the first column for their first more. (As the max returned from the checkGreatest function will be the column that the 
computer chooses as there is no "best" move yet.)

