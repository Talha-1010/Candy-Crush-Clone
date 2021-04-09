//============================================================================
// Name        : .cpp
// Author      : Talha
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> 	// for basic math functions such as cos, sin, sqrt
#include"Player.h"
#include"Menu.h"
#include "Shape.h"
#include"GameBoard.h"
#include<vector>
#include<algorithm>
#include<iterator>
#include"CImg.h"
#include <fstream>
using namespace std;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/*
 * 	Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 */
GameBoard obj(0, 0, 0, 0, 0, 8);
int GameBoard::loadingTime=10;
void SetCanvasSize(int width, int height)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function
 */

void drawpoint(int x, int y) {
	y=840-y;
	cout<<"x : "<<x<<" y : "<<y<<endl;
	DrawCircle(x, y,3 , colors[BLUE]);
	glEnd();
	glutSwapBuffers();
}
bool GameBoard:: loadingStatus=true;


void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	Menu menu;

	if(GameBoard::loadingStatus ==false)
	{

		if(GameBoard::decision==1)
		{
			menu.displayMenu();
		}
		else if(GameBoard::decision==2)
		{
			menu.displaySettings();
		}
		else if(GameBoard::decision==3)
		{
				obj.play();
		}
		else if(GameBoard::decision==4)
		{
			obj.pauseWindow();
		}
		else if(GameBoard::decision==5)
		{
			obj.displayAbout();
		}
		else if(GameBoard::decision==6)
		{
			obj.displayHighScore();
		}

	}
	glutSwapBuffers(); // do not modify this line..
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {

	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
		// what to do when left key is pressed...

	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{


	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{

	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variables:
  1.key contains the ASCII of the key pressed
  2.while x and y tells the program coordinates of mouse pointer when key was pressed.
 * */

bool GameBoard::TimeTrialStatus=false;
int GameBoard::decision=1;
bool Menu::modes=false;
void PrintableKeys(unsigned char key, int x, int y) {




	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	else if(key=='m' || key=='M' || key=='b'|| key=='B')//to access menu
	{
		GameBoard::decision=1;
	}
	else if(key=='S' || key=='s')//to open settings
	{
		GameBoard::decision=2;
	}
	else if(key=='r' || key=='R')//to play
	{
		GameBoard::decision=3;
		GameBoard::moves=5;
		GameBoard::TotalTime=220;
	}
	else if(key=='p' || key=='P')//to pause
	{
		cout<<"true"<<endl;
		GameBoard::decision=4;
	}
	else if(key=='A' || key=='a')
	{
		GameBoard::decision=5;
	}
	else if(key=='H' || key=='h')
	{
		GameBoard::decision=6;
	}
	if(key=='n'|| key=='N')
	{
		Menu::modes=false;
	}
	else if(key=='t'|| key=='T')
	{
		Menu::modes=true;
	}


	glutPostRedisplay();
}

/*
 *
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 */

int GameBoard::TotalTime=220;

void Timer(int m) {


	GameBoard::xLength+=10;

	glutPostRedisplay();
	if(GameBoard::loadingTime>=0)
	{
		obj.GameLoading();
	}
	else
	{
		GameBoard::loadingStatus=false;
	}
	if(GameBoard::TimeTrialStatus==true)
	{
		GameBoard::TotalTime--;
	}
	GameBoard::loadingTime--;
	obj.CandiesTransfer();
	obj.candyRegenerator();
	// implement your functionality here
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutSwapBuffers();
	glutTimerFunc(100.0, Timer, m+1);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {

	drawpoint(x,y);
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

int GameBoard::coordinate_X1=0;
int GameBoard::coordinate_Y1=0;
int GameBoard::coordinate_X2=0;
int GameBoard::coordinate_Y2=0;
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		y=840-y;
		if(state == GLUT_DOWN )
		{
			GameBoard::coordinate_X1=x;
			GameBoard::coordinate_Y1=y;
		}
		else if (state==GLUT_UP) {
			GameBoard::coordinate_X2=x;
			cout<<"release x1 "<<GameBoard::coordinate_X2;
			GameBoard::coordinate_Y2=y;
			cout<<"release y2 "<<GameBoard::coordinate_Y2<<endl;
			obj.swapShape();
			obj.match(GameBoard::ycoord2 ,GameBoard::xcoord2 ,GameBoard::id1);
		}

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
	glutPostRedisplay();
}
/*
 * our gateway to main function
 * */
int main(int argc, char*argv[]) {


	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	//glutCreateMenu(Menu2);

	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...

	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
