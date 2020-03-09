// ex3
#include <iostream>

class Vehicle {
	public:
		virtual void move() = 0;
		virtual void stop() = 0;
};

class Bus : public Vehicle {
	public:
		virtual void move() { std::cout << "Bus is moving!"<< std::endl; } 
		virtual void stop() { std::cout << "Bus is stoping!"<< std::endl; } 
};

class Car : public Vehicle {
	public:
		virtual void move() { std::cout << "Car is moving!"<< std::endl; } 
		virtual void stop() { std::cout << "Car is stoping!"<< std::endl; } 
};
