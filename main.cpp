#include <iostream>
#include <string>
using namespace std;

/*
-------------------------------------------------
Basic naughts and crosses programme for terminal
by Cold_Clock
First version 26/06/2017
2 Player Only - No AI
-------------------------------------------------
*/

int main()
{
    //Prints title text
    cout << "Welcome to Naughts and Crosses! \n";
    cout << "Made by Rowan Upstone 2017 \n \n";
    //Start Point for future use - we use it later to restart the game from here
    completeStart:
    //Sets up variables for player names
    string nameA;
    string nameB;
    int round;
    round=1;
    //Player name entry
    cout << "Enter player 1 name: ";
    cin >> nameA;
    cout << "Enter player 2 name: ";
    cin >> nameB;
    //The point where the game restarts if players want to use old player names
    restartPoint:
    //All initial set up
    //turn is the counter for what turn we're on
    int turn=1;
    //This bool is to termine a O or X turn, it starts at 0 for an X turn
    bool switchTurn=0;
    //This is just how we work out if the game is over, 0 means we are playing/draw, 1 means X victory and 2 means O victory
    int winner=0;
    //set up grid array for display and logic
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    //Store match title info
    string matchTitle=nameA+" vs. "+nameB+" | Round: ";
    //Pretty divider
    cout << endl << "------------" << endl;
    //Print match title
    cout << endl << matchTitle << round << endl << endl;
    //Draw the initial board
    cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "  1" << "|" << "2" << "|" << "3" << endl;
    cout << "-----" << "  -----" << endl;
    cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "  4" << "|" << "5" << "|" << "6" << endl;
    cout << "-----" << "  -----" << endl;
    cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "  7" << "|" << "8" << "|" << "9" << endl;
    cout << endl;
    //Call back point for turns that haven't won the game
    turnstart:
    //Print turn infomation
    cout << endl << "Turn: " << turn << endl << endl;
    //draw conditions
    if (turn==10){
    cout << endl << "DRAW!" << endl;
    goto ending;
    }
    //Player 1 - X Turn
    player1input:
    if (switchTurn==0){
    //Player move
    //Creating a holder for player move data and bool for whether the move is correct
    int player1move=0;
    //bool correctMove1=0;
    //Player input
    cout << nameA << "'s move: ";
    cin >> player1move;
    //too high return
    if (player1move>9){
    cout << endl << "Too high, enter a number between 1-9!" << endl << endl;
    goto player1input;
    }
    //too low return
    if (player1move<1){
    cout << endl << "Too low, enter a number between 1-9!" << endl << endl;
    goto player1input;
    }
    //Move processing, initially we make a string to call back to if the space is taken - we use it later
    string spaceTaken="This space is taken, please pick another!";
    //Some generic text to show this move is an acceptable input
    cout << endl << "OK!" << endl << endl;
    //move if statements, if the space in the array is blank then write to it, else, print it is incorrect and restart input
    if (player1move==1){
    if (board[0][0]==' '){
    board[0][0]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    if (player1move==2){
    if (board[0][1]==' '){
    board[0][1]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    if (player1move==3){
    if (board[0][2]==' '){
    board[0][2]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    if (player1move==4){
    if (board[1][0]==' '){
    board[1][0]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    if (player1move==5){
    if (board[1][1]==' '){
    board[1][1]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    if (player1move==6){
    if (board[1][2]==' '){
    board[1][2]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    if (player1move==7){
    if (board[2][0]==' '){
    board[2][0]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    if (player1move==8){
    if (board[2][1]==' '){
    board[2][1]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    if (player1move==9){
    if (board[2][2]==' '){
    board[2][2]='X';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player1input;
    }
    }
    //Draw updated board
    cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "  1" << "|" << "2" << "|" << "3" << endl;
    cout << "-----" << "  -----" << endl;
    cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "  4" << "|" << "5" << "|" << "6" << endl;
    cout << "-----" << "  -----" << endl;
    cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "  7" << "|" << "8" << "|" << "9" << endl;
    cout << endl;
    //conditional set up that helps trigger a win
    bool win=0;
    //X winners logic, this goes through all the possible ways to win and sets the values for an X win then dumps us
    //to a victory message
    if (board[0][0]=='X'&&board[0][1]=='X'&&board[0][2]=='X'){
    win=1;
    winner=1;
    }
    if (board[1][0]=='X'&&board[1][1]=='X'&&board[1][2]=='X'){
    win=1;
    winner=1;
    }
    if (board[2][0]=='X'&&board[2][1]=='X'&&board[2][2]=='X'){
    win=1;
    winner=1;
    }
    if (board[0][0]=='X'&&board[1][0]=='X'&&board[2][0]=='X'){
    win=1;
    winner=1;
    }
    if (board[0][1]=='X'&&board[1][1]=='X'&&board[2][1]=='X'){
    win=1;
    winner=1;
    }
    if (board[0][2]=='X'&&board[1][2]=='X'&&board[2][2]=='X'){
    win=1;
    winner=1;
    }
    if (board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X'){
    win=1;
    winner=1;
    }
    if (board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X'){
    win=1;
    winner=1;
    }
    //This is the if that takes us to victory
    if (win==1){
    goto ending;
    }
    //For non victors, this adds one to the turn and switches controll to O restarting the turn process
    turn++;
    switchTurn=1;
    goto turnstart;
    }
    //Player 2 - O Turn
    if (switchTurn==1){
    //All of this is the same as X with basic values changed so if you want to know whats going on then check X's turn
    //That's why some isn't commented
    //Creating a holder for player move data and bool for whether the move is correct
    int player2move=0;
    //bool correctMove2=0;
    //Player input
    player2input:
    cout << nameB << "'s move: ";
    cin >> player2move;
    //too high return
    if (player2move>9){
    cout << endl << "Too high, enter a number between 1-9!" << endl << endl;
    goto player2input;
    }
    //too low return
    if (player2move<1){
    cout << endl << "Too low, enter a number between 1-9!" << endl << endl;
    goto player2input;
    }
    //correct move message
    //correctMove2=1;
    string spaceTaken="This space is taken, please pick another!";
    cout << endl << "Valid move!" << endl << endl;
    if (player2move==1){
    if (board[0][0]==' '){
    board[0][0]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    }
    }
    if (player2move==2){
    if (board[0][1]==' '){
    board[0][1]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    }
    }
    if (player2move==3){
    if (board[0][2]==' '){
    board[0][2]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    }
    }
    if (player2move==4){
    if (board[1][0]==' '){
    board[1][0]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    }
    }
    if (player2move==5){
    if (board[1][1]==' '){
    board[1][1]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    }
    }
    if (player2move==6){
    if (board[1][2]==' '){
    board[1][2]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    };
    }
    if (player2move==7){
    if (board[2][0]==' '){
    board[2][0]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    }
    }
    if (player2move==8){
    if (board[2][1]==' '){
    board[2][1]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    }
    }
    if (player2move==9){
    if (board[2][2]==' '){
    board[2][2]='O';
    }
    else{
    cout << spaceTaken << endl << endl;
    goto player2input;
    }
    }
    cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "  1" << "|" << "2" << "|" << "3" << endl;
    cout << "-----" << "  -----" << endl;
    cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "  4" << "|" << "5" << "|" << "6" << endl;
    cout << "-----" << "  -----" << endl;
    cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "  7" << "|" << "8" << "|" << "9" << endl;
    cout << endl;
    bool win=0;
    if (board[0][0]=='O'&&board[0][1]=='O'&&board[0][2]=='O'){
    win=1;
    winner=2;
    }
    if (board[1][0]=='O'&&board[1][1]=='O'&&board[1][2]=='O'){
    win=1;
    winner=2;
    }
    if (board[2][0]=='O'&&board[2][1]=='O'&&board[2][2]=='O'){
    win=1;
    winner=2;
    }
    if (board[0][0]=='O'&&board[1][0]=='O'&&board[2][0]=='O'){
    win=1;
    winner=2;
    }
    if (board[0][1]=='O'&&board[1][1]=='O'&&board[2][1]=='O'){
    win=1;
    winner=2;
    }
    if (board[0][2]=='O'&&board[1][2]=='O'&&board[2][2]=='O'){
    win=1;
    winner=2;
    }
    if (board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O'){
    win=1;
    winner=2;
    }
    if (board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O'){
    win=1;
    winner=2;
    }
    if (win==1){
    goto ending;
    }
    turn++;
    switchTurn=0;
    goto turnstart;
    }
    //Ending screen info
    ending:
    //Checks for draw
    if (turn!=10){
    string winnerName;
    //Finds out who won and writes name in string
    if (winner==1){
    winnerName = nameA;
    }
    if (winner==2){
    winnerName = nameB;
    }
    //Prints message using winner's name from string found earlier in this if statement
    cout << endl << "A winner is you " << winnerName << "!" << endl;
    }
    //Ask player if they want to play again
    char restart=' ';
    cout << endl << "Do you want to play again? (Y/N): ";
    //Restart point for failed answers
    rematchQuestion:
    cin >> restart;
    //Process results - Y to next section, X returns 0 to quit - input will process upper and lower case
    if (restart=='Y'){
    round++;
    goto newNameQuestion;
    }
    if (restart=='N'){
    return 0;
    }
    if (restart=='y'){
    round++;
    goto newNameQuestion;
    }
    if (restart=='n'){
    return 0;
    }
    //if result not y or n then it will ask to input again
    cout << endl << "Sorry, I didn't catch that. Please type again (Y/N):";
    goto rematchQuestion;
    //After asking for new game, we now ask if they want a rematch - meaning do they want to keep there old names
    //and start a new round or do they want to start fresh
    newNameQuestion:
    char newName2=' ';
    cout << endl << "Do you want a rematch? (Y/N): ";
    //another restart point for failed answers
    q1:
    cin >> newName2;
    //Result processing
    if (newName2=='N'){
    round=0;
    goto completeStart;
    }
    if (newName2=='Y'){
    goto restartPoint;
    }
    if (newName2=='n'){
    round=0;
    goto completeStart;
    }
    if (newName2=='y'){
    goto restartPoint;
    }
    //unexpected result processing
    cout << endl << "Sorry, I didn't catch that. Please type again (Y/N):";
    goto q1;
    //If the code somehow ends up here it will quit
    return 0;
}
