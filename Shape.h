/*
 * Candy.h
 *
 *  Created on: May 4, 2020
 *      Author: talha
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include<string>
#include"util.h"
using namespace std;
class Shape{
protected:
	float *color;//color of shape
	int x_pos;//position x
	int y_pos;//position y
	int id;//id of shape
public:

	Shape();
	Shape(int ,int,int ,float*);
	int getPos_x();
	void setPos_x(int pos);
	int getPos_y();
	void setPos_y(int p);
	float* getShapeColor();
	void setShapeColor(float *color);
	int getId() const;
	void setId(int id);
};
#endif /* SHAPE_H_ */
