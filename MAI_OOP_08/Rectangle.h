#ifndef RECTANGLE_H
#define	RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(const Rectangle& orig);
	double SquareF();
	Rectangle(std::istream &is);
	Rectangle(long int i, long int j);

	friend bool operator==(const Rectangle& left, const Rectangle&right);

	friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
	friend std::istream& operator>>(std::istream& is, Rectangle& obj);

	Rectangle& operator=(const Rectangle & right);

	void Print() override;
	virtual ~Rectangle();
private:
	long int side_a;
	long int side_b;
};

#endif	/* RECTANGLE_H */