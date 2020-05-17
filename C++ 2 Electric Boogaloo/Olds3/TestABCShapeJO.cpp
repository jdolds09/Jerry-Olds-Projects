// Author: Jerry Olds
// Course: COSC 1437
// Program 3.3
#include<iostream>
using namespace std;

// Basic Shape Class
class BasicShape
{
protected:
	double area;
public:
	double getArea()
	{return area;}
	virtual void calcArea() = 0;
};
// Circle Class
class Circle : public BasicShape
{
private:
	long centerx;
	long centery;
	double radius;
public:
	Circle(long x, long y, double r)
	{
		centerx = x;
		centery = y;
		radius = r;
		calcArea();
	}
	long getCenterX()
	{
		return centerx;
	}
	long getCenterY()
	{
		return centery;
	}
	void calcArea()
	{
		area = 3.14159 * radius * radius;
	}
};
// Rectangle Class
class Rectangle : public BasicShape
{
private:
	long length;
	long width;
public:
	Rectangle(long l, long w)
	{
		length = l;
		width = w;
		calcArea();
	}
	long getlength()
	{
		return length;
	}
	long getwidth()
	{
		return width;
	}
	void calcArea()
	{
		area = length * width;
	}
};

int main()
{
// Variables
	long x;
	long y;
	double radius;
	long length;
	long width;
// Title
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t   Abstract Base Class Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// User Prompt for Circle
	cout << "Please enter the x coordinate of the circle's center: ";
	cin >> x;
// Input Validation
	while (x < 0)
	{
		cout << "Invalid Input." << endl;
		cout << "Please enter the x coordinate of the circle's center: ";
		cin >> x;
	}
	cout << "Please enter the y coordinate of the circle's center: ";
	cin >> y;
// Input Validation
	while (y < 0)
	{
		cout << "Invalid Input." << endl;
		cout << "Please enter the y coordinate of the circle's center: ";
		cin >> y;
	}
	cout << "Please enter the radius of the circle: ";
	cin >> radius;
// Input Validation
	while (radius < 0)
	{
		cout << "Invalid Input." << endl;
		cout << "Please enter the radius of the circle: ";
		cin >> radius;
	}
// Send Input to Circle Class
	Circle shape1(x, y, radius);
// Display Results
	cout << "The area of the circle is " << shape1.getArea() << endl;
// User Prompt for Rectangle
	cout << "\nPlease enter the length of the rectangle: ";
	cin >> length;
// Input Validation
	while (length < 0)
	{
		cout << "Invalid Input." << endl;
		cout << "Please enter the length of the rectangle: ";
		cin >> length;
	}
	cout << "Please enter the width of the rectangle: ";
	cin >> width;
// Input Validation
	while (width < 0)
	{
		cout << "Invalid Input." << endl;
		cout << "Please enter the width of the rectangle: ";
		cin >> width;
	}
// Send Input to Rectangle Class
	Rectangle shape2(length, width);
// Display Results
	cout << "The area of the Rectangle is " << shape2.getArea() << endl;
	cout << endl;
// End of Program
	return 0;
}