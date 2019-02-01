#ifndef POINT2_H
#define POINT2_H

class Point2{
	private: 
		float x,y;
	public:
		Point2 (float x_input, float y_input);
		Point2 ();
		
		//void setPoint2 (float x_input, float y_input);
		
		float DistanceBetween(Point2 pt2_input);
		int Quadrant();
		void Print();
};


#endif
