#ifndef SQUARE_H
#define	SQUARE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Square : public Figure {
public:
	Square();
	Square(std::istream &is);
	Square(const Square& orig);
	Square(long int i);
	double SquareF();

	friend bool operator==(const Square& left, const Square& right);

	friend std::ostream& operator<<(std::ostream& os, const Square& obj);
	friend std::istream& operator>>(std::istream& is, Square& obj);

	Square& operator=(const Square & right);

	void Print() override;
	virtual ~Square();
private:
	long int side_a;
};

#endif	/* SQUARE_H */