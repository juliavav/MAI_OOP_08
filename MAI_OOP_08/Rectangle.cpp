#include "Rectangle.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() : Rectangle(0, 0) {
}

Rectangle::Rectangle(long int i, long int j) : side_a(i), side_b(j) {
}

Rectangle::Rectangle(std::istream &is) {
	std::cout << "Side a=";
	is >> side_a;
	std::cout << "Side b=";
	is >> side_b;
}
Rectangle::Rectangle(const Rectangle& orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
}
double Rectangle::SquareF() {

	return side_a*side_b;

}
Rectangle& Rectangle::operator=(const Rectangle& right) {
	if (this == &right) return *this;
	side_a = right.side_a;
	side_b = right.side_b;
	return *this;
}

bool operator==(const Rectangle& left, const Rectangle& right) {
	return left.side_a == right.side_a&&left.side_b == right.side_b;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
	os << "a=" << obj.side_a << ", b=" << obj.side_b << std::endl;
	return os;
}
std::istream& operator>>(std::istream& is, Rectangle& obj) {

	is >> obj.side_a;
	is >> obj.side_b;
	return is;
}

void  Rectangle::Print()
{
	std::cout << "a=" << side_a << ", b=" << side_b << std::endl;
}

Rectangle::~Rectangle() {
}