#ifndef TRAPEZE_H
#define	TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include"Figure.h"

class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(const Trapeze& orig);
	double SquareF();
	Trapeze(long int i, long int j, long int k);

	friend bool operator==(const Trapeze& left, const Trapeze& right);

	friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
	friend std::istream& operator>>(std::istream& is, Trapeze& obj);

	Trapeze& operator=(const Trapeze & right);
	void Print() override;
	virtual ~Trapeze();
private:
	long int side_a;
	long int side_b;
	long int height;
};

#endif	/* TRAPEZE_H */