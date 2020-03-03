//Listing .6 Hiding methods 
#include <iostream>
using std::cout;
class Mammal {
	public:
		void Move() const  { cout << "Mammal move one step.\n"; }
		void Move(int distance) const
		{
			cout << "Mammal move ";
			cout << distance <<" steps.\n";
		} 
	protected:
		int itsAge;
		int itsWeight; };
class Dog : public Mammal
{
	public:
		// You might receive a warning that you are hiding a function!
		void Move() const { cout << "Dog move 5 steps.\n"; }
		// void Move(int steps) const { cout << "Dog moved " << steps << " steps" << std::endl; }
};

int main()
{
	Mammal bigAnimal;
	Dog Fido;
	bigAnimal.Move();
	bigAnimal.Move(2);
	Fido.Mammal::Move();
	//Fido.Move(10);
	return 0;
}
