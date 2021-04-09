/*
 * GameBoard.h
 *
 *  Created on: May 5, 2020
 *      Author: talha
 */
#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_
#include"Menu.h"
#include"Shape.h"
class GameBoard: public Menu {
private:

	int lives;//Total lives of player
	int targetScore;//target of the current game
	Shape **shapes;//a double pointer of shapes class for drawing shapes
	int gameScore;//It is the points or score ,increases with level
public:
	///////////////////////////////////////static variables
	static int coordinate_X1;
	static int coordinate_X2;
	static int coordinate_Y1;
	static int coordinate_Y2;
	static int loadingTime;
	static int xLength;
	static int id1;
	static int id2;
	static int ycoord1;
	static int xcoord1;
	static int ycoord2;
	static int xcoord2;
	static bool status;
	static bool loadingStatus;
	static int TotalTime ;
	static bool TimeTrialStatus;
	static int BarLength;
	static int BarIncrement;
	static int TimeIncrement;
	static int LevelNo;
	static int ScorePerCandy;
	static bool NextLevelStatus;
	static double levelColor;
	static int decision;//decide to display menu /time trial mode/normal mode/pause window
	//static int lives;
	static int highScoreArray[4];
	static vector<int> HighScore;
	static int moves;//total moves
	static int pauseStatus;// check for pausing the game
	/////////////////////////////////////////member functions
	GameBoard();//default constructor
	GameBoard(int l,int ts,int gs,int scp ,int hs,int size );//parameterized constructor
	void displayCandies();//to display candies
	void displayTime();//  to display the time
	void displayScore();//current game score
	void displaylives();//To display lives
	void displayBoundaries();//to display the boundaries of GameBoard
	void displayScorePerCandy();//
	void GameLoading();//to load game before menu
	void swapShape();//to swap the candies
	void match(int ,int ,int);//matching similar candies and destroying them
	void candyRegenerator();//regenerating candies after destroying
	void CandiesTransfer();//It transfer the candies from top to bottom
	void TimeTrialMode();//for time trial mode
	void normalMode();//for normal mode
	void play();//to play or run the game
	void levels();//no of levels
	void ProgressBar(int);// progress bar that increases or decreases with time  and match
	int getXcoordinate(int x);//return x coordinate
	int getYcoordinate(int y);//return y coordinate
	void pauseWindow();// to pause game and display a pause window
	~GameBoard();//destructor
	int getGameScore() const;//returns game score
	void setGameScore(int gameScore);//set game score
	int getLives() const;//return lives
	void setLives(int lives);//set lives
	int getScorePerCandy() const;//return Score Per candy
	void setScorePerCandy(int scorePerCandy);//set score per candy
	int getTargetScore() const;//return target score
	void setTargetScore(int targetScore);// set target score
	void displayHighScore();// display high score window
};

#endif /* GAMEBOARD_H_ */
