#include <iostream>
using namespace std;
enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };
class Mammal {
	public:
		// constructors 
		Mammal();
		Mammal(int age);
		~Mammal();

		//accessors
		int GetAge() const { return itsAge; }
		void SetAge(int age) { itsAge = age; }
		int GetWeight() const { return itsWeight; }
		void SetWeight(int weight) { itsWeight = weight; }

		//Other methods
		void Speak() const { cout << "Mammal sound!\n"; }
		void Sleep() const { cout << "shhh. I’m sleeping.\n"; }

	protected:
		int itsAge;
		int itsWeight;
};

class Dog : public Mammal
{
	public:

		// Constructors
		Dog();
		Dog(int age);
		Dog(int age, int weight);
		Dog(int age, BREED breed);
		Dog(int age, int weight, BREED breed);
		~Dog();

		// Accessors
		BREED GetBreed() const { return itsBreed; }
		void SetBreed(BREED breed) { itsBreed = breed; }

		// Other methods
		void WagTail() const { cout << "Tail wagging...\n"; }
		void BegForFood() const { cout << "Begging for food...\n"; }

	private:
		BREED itsBreed;
};

Mammal::Mammal():
	itsAge(1),
	itsWeight(5)
{
	cout << "Mammal constructor..." << endl;
}

Mammal::Mammal(int age):
	itsAge(age),

	itsWeight()
{
	cout << "Mammal(int) constructor..." << endl;
}

Mammal::~Mammal()
{
	cout << "Mammal destructor..." << endl;
}

Dog::Dog():
	Mammal(),
	itsBreed(GOLDEN)
{
	cout << "Dog constructor..." << endl;
}

Dog::Dog(int age) :
	Mammal(age),
	itsBreed(GOLDEN)
{
	cout << "Dog(int) constructor..." << endl;
}

Dog::Dog(int age, int weight) :
	Mammal(age),
	itsBreed(GOLDEN)
{
	itsWeight = weight;
	cout << "Dog(int, int) constructor..." << endl;
}

Dog::Dog(int age, int weight, BREED breed) :
	Mammal(age),
	itsBreed(breed)
{
	itsWeight = weight;
	cout << "Dog(int, int, BREED) constructor..." << endl;
}

Dog::Dog(int age, BREED breed) :
	Mammal(age),
	itsBreed(breed)
{
	cout << "Dog(int, BREED) constructor..." << endl;
}

Dog::~Dog()
{
	cout << "Dog destructor " << endl;
}

int main()
{
	Dog Fido;
	Dog rover(5);
	Dog buster(6,8);
	Dog yorkie (3,GOLDEN);
	Dog dobbie (4,20,DOBERMAN); Fido.Speak();
	rover.WagTail();
	cout << "Yorkie is " << yorkie.GetAge()
		<< " years old" << endl;
	cout << "Dobbie weighs ";
	cout << dobbie.GetWeight() << " pound" << endl;
	return 0;
}
