
#include <iostream>
#include <cstring>
using namespace std;
const bool PlayerX = true;
const bool PlayerO = false;
bool checkWin(struct board* b);
void endGame(struct board* b);
void printBoard(struct board* b);
void playAgain(struct board* b);
bool checkTie(struct board* b);
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

int main()
{
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
	  while(myBoard.running == true){
	  if(myBoard.currentPlayer == true)
	    {
        column = 0;
        row = 0;
	      cout << "Player X, enter your move:" << endl;
	      cin.get(temp, 3, '\n');
	      cin.get();
      column = temp[1]-'0';
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
   cout << row << endl;
   cout << myBoard.board[row][column-1] << endl;
   if(myBoard.board[row][column] == 0){
      myBoard.board[row][column-1] = 1;
        printBoard(&myBoard);
      myBoard.Winning = checkWin(&myBoard);
      endGame(&myBoard);
      myBoard.Tie = checkTie(&myBoard);
      playAgain(&myBoard);
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
     if(myBoard.currentPlayer == false)
	    {
        column = 0;
        row = 0;
	      cout << "Player O, enter your move:" << endl;
	      cin.get(temp2, 3, '\n');
	      cin.get();
        column2 = temp2[1]-'0';
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
 if(myBoard.board[row2][column2-1] == 0){
      myBoard.board[row2][column2-1] = 2;
      printBoard(&myBoard);
      myBoard.Winning = checkWin(&myBoard);
      endGame(&myBoard);
      myBoard.Tie = checkTie(&myBoard);
      playAgain(&myBoard);
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

void printBoard(struct board* b) {
  for(int m = 0; m < 3; m++){
    for(int n = 0; n < 3; n++){
      cout << ' ' << b->board[m][n] << ' ';
    }
    cout << endl;
  }
  //struct game newboard;
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
  
