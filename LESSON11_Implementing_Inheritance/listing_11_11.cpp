//Listing 11.11 Virtual copy constructor
#include <iostream>
using namespace std;

class Mammal
{
	public:
		Mammal() : itsAge(1) { cout << "Mammal constructor...\n"; }
		virtual ~Mammal() { cout << "Mammal destructor...\n"; }
		Mammal(const Mammal &rhs) : itsAge(rhs.GetAge())
	{
		cout << "Mammal Copy Constructor...\n";
	}
		virtual void Speak() const { cout << "Mammal speak!\n"; }
		virtual Mammal *Clone() { return new Mammal(*this); }
		int GetAge() const { return itsAge; }

	protected:
		int itsAge;
};

class Dog : public Mammal
{
	public:
		Dog() { cout << "Dog constructor...\n"; }
		virtual ~Dog() { cout << "Dog destructor...\n"; }
		Dog(const Dog &rhs);
		void Speak() const { cout << "Woof!\n"; }
		virtual Mammal *Clone() { return new Dog(*this); }
};

Dog::Dog(const Dog &rhs) : Mammal(rhs)
{
	cout << "Dog copy constructor...\n";
}

class Cat : public Mammal
{
	public:
		Cat() { cout << "Cat constructor...\n"; }
		~Cat() { cout << "Cat destructor...\n"; }
		Cat(const Cat &);
		void Speak() const { cout << "Meow!\n"; }
		virtual Mammal *Clone() { return new Cat(*this); }
};

Cat::Cat(const Cat &rhs) : Mammal(rhs)
{
	cout << "Cat copy constructor...\n";
}

enum ANIMALS
{
	MAMMAL,
	DOG,
	CAT
};
const int NumAnimalTypes = 3;
int main()
{
	Mammal *theArray[NumAnimalTypes];
	Mammal *ptr;
	int choice, i;
	for (i = 0; i < NumAnimalTypes; i++)
	{
		cout << "(1)dog (2)cat (3)Mammal: ";
		cin >> choice;
		switch (choice)
		{
			case DOG:
				ptr = new Dog;
				break;
			case CAT:
				ptr = new Cat;
				break;
			default:
				ptr = new Mammal;
				break;
		}
		theArray[i] = ptr;
	}
	Mammal *OtherArray[NumAnimalTypes];
	for (i = 0; i < NumAnimalTypes; i++)
	{
		theArray[i]->Speak();
		OtherArray[i] = theArray[i]->Clone();
	}
	for (i = 0; i < NumAnimalTypes; i++)
		OtherArray[i]->Speak();
	return 0;
}
