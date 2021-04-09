/*
 * Player.h
 *
 *  Created on: May 4, 2020
 *      Author: talha
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include<string>
#include<iostream>
using namespace std;
class Player {
private:
	string name;
	int highestLevel;//highest level of
public:

	Player();
	const string& getName() const;
	void setName(const string &name);
	int getHighestLevel() const;
	void setHighestLevel(int highestLevel);
};

#endif /* PLAYER_H_ */
