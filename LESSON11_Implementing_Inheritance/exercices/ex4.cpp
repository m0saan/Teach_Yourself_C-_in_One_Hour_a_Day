//Write a virtual copy constructor for the class Square (in Exercise 3).
class Shape
{
};
class Rectangle : public Shape
{
	int length;
	int width;
};
class Square : public Rectangle
{
	Square();
	virtual Square *Clone() { return new Square(*this); }
	int length;
};
