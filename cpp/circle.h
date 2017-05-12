#include<cmath>
#include<ostream>
class circle {
	/*
	 * A class to represent a circle.
	 */
	public:
		static constexpr double pi = 3.14;
		circle(double r = 0) : rad(r),
				diam(r*2),
				circumf(circle::pi * diam),
				area(circle::pi * pow(r,2.0)) {}
		~circle() {}
		circle& operator=(const circle& other);
		double diameter() const { return diam; }
		double radius() const { return rad; }
		double circum() const { return circumf; }
		double areaof() const { return area; }
	private:
		double rad;
		double diam;
		double circumf;
		double area;
};
circle& circle::operator=(const circle& other) {
	rad = other.rad;
	diam = other.diam;
	circumf = other.circumf;
	area = other.area;
	return *this;
}
std::ostream& operator<<(std::ostream& os, circle& c) {
	os << "R = " << c.radius();
}
