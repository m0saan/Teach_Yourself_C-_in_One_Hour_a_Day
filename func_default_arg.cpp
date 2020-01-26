#include <iostream>

enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal {
public:
	// Constructors
	Mammal();
	Mammal(int age);
	~Mammal();

	// Accessors
	void	setAge(int age) {itsAge = age; }
	int		getAge() const { return itsAge; }
	void	setWeight(int weight) {itsWeight = weight; }
	int		getWeight() const { return itsWeight;}

	//Other methods
	void Speak() const { std::cout << "Mammal sound!\n"; }
	void Sleep() const { std::cout << "shhh. I’m sleeping.\n"; }
protected:
	int itsAge;
	int itsWeight;
};

class Dog : public Mammal {
public:
	// Constructors
	Dog();
	Dog(int age);
	Dog(int age, int weight);
	Dog(int age, BREED breed);
	Dog(int age, int weight, BREED breed);
	~Dog();

	// Accessors
	void	setBreed(BREED breed) { itsBreed = breed; }
	int		getBreed() const { return  itsBreed; }
	// Other methods
	void WagTail() const { std::cout << "Tail wagging...\n"; }
	void BegForFood() const { std::cout << "Begging for food...\n"; }

protected:
	BREED itsBreed;
};

// Mammal Constructors;
Mammal::Mammal():
itsAge(1),
itsWeight(5)
{
	std::cout << "Mammal constructor "<< std::endl;
}

Mammal::Mammal(int age):
itsAge(age),
itsWeight(5)
{
	std::cout << " Mammal(int age) constructor" << std::endl;
	itsAge = age;
}
Mammal::~Mammal() {
	std::cout << "Mammal destructor" << std::endl;
}

// Dog Constructors
Dog::Dog() : Mammal() {
	std::cout << "Dog constructors" << std::endl;
}

Dog::Dog(int age): Mammal(age),
itsBreed(GOLDEN)
{
	std::cout << " Dog (int age) constructor "<< std::endl;
}

Dog::Dog(int age, int weight): Mammal(age), itsBreed(GOLDEN)
{
	itsWeight = weight;
	std::cout << "Dog(int age int weight) constructor "<< std::endl;
}

Dog::Dog(int age, BREED breed): Mammal(age),
itsBreed(breed)
{
	std::cout << "Dog(int age, BREED breed) constructor "<< std::endl;
}

Dog::Dog(int age, int weight, BREED breed): Mammal(age), itsBreed(breed)
{
	itsWeight = weight;
	std::cout << "Dog(int age, int weight, BREED breed) constructor" << std::endl;
}
Dog::~Dog() {
	std::cout << "Dog destructor "<< std::endl;
}
int main(int argc , char const* argv [])
{
	using namespace std;
	Dog Fido;
	Dog rover(5);
	Dog buster(6,8);
	Dog yorkie (3,GOLDEN);
	Dog dobbie (4,20,DOBERMAN);
	Fido.Speak();
	rover.WagTail();
	cout << "Yorkie is " << yorkie.getAge() << " years old" << endl;
	cout << "Dobbie weighs ";
	cout << dobbie.getWeight() << " pounds" << endl;
	return 0;
}

/*
 1: Mammal constructor...
2: Dog constructor...
3: Mammal(int) constructor...
4: Dog(int) constructor...
5: Mammal(int) constructor...
6: Dog(int, int) constructor...
7: Mammal(int) constructor...
8: Dog(int, BREED) constructor....
9: Mammal(int) constructor...
10: Dog(int, int, BREED) constructor...
11: Mammal sound!
12: Tail wagging...
13: Yorkie is 3 years old.
14: Dobbie weighs 20 pounds.
15: Dog destructor. . .
16: Mammal destructor...
17: Dog destructor...
18: Mammal destructor...
19: Dog destructor...
20: Mammal destructor...
21: Dog destructor...
22: Mammal destructor...
23: Dog destructor...
24: Mammal destructor...
 */
