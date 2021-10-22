#include <iostream>
#include <cstring>
using namespace std;
const bool PlayerX = true;
const bool PlayerO = false;
bool checkWin(struct board* b);
void endGame(struct board* b);
void printBoard(struct board* b);
void playAgain(struct board* b);
struct board{
  char board[3][3];
  bool currentPlayer;
  bool Winning;
  int xWins;
  int oWins;
  bool playing;
  bool running;
};

int main()
{
  struct board myBoard;
  myBoard.playing = true;
  myBoard.running = true;
  char temp[2];
  int column = 0;
  int row = 0;
  char temp2[2];
  int column2 = 0;
  int row2 = 0;
  myBoard.Winning = true;
  myBoard.xWins = 0;
  myBoard.oWins = 0;
  memset(myBoard.board, 0,9);
  while(myBoard.playing == true){
myBoard.currentPlayer = true;
cout << "Welcome to TicTacToe. \n There will be two players, and X will have the first move." << endl;
          cout<< "Player X please enter a valid move e.g 'a1' " << endl;	  
	  printBoard(&myBoard);
	  while(myBoard.running = true){
	  if(myBoard.currentPlayer == true)
	    {
	      cout << "Player X, enter your move:" << endl;
	      cin.get(temp, 3, '\n');
	      cin.get();
	      cout << temp << endl;
      column = temp[1]-'0';
      cout << temp[1] << endl;
      if(1 <= column <= 3){
      if('a' <= temp[0] <='c'){
	 if(temp[0] == 'a'){
	   row = 0;
	 }
	 if(temp[0] == 'b'){
	   row = 1;
	 }
	 if(temp[0] == 'c'){
	   row = 2;
	 }
	 if(myBoard.board[row][column-1] == '\0'||' '){
 cout << "This is the X: " << column-1 << endl;
 cout << "This is the Y: " << row << endl;
      myBoard.board[row][column-1] = 'X';
      myBoard.Winning = checkWin(&myBoard);
      endGame(&myBoard);
      playAgain(&myBoard);
      myBoard.currentPlayer = false;
      printBoard(&myBoard);
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
     if(myBoard.currentPlayer == false)
	    {
	      cout << "Player O, enter your move:" << endl;
	      cin.get(temp2, 3, '\n');
	      cin.get();
      column2 = temp2[1]-'0';
      if(1 <= column2 <= 3){
      if('a' <= temp2[0] <='c'){
 if(temp2[0] == 'a'){
   row2 = 0;
 }
 if(temp[0] == 'b'){
   row2 = 1;
 }
 if(temp[0] == 'c'){
   row2 = 2;
 }
 if(myBoard.board[row2][column2-1] == '\0'||' '){
      myBoard.board[row2][column2-1] = 'O';
      printBoard(&myBoard);
      myBoard.Winning = checkWin(&myBoard);
      endGame(&myBoard);
      playAgain(&myBoard);
      myBoard.currentPlayer = true;
 }
 else{
	  cout << "Please enter a valid move e.g. a1" << endl;
	}
      }
      else{
	cout << "Please enter a valid move (e.g a1, b2, c3, etc)." << endl;
      }
      }
      else{
	  cout << "Please enter a valid move e.g. a1" << endl;
	}
	    }
	  }
  }
}

bool checkWin(struct board* b){
  char player = ' ';
  if(b->currentPlayer == false){
    char player = 'O';
  }
  if(b->currentPlayer == true){
    char player = 'X';
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

void printBoard(struct board* b){
cout << "  1  2  3" << endl;
  for(int m = 0; m < 3; m++){
    cout << (char)('a' + (char)m);
    for(int n = 0; n < 3; n++){
      cout<<' '<< b->board[m][n] << ' ';
    }
    cout << endl;
  }
}

void endGame(struct board* b){
  int winCount = 0;
  if(b->Winning == true){
  if(b->currentPlayer == true){
    b->xWins++;
    cout << "Player X" << " has won!" << endl;
    cout << "They have won " << b->xWins << " times." << endl; 
    b->running = false;
  }
  if(b->currentPlayer == false){
    b->oWins++;
    cout << "Player O" << " has won!" << endl;
    cout << "They have won " << b->oWins << " times." << endl;
    b->running = false;
  }  
  }
}

void playAgain(struct board* b){
  char redo[1];
  memset(redo,0 , 1);
  if(b->Winning == true){
    cout << "Do you want to play again? (y or n)" << endl;
    cin.get(redo,1);
    cin.get();
    if(redo == "y"){
      b->playing = true;
      b->running = true;
    }
    if(redo == "n"){
      b->playing = false;
    }
  }
}

