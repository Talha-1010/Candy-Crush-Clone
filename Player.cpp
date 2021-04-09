/*
 * Player.cpp
 *
 *  Created on: May 4, 2020
 *      Author: talha
 */

#include "Player.h"

const string& Player::getName() const {
	return name;
}

int Player::getHighestLevel() const {
	return highestLevel;
}

void Player::setHighestLevel(int highestLevel) {
	this->highestLevel = highestLevel;
}

void Player::setName(const string &name) {
	this->name = name;
}

Player::Player() {
	// TODO Auto-generated constructor stub
	name="";
	highestLevel=0;

}

