/*
 * Menu.cpp
 *
 *  Created on: May 4, 2020
 *      Author: talha
 */

#include "Menu.h"
#include"util.h"
#include"CImg.h"
#include"GameBoard.h"
#include"Player.h"
#include<fstream>
using namespace std;
void Menu::setHighScore(int highScore) {
	HighScore = highScore;
}
int Menu:: getHighScore()
{
	return HighScore;
}
// Display the game settings
void Menu:: displaySettings(){
	glClearColor(0.0/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(380, 500, "MODE SETTINGS", colors[BLUE]);
	DrawString(380, 450, "NORMAL MODE", colors[GREEN]);
	DrawString(650, 450, "PRESS N", colors[WHITE]);
	DrawString(380, 400, "TIME TRIAL MODE", colors[GREEN]);
	DrawString(650, 400, "PRESS T", colors[WHITE]);
	DrawString(380, 350, "BACK ", colors[GRAY]);
	DrawString(650, 350, "PRESS B ", colors[WHITE]);

}
// Display the menu of the game
void Menu:: displayMenu(){
	glClearColor(0.0/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		DrawString(380, 500, "CANDY CRUSH", colors[BLUE]);
		DrawString(380, 450, "PLAY", colors[GREEN]);
		DrawString(650, 450, "PRESS R", colors[WHITE]);
		DrawString(380, 400, "MODE SETTINGS", colors[GREEN]);
		DrawString(650, 400, "PRESS S", colors[WHITE]);
		DrawString(380, 350, "HIGH SCORE", colors[GREEN]);
		DrawString(650, 350, "PRESS H", colors[WHITE]);
		DrawString(380, 300, "ABOUT", colors[GREEN]);
		DrawString(650, 300, "PRESS A", colors[WHITE]);
		DrawString(380, 250, "QUIT", colors[GREEN]);
		DrawString(650, 250, "PRESS ESC", colors[WHITE]);
}
void Menu:: displayAbout( ){
	glClearColor(0.0/*Red Component*/, 0.0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(450, 500, "ABOUT GAME", colors[BLUE]);
	DrawString(300, 450, "THIS IS A SIMPLE CANDY CRUSH GAME", colors[GREEN]);
	DrawString(290, 400, "THER ARE TWO DIFFERENT LEVEL MODES", colors[GREEN]);
	DrawString(220, 350, "YOU CAN CHOOSE THEM IN THE MODE SETTINGS OPTION", colors[GREEN]);
	DrawString(150, 300, "YOU HAVE TO SWAP AND MATCH THE CANDIES IN ORDER TO GO TO ", colors[GREEN]);
	DrawString(440, 250, "THE NEXT LEVEL ", colors[GREEN]);
	DrawString(450, 200, "BACK ", colors[GRAY]);
	DrawString(530, 200, "PRESS B ", colors[WHITE]);
}



