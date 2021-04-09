/*
 * Candy.cpp
 *
 *  Created on: May 4, 2020
 *      Author: talha
 */

#include "Shape.h"
int Shape::getPos_x(){
	return x_pos;
}

void Shape::setPos_x(int pos) {
	x_pos = pos;
}

int Shape::getPos_y() {
	return y_pos;
}

void Shape::setPos_y(int pos) {
	y_pos = pos;
}
float* Shape::getShapeColor() {
	return color;
}

void Shape::setShapeColor(float *color){
	this->color = color;
}
Shape::Shape() {

	x_pos=0;
	y_pos=0;
	color=nullptr;
	id=0;
}
Shape::Shape (int x,int y,int i,float*c){

	x_pos=x;
	y_pos=y;
	color=c;
	id=i;

}

int Shape::getId() const {
	return id;
}

void Shape::setId(int id) {
	this->id = id;
}
