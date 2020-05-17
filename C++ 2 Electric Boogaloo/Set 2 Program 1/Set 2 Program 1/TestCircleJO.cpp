// Author: Jerry Olds
// Course: COSC 1437
// Program 2.1
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

// Circle Class
class Circle
{
private:
		double radius;
		const double PI = 3.14159;
public:
	Circle()
		{radius = 0.0;}
	Circle(double r)
		{radius = r;}
	void setRadius(double r)
		{radius = r;}
	double getRadius() const
		{return radius;}
	double getArea() const;
	double getDiameter() const;
	double getCircumference() const;
};
// Get Area Function
double Circle::getArea() const
{
	return PI * pow(radius, 2);
}
// Get Diameter Function
double Circle::getDiameter() const
{
	return radius * 2;
}
// Get Circumference Function
double Circle::getCircumference() const
{
	return radius * 2 * PI;
}

int main()
{
// Variables
	Circle sphere;
	double circleRadius;
// Output
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\tCircle Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Please enter the Radius of the circle: ";
	cin >> circleRadius;
	while (circleRadius < 0)
	{
		cout << "Invalid Input." << endl;
		cout << "Please enter the Radius of the circle: ";
		cin >> circleRadius;
	}
// Send Input to Class
	sphere.setRadius(circleRadius);
// Display Results
	cout << "\nHere is the circle's data: " << endl;
	cout << "Area: " << setw(16) << sphere.getArea() << endl;
	cout << "Diameter: " << setw(7) << sphere.getDiameter() << endl;
	cout << "Circumference: " << sphere.getCircumference() << endl << endl;
	return 0;
}