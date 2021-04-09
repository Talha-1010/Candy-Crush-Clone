/*
 * GameBoard.cpp
 *
 *  Created on: May 5, 2020
 *      Author: talha
 */
#include "GameBoard.h"
#include"Shape.h"
#include"util.h"
#include<iostream>
#include "fstream"
using namespace std;
GameBoard::GameBoard():Menu() {
	lives=0;
	targetScore=0;
	gameScore=0; //current game SCore
	ScorePerCandy=0;//It is the points or score
	shapes=nullptr;
}

GameBoard :: GameBoard (int l,int ts,int gs,int scp ,int hs,int size):Menu(hs){
	lives=l;
	targetScore=ts;
	gameScore=gs; //current game
	ScorePerCandy=scp;

	shapes =new Shape*[size];
	for(int i=0;i<size;i++)
	{
		shapes[i]=new Shape[size];
	}
}

void GameBoard::displayCandies() {
	int px=330,py=660;
	static int count=0;
	count+=1;



	if(count==1)
	{
		srand(time(NULL));

		for(int i=0; i<8; i++)
		{
			for(int j=0;j<8;j++)
			{
				int x =rand() % 5+1;
				this->shapes[i][j].setId(x);
			}
		}

	}


	for(int i=0;i<8;i++)
	{

		px=330;
		for(int j=0;j<8;j++)
		{
			px+=50;
			for(int k=0;k<1;k++)
			{
				if(this->shapes[i][j].getId()==1)
				{

					DrawRectangle(px, py, 35, 30, colors[SKY_BLUE]);
					this->shapes[i][j].setPos_x(px);
					this->shapes[i][j].setPos_y(py);


				}


				if(this->shapes[i][j].getId()==2)
				{
					DrawTriangle( px, py , px+40, py , px+20 , py+40, colors[GREEN] );
					this->shapes[i][j].setPos_x(px);
					this->shapes[i][j].setPos_y(py);


				}

				if(this->shapes[i][j].getId()==3){

					DrawCircle(px+20,py+20,20,colors[WHITE]);
					this->shapes[i][j].setPos_x(px);
					this->shapes[i][j].setPos_y(py);

				}

				if(this->shapes[i][j].getId()==4){
					DrawRoundRect(px, py, 35, 30, colors[BLUE], 10);
					this->shapes[i][j].setPos_x(px);
					this->shapes[i][j].setPos_y(py);

				}

				if(this->shapes[i][j].getId()==5){
					DrawSquare(px, py, 30, colors[CHOCOLATE]);
					this->shapes[i][j].setPos_x(px);
					this->shapes[i][j].setPos_y(py);

				}

			}
		}
		py-=70;
	}
}

void GameBoard::displayScore() {
	DrawString(50, 800, "Score = "+Num2Str(gameScore) , colors[MISTY_ROSE]);
}

void GameBoard::displaylives() {
	DrawString(800, 800, "lives" , colors[MISTY_ROSE]);
}

void GameBoard::displayBoundaries() {
	DrawLine( 780 , 60 ,  780 , 750 , 10 , colors[MISTY_ROSE] );
	DrawLine( 780 , 750 ,  360 , 750 , 10 , colors[MISTY_ROSE] );
	DrawLine( 360 , 60 ,  360 , 750 , 10 , colors[MISTY_ROSE] );
	DrawLine( 360 , 60 ,  780 , 60 , 10 , colors[MISTY_ROSE] );
}

void GameBoard::displayScorePerCandy() {
	DrawString(400, 80, "SCORE PER CANDY = "+Num2Str(ScorePerCandy), colors[MISTY_ROSE]);
}
int GameBoard::id1=0;
int GameBoard::id2=0;
int GameBoard:: ycoord1=0;
int GameBoard:: xcoord1=0;
int GameBoard:: ycoord2=0;
int GameBoard:: xcoord2=0;
bool GameBoard::status=false;

void GameBoard:: swapShape()
{
		bool newcond1=false;
		bool newcond2=false;

		if ((GameBoard::coordinate_X1-GameBoard::coordinate_X2<=70 || GameBoard::coordinate_X1-GameBoard::coordinate_X2>=-70 ) && (GameBoard::coordinate_Y1-GameBoard::coordinate_Y2<=120))
		{
			for(int i=0;i<8;i++)
			{
				for (int j = 0; j < 8; j++)
				{
					for(int k=0;k<1;k++)
					{
						if(( this->shapes[i][j].getPos_x() >= (GameBoard::coordinate_X1-25)
								&& this->shapes[i][j].getPos_x()<= (GameBoard::coordinate_X1+25) )
								&&  (this->shapes[i][j].getPos_y() >=(GameBoard::coordinate_Y1-40)
										&& this->shapes[i][j].getPos_y()<=(GameBoard::coordinate_Y1+40) ) )
						{
							id1=this->shapes[i][j].getId();
							ycoord1=i;
							xcoord1=j;
							newcond1=true;
							break;
						}
						else if( ( this->shapes[i][j].getPos_x()>= (GameBoard::coordinate_X2-25)
								&& this->shapes[i][j].getPos_x()<=(GameBoard::coordinate_X2+25) )
								&&  (this->shapes[i][j].getPos_y() >=(GameBoard::coordinate_Y2-40)
										&& this->shapes[i][j].getPos_y()<=(GameBoard::coordinate_Y2+40)  ) )
						{
							id2=this->shapes[i][j].getId();
							ycoord2=i;
							xcoord2=j;
							newcond2=true;
							break;

						}
					}
				}
			}

			if(newcond1==true && newcond2==true)
			{
				if( ( ycoord1==ycoord2   && ( xcoord1==xcoord2+1 || xcoord1==xcoord2-1 ) ) || ( xcoord1==xcoord2   && (ycoord1==ycoord2+1 || ycoord1==ycoord2-1 ) ) )
				{
					shapes[ycoord1][xcoord1].setId(id2);
					shapes[ycoord2][xcoord2].setId(id1);
				}
			}
		}
}

void GameBoard:: play(){

	if(Menu::modes==true)
	{
			this->TimeTrialMode();
	}
	else if(Menu::modes==false)
	{
			this->normalMode();
	}
}

void GameBoard::TimeTrialMode(){
	GameBoard::TimeTrialStatus=true;
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			levelColor/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	if(TotalTime>0)
	{
		this->displayScore();
		this->displayBoundaries();
		this->displayCandies();
		DrawLine(360,800, 780, 800, 15, colors[WHITE]);
		DrawString(850, 800, "LEVEL "+Num2Str(LevelNo), colors[WHITE]);
		this->ProgressBar(TotalTime);
	}
	else {
		this->displayScore();
		DrawString(450, 500, "TIME OVER ", colors[WHITE]);
		DrawString(450, 450, "PLAY AGAIN ", colors[WHITE]);
		DrawString(650, 450, "PRESS R ", colors[WHITE]);
		DrawString(450, 400, "BACK ", colors[WHITE]);
		DrawString(650, 400, "PRESS B ", colors[WHITE]);
		GameBoard::TimeTrialStatus=false;
	}
}
int GameBoard:: moves=5;

void GameBoard::normalMode(){
	glClearColor(0.0/*Red Component*/, levelColor,	//148.0/255/*Green Component*/,
	levelColor/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	if(GameBoard::moves>=0)
	{
			DrawString(800, 700, "MOVES LEFT "+Num2Str(moves), colors[WHITE]);
			this->displayScore();
			this->displayBoundaries();
			this->displayCandies();
			this->displayScorePerCandy();
			this->ProgressBar(BarLength);
			DrawString(850, 800, "LEVEL "+Num2Str(LevelNo), colors[WHITE]);
	}
	else {
		DrawString(450, 500, "GAME OVER ", colors[WHITE]);
		this->displayScore();
		DrawString(850, 800, "LEVEL "+Num2Str(LevelNo), colors[WHITE]);
		DrawString(450, 450, "PLAY AGAIN ", colors[WHITE]);
		DrawString(650, 450, "PRESS R ", colors[WHITE]);
		DrawString(450, 400, "BACK ", colors[WHITE]);
		DrawString(650, 400, "PRESS B ", colors[WHITE]);

	}
}

int GameBoard:: BarLength=0;
double GameBoard::levelColor=0;
void GameBoard::ProgressBar(int barLength){

	DrawLine(360,800, 780, 800, 15, colors[WHITE]);
	DrawLine(360,800, 360+barLength, 800, 15, colors[BLUE]);
		if(360+barLength>=780)
		{
			glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
					1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
			glClear (GL_COLOR_BUFFER_BIT); //Update the colors
			BarLength=0;
			TotalTime=220;
			BarIncrement-=10;
			LevelNo++;
			levelColor=((double)rand()) / ((double)RAND_MAX) * 0.9 + 0.1;
			ScorePerCandy+=1;
			moves+=10;
			gameScore=0;
			glutSwapBuffers();
		}
}
void GameBoard::pauseWindow(){

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(400, 500, "GAME PAUSED ", colors[DARK_BLUE]);
	DrawString(400, 450, "RESUME" , colors[DARK_BLUE]);
	DrawString(650, 450, "PRESS R" , colors[DARK_BLUE]);

}
int GameBoard::BarIncrement=100;

int GameBoard::ScorePerCandy=1;

void GameBoard:: match(int temp_i ,int temp_j,int id ){

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(temp_i==i)
			{
				if (shapes[temp_i][temp_j+1].getId()==id && shapes[temp_i][temp_j+2].getId()==id && shapes[temp_i][temp_j+3].getId()==id && shapes[temp_i][temp_j+4].getId()==id && shapes[temp_i][temp_j+5].getId()==id  && (j+5 <=7) ) {
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					shapes[temp_i][temp_j+2].setId(6);
					shapes[temp_i][temp_j+3].setId(6);
					shapes[temp_i][temp_j+4].setId(6);
					shapes[temp_i][temp_j+5].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if (shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j-2].getId()==id && shapes[temp_i][temp_j-3].getId()==id && shapes[temp_i][temp_j-4].getId()==id && shapes[temp_i][temp_j-5].getId()==id  && (j-5 >=0)) {
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j-2].setId(6);
					shapes[temp_i][temp_j-3].setId(6);
					shapes[temp_i][temp_j-4].setId(6);
					shapes[temp_i][temp_j-5].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if (shapes[temp_i][temp_j+1].getId()==id && shapes[temp_i][temp_j+2].getId()==id && shapes[temp_i][temp_j+3].getId()==id && shapes[temp_i][temp_j+4].getId()==id  && (j+4 <=7)      ) {
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					shapes[temp_i][temp_j+2].setId(6);
					shapes[temp_i][temp_j+3].setId(6);
					shapes[temp_i][temp_j+4].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if (shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j-2].getId()==id && shapes[temp_i][temp_j-3].getId()==id && shapes[temp_i][temp_j-4].getId()==id   && (j-4 >=0)) {
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j-2].setId(6);
					shapes[temp_i][temp_j-3].setId(6);
					shapes[temp_i][temp_j-4].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if (shapes[temp_i][temp_j+1].getId()==id && shapes[temp_i][temp_j+2].getId()==id && shapes[temp_i][temp_j+3].getId()==id   && (j+3 <=7)      ) {
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					shapes[temp_i][temp_j+2].setId(6);
					shapes[temp_i][temp_j+3].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}

				else if (shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j-2].getId()==id && shapes[temp_i][temp_j-3].getId()==id && (j-3 >=0)) {
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j-2].setId(6);
					shapes[temp_i][temp_j-3].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if(shapes[temp_i][temp_j-2].getId()==id && shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j+1].getId()==id && shapes[temp_i][temp_j+2].getId()==id  ){
					shapes[temp_i][temp_j-2].setId(6);
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					shapes[temp_i][temp_j+2].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if(shapes[temp_i][temp_j-3].getId()==id && shapes[temp_i][temp_j-2].getId()==id && shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j+1].getId()==id  ){
					shapes[temp_i][temp_j-3].setId(6);
					shapes[temp_i][temp_j-2].setId(6);
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if(shapes[temp_i][temp_j-3].getId()==id && shapes[temp_i][temp_j-2].getId()==id && shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j+1].getId()==id  ){
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					shapes[temp_i][temp_j+2].setId(6);
					shapes[temp_i][temp_j+3].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if( shapes[temp_i][temp_j-2].getId()==id && shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j+1].getId()==id  && (j+1<=7 || j-2>=0))
				{
					shapes[temp_i][temp_j-2].setId(6);
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if( shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j+1].getId()==id && shapes[temp_i][temp_j+2].getId()==id && (j+2<=7 || j-1>=0))
				{
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					shapes[temp_i][temp_j+2].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if (shapes[temp_i][temp_j+1].getId()==id && shapes[temp_i][temp_j+2].getId()==id ) {
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					shapes[temp_i][temp_j+2].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if (shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j-2].getId()==id  ){
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j-2].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else if(  shapes[temp_i][temp_j-1].getId()==id && shapes[temp_i][temp_j+1].getId()==id)
				{
					shapes[temp_i][temp_j-1].setId(6);
					shapes[temp_i][temp_j].setId(6);
					shapes[temp_i][temp_j+1].setId(6);
					gameScore+=ScorePerCandy;
					TotalTime+=BarIncrement;
					BarLength+=BarIncrement;
				}
				else {
					moves-=1;
					break;
				}
			}
		}
	}
}
int GameBoard:: highScoreArray[4]={0,0,0,0};
vector<int> GameBoard::HighScore;
void GameBoard:: displayHighScore(){
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	levelColor/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	HighScore.push_back(gameScore);
	int temp;
	ofstream outputFile;
	outputFile.open("HighScore.txt");

	for(int i=0;i<HighScore.size();i++)
	{
	outputFile << GameBoard::HighScore[i]<< endl;
	}
	outputFile.close();
	ifstream inputFile;
	int number;
	inputFile.open("HighScore.txt");
	while (inputFile >> number)
	{
		for(int i=0;i<HighScore.size();i++)
		{
			for(int j=i+1;j<HighScore.size();j++)
			{
				if(GameBoard::HighScore[i]<GameBoard::HighScore[j])
				{
					temp  =HighScore[i];
					HighScore[i]=HighScore[j];
					HighScore[j]=temp;
				}
			}
		}
	}

	int x=450,y=500;
	for(int i=0;i<4;i++)
	{
		DrawString(x, y, "HIGH SCORE "+Num2Str(HighScore[i]), colors[WHITE]);
		y-=50;
	}
	inputFile.close();

}


int GameBoard::LevelNo=1;
void GameBoard:: CandiesTransfer(){
	int temp1=0;
	int temp2=0;

	for(int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			if (shapes[i][j].getId()==6)
			{
				for(int k=0;k<i;)
				{
					temp1=shapes[k][j].getId();
					temp2= shapes[k+1][j].getId();
					shapes[k][j].setId(temp2);
					shapes[k+1][j].setId(temp1);
					k++;

				}
			}
		}
	}
}
void GameBoard:: candyRegenerator(){

	for (int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if (shapes[i][j].getId()==6 )
			{
				shapes[i][j].setId(rand()% 5+1);

			}
		}
	}
}

int GameBoard:: xLength=0;
void GameBoard:: GameLoading(){
	glClearColor(0/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
				0.2/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(450, 500, "LOADING", colors[BLUE]);
	DrawString(425, 450, "PLEASE WAIT", colors[DARK_BLUE]);
	DrawLine(450, 400, 450+xLength, 400, 20, colors[BLUE]);
}





int GameBoard:: getXcoordinate(int x){
	return x;
}
int GameBoard:: getYcoordinate(int y){
	return y;
}

GameBoard::~GameBoard() {

	if(shapes!=nullptr )
	{
		delete []shapes;
		cout<<"Destructor"<<endl;
	}

}

int GameBoard::getGameScore() const {
	return gameScore;
}

void GameBoard::setGameScore(int gameScore) {
	this->gameScore = gameScore;
}

int GameBoard::getLives() const {
	return lives;
}

void GameBoard::setLives(int lives) {
	this->lives = lives;
}

int GameBoard::getScorePerCandy() const {
	return ScorePerCandy;
}

void GameBoard::setScorePerCandy(int scorePerCandy) {
	ScorePerCandy = scorePerCandy;
}

int GameBoard::getTargetScore() const {
	return targetScore;
}

void GameBoard::setTargetScore(int targetScore) {
	this->targetScore = targetScore;
}
