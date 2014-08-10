#include <stdio.h>

inline double max(double &x, double &y) {
	return x>y?x:y;
}

inline double min(double &x, double &y) {
	return x<y?x:y;
}

class Vector2D {
public:
	static double dot_product (Vector2D v1, Vector2D v2) {
		return v1.x*v2.x + v1.y*v2.y;
	}	

	static double cross_product (Vector2D v1, Vector2D v2) {
		return v1.x*v2.y - v1.y*v2.x;	
	}
	
	static bool isClockwise(Vector2D v1, Vector2D v2, Vector2D v3) {
		return cross_product(v2-v1, v3-v2) > 0;
	}

	static bool isOnSegment(Vector2D v1, Vector2D v2, Vector2D v3) {
		if (min(v1.x,v2.x)<=v3.x && v3.x<=max(v1.x,v2.x) &&
			min(v1.y,v2.y)<=v3.y && v3.y<=max(v1.y,v2.y) &&
			cross_product(v2-v1, v3-v2)==0) {
			return true;
		} else {
			return false;
		}	
	}

	static bool isIntersect(Vector2D v1, Vector2D v2, Vector2D v3, Vector2D v4) {
		if ((min(v1.x,v2.x)<=v3.x && v3.x<=max(v1.x,v2.x) && 
			 min(v1.y,v2.y)<=v3.y && v3.y<=max(v1.y,v2.y))
			 ||
			(min(v1.x,v2.x)<=v4.x && v4.x<=max(v1.x,v2.x) &&
		 	 min(v1.y,v2.y)<=v4.y && v4.y<=max(v1.y,v2.y))) {
			if (cross_product(v3-v1, v2-v1) *
				cross_product(v2-v1, v4-v1) >= 0) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}


public:
	Vector2D (double x, double y) :
		x(x), y(y) {
	}
	// operator
	Vector2D& operator+(const Vector2D& v) {
		this->x += v.x;	
	}
	Vector2D& operator-(const Vector2D& v) {
		this->y += v.y;
	}

private:
	double x;
	double y;
};



class Vector3D {
public:
	Vector3D (double x, double y, double z):
		x(x),y(y),z(z) {
	}

private:
	double x;
	double y;
	double z;	
};


int main() {

	return 0;
}
