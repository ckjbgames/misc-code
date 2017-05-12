#include<iostream>
#include "circle.h"
int main() {
	circle c;
	double d = 0.0;
	for(;;) {
		std::cout << "Enter the radius of the circle: ";
		std::cin >> d;
		if(d != 0.0) break;
		else std::cout << "It seems you didn't enter a number.\n" <<
			"Could you try again?\n";
	}
	c = circle(d);
	std::cout << c << '\n';
	std::cout << "Area: " << c.areaof() << '\n';
	std::cout << "Circumference: " << c.circum() << '\n';
	std::cout << "Bye!\n";
	return 0;
}
