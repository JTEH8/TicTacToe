//A two player game of Tic-Tac-Toe through the console.
#include <iostream>
#include <cstring>
using namespace std;
//Methods
bool checkWin(struct board* b);
void endGame(struct board* b);
void printBoard(struct board* b);
void playAgain(struct board* b);
bool checkTie(struct board* b);
//Struct for board, which stores, the board, # of wins, as well as booleans.
struct board{
  int board[3][3];
  bool currentPlayer;
  bool Winning;
  int xWins;
  int oWins;
  bool playing;
  bool running;
  bool Tie;
  bool over;
};

//Main method
int main()
{
//Creatiing Variables
  struct board myBoard;
  myBoard.playing = true;
  myBoard.running = true;
  myBoard.Tie = false;
  myBoard.over = false;
  char temp[3];
  int column = 0;
  int row = 0;
  char temp2[3];
  int column2 = 0;
  int row2 = 0;
  myBoard.Winning = true;
  myBoard.xWins = 0;
  myBoard.oWins = 0;
  while(myBoard.playing == true){
  myBoard.currentPlayer = true;
 //Prompt text
  cout << "Welcome to TicTacToe. \n There will be two players, and X will have the first move." << endl;
          cout<< "Player X please enter a valid move e.g 'a1' " << endl;	  
	  for(int a = 0; a < 3; a++){
	    for(int b = 0; b < 3; b++){
	      myBoard.board[a][b] = '\0';
	    }
	  }
    myBoard.running = true;
    myBoard.over = false;
	  printBoard(&myBoard);
	  //Switches between two players
	  while(myBoard.running == true){
	//X's turn
	  if(myBoard.currentPlayer == true)
	    {
        column = 0;
        row = 0;
	      cout << "Player X, enter your move:" << endl;
	      cin.get(temp, 3, '\n');
	      cin.get();
      column = temp[1]-'0';
		  //Checking valid input
      if(('a' == temp[0]) || (temp[0] == 'b') || (temp[0] == 'c')){
        cout << column << endl;
    if((1 == column)|| (column == 2) || (column == 3)){
	 if(temp[0] == 'a'){
	   row = 0;
	 }
	 if(temp[0] == 'b'){
	   row = 1;
	 }
	 if(temp[0] == 'c'){
	   row = 2;
   }
	    //If the space is empty
   if(myBoard.board[row][column] == 0){
      myBoard.board[row][column-1] = 1;
        printBoard(&myBoard);
      myBoard.Winning = checkWin(&myBoard);
      endGame(&myBoard);
      myBoard.Tie = checkTie(&myBoard);
      playAgain(&myBoard);
	   //If the game restarts
      if(myBoard.over == true){
      break;
      }
      myBoard.currentPlayer = false;
   }
    else{
     cout << "Please enter a valid input. e.g a1";
   }
	 }
   else{
     cout << "Please enter a valid input. e.g a1";
   }
      }
       else{
	  cout << "Please enter a valid move e.g. a1" << endl;
	    }
	//O's Turn
     if(myBoard.currentPlayer == false)
	    {
        column2 = 0;
        row2 = 0;
	      cout << "Player O, enter your move:" << endl;
	      cin.get(temp2, 3, '\n');
	      cin.get();
        column2 = temp2[1]-'0';
	     //Checking valid input
        if(('a' == temp2[0]) || (temp2[0] == 'b') || (temp2[0] == 'c')){
    if((1 == column2)|| (2 == 2) || (column2 == 3)){
 if(temp2[0] == 'a'){
   row2 = 0;
 }
 if(temp2[0] == 'b'){
   row2 = 1;
 }
 if(temp2[0] == 'c'){
   row2 = 2;
 }
	    //If the space is empty
 if(myBoard.board[row2][column2-1] == 0){
      myBoard.board[row2][column2-1] = 2;
      printBoard(&myBoard);
      myBoard.Winning = checkWin(&myBoard);
      endGame(&myBoard);
      myBoard.Tie = checkTie(&myBoard);
      playAgain(&myBoard);
	 //If game needs to restart
      if(myBoard.over == true){
      break;
      }
      myBoard.currentPlayer = true;
 }
 else{
	  cout << "Please enter a valid move e.g. a1" << endl;
      }
      }
       else{
	  cout << "Please enter a valid move e.g. a1" << endl;
      }
	}
   else{
	  cout << "Please enter a valid move e.g. a1" << endl;
      }
  }
}
}  
}
}
//Checks all win conditions (similar to Java code)
bool checkWin(struct board* b){
  int player = 0;
  if(b->currentPlayer == true){
    player = 1;
  }
  if(b->currentPlayer == false){
    player = 2;
  }
 if (b->board[0][0] == player && b->board[0][1] == player && b-> board[0][2] == player){
    return true;
  }
  //diagonal from top left to bottom right
  if (b->board[0][0] == player && b->board[1][1] == player && b->board[2][2] == player){
    return true;
  }
  //middle row
  if (b->board[1][0] == player && b->board[1][1] == player && b->board[1][2] == player){
    return true;
  }
  //bottom row
  if (b->board[2][0] == player && b->board[2][1] == player && b->board[2][2] == player){
    return true;
  }
  //left column
  if (b->board[0][0] == player && b->board[1][0] == player && b->board[2][0] == player){
    return true;
  }
  // middle column
  if (b->board[0][1] == player && b->board[1][1] == player && b->board[2][1] == player){
    return true;
  }
  //right column
  if (b->board[0][2] == player && b->board[1][2] == player && b->board[2][2] == player){
    return true;
  }
  //diagonal from bottom left to top right
  if (b->board[2][0] == player && b->board[1][1] == player && b->board[0][2] == player){
    return true;
  }
  return false;
}
//Prints the board one line at a time. (Help from Nihal Parthasarathy and Ehan Masud) 
void printBoard(struct board* b) {
  int num = 1;
  cout << "  1 2 3" << endl;
  for (int i = 0; i < 3; i++) {
    cout << '\0' << endl;
    cout << (char)('a' + (char)(num-1));
    num++;
    for (int j=0; j < 3; j++) {
      cout << ' ';
       if (b->board[i][j] == 0) {
         cout << ' ';
       }
       if (b->board[i][j] == 1) {
         cout << 'X';
       }
       if (b->board[i][j] == 2) {
         cout << 'O';
       }
    }
    cout << '\0' << endl;
  }
}
//Ending the game and adding to win count
void endGame(struct board* b){
  int winCount = 0;
  if(b->Winning == true){
  if(b->currentPlayer == true){
    b->xWins++;
    cout << "Player X has won!" << endl;
    cout << "They have won " << b->xWins << " times." << endl; 
    //b->running = false;
  }
  if(b->currentPlayer == false){
    b->oWins++;
    cout << "Player O has won!" << endl;
    cout << "They have won " << b->oWins << " times." << endl;
    //b->running = false;
  }  
  }
}
//Asks the user to play again, and breaks out of while loop to go back to start.
void playAgain(struct board* b){
  char redo[2];
  memset(redo, 0, 2);
  if(b->Winning == true){
    b->Winning = false;
    cout << "Do you want to play again? (y or n)" << endl;
    cin.get(redo,2);
    cin.get();
    cout << redo << endl;
    if(redo[0] == 'y'){
        b->over = true;
      b->playing = true;
      b->running = true;
    }
    if(redo[0] == 'n'){
        cout << "Thanks for playing!" << endl;
        cout << "X has won: " << b-> xWins << " times." << endl;
        cout << "O has won: " << b-> oWins << " times." << endl;
        b->playing = true;
      b->running = true;
      exit(0);
    }
  }
//What happens when it's a tie
    if(b->Tie == true){
    cout << "That's a tie!" << endl;
    cout << "Do you want to play again? (y or n)" << endl;
    cin.get(redo,1);
    cin.get();
    if(redo[0] == 'y'){
        b->over = true;
      b->playing = true;
      b->running = true;
    }
    if(redo[0] == 'n'){
        cout << "Thanks for playing!" << endl;
        cout << "X has won: " << b-> xWins << " times." << endl;
        cout << "O has won: " << b-> oWins << " times." << endl;
      exit(0);
    }
  }
}
//Checks if it's a tie (again, help from Nihal Parthasarathy)
bool checkTie(struct board* b){
  for(int m = 0; m < 3; m++){
    for(int n = 0; n < 3; n++ ){
      if(b->board[m][n] == 0){
        return false;
      }
    }
    }
    return true;    
  }
  
