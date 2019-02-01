#include <iostream>
#include <math.h>
#include "point2.h"

Point2::Point2 (float x_input, float y_input){
		x = x_input;
		y=y_input;
	}
Point2::Point2(){
	x = 0;
	y = 0;
	}
/*
Point2::setPoint2(float x_input, float y_input){
		this->x = x_input;
		this->y = y_input;
	}
*/
float Point2::DistanceBetween (Point2 pt2_input){
	float distanceXY;
	float pt2_x = pt2_input.x;
	float pt2_y = pt2_input.y;
	float x1_minus_x2_square = pow(x - pt2_x , 2.0);
	float y1_minus_y2_square = pow(y - pt2_y , 2.0);
	distanceXY = sqrt(x1_minus_x2_square + y1_minus_y2_square);
	return distanceXY;
	}

int Point2::Quadrant(){
	if (x == 0 && y ==0){
		return 0;
		}
	else if (x > 0 && y >= 0){
		return 1;
		}
	else if (x <= 0 && y> 0){
		return 2;
		}
	else if (x < 0 && y <= 0){
		return 3;
		}
	else if (x >= 0 && y <0){
		return 4;
		}
	else {
		return -1;
		}
	}
	
void Point2::Print(){
	using namespace std;
	cout << "x : " << x << ", y : " << y << ".";
	}
