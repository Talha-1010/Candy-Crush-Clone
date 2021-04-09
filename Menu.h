/*
 * Menu.h
 *
 *  Created on: May 4, 2020
 *      Author: talha
 */

#ifndef MENU_H_
#define MENU_H_

class Menu {
protected:
	int HighScore;//game High Score

public:
	Menu(){//default constructor
		HighScore=0;
	}
	Menu(int hs){//parameterized constructor
		HighScore=hs;
	}
	static bool modes;// to select different modes i.e time trial mode and normal mode
	void displayMenu();// Display the menu of the game
	int getHighScore();// return high score
	void displaySettings();// Display the game settings
	void displayAbout();// display About window

	void setHighScore(int highScore);// set high score
};


#endif /* MENU_H_ */
