// If, in Exercise 2, Shape takes no parameters, Rectangle takes two (length and width), but Square takes only one (length), show the constructor initialization for Square.
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
	int length;
};

