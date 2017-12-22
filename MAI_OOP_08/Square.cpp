#include "Square.h"
#include <iostream>
#include <cmath>

Square::Square() : Square(0) {
}

Square::Square(std::istream &is) {
	std::cout << "Side =";
	is >> side_a;
}
Square::Square(long int i) : side_a(i) {
}

double Square::SquareF() {

	return side_a*side_a;
}

Square::Square(const Square& orig) {
	side_a = orig.side_a;
}

Square& Square::operator=(const Square& right) {

	if (this == &right) return *this;
	
	side_a = right.side_a;

	return *this;
}

bool operator==(const Square & left, const Square & right) {
	return left.side_a == right.side_a;
}

void Square::Print() {
	std::cout << "a=" << side_a << std::endl;

}
Square::~Square() {
	//std::cout << "Square deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Square& obj) {

	os << "a=" << obj.side_a;
	return os;
}

std::istream& operator>>(std::istream& is, Square& obj) {

	is >> obj.side_a;

	return is;
}