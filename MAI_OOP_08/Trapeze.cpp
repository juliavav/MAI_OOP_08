#include "Trapeze.h"
#include <iostream>
#include <cmath>

Trapeze::Trapeze() : Trapeze(0, 0, 0) {
}

Trapeze::Trapeze(long int i, long int j, long int k) : side_a(i), side_b(j), height(k) {
}

Trapeze::Trapeze(std::istream &is) {
	std::cout << "Side a and side b - two parallel sides." << std::endl;
	std::cout << "Side a=";
	is >> side_a;
	std::cout << "Side b=";
	is >> side_b;
	std::cout << "Height=";
	is >> height;
}


Trapeze::Trapeze(const Trapeze& orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	height = orig.height;
}

double Trapeze::SquareF() {

	return height*(side_a + side_b)*0.5;

}

Trapeze& Trapeze::operator=(const Trapeze& right) {
	if (this == &right) return *this;
	side_a = right.side_a;
	side_b = right.side_b;
	height = right.height;
	return *this;
}

bool operator==(const Trapeze& left, const Trapeze& right) {
	return left.side_a == right.side_a&&left.side_b == right.side_b&&left.height == right.height;
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj) {
	os << "a=" << obj.side_a << ", b=" << obj.side_b << ", height=" << obj.height << std::endl;
	return os;
}

void Trapeze::Print() {
	std::cout << "a=" << side_a << ", b=" << side_b << ", height=" << height << std::endl;

}

std::istream& operator>>(std::istream& is, Trapeze& obj) {

	is >> obj.side_a;
	is >> obj.side_b;
	is >> obj.height;

	return is;
}

Trapeze::~Trapeze() {
}