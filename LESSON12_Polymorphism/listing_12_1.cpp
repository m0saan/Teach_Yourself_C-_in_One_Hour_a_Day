// Listing 12.1. If horses could fly... // Percolating Fly() up into Horse
#include <iostream>
using namespace std;
class Horse {
	public:
		// Because I'm compiling with the flag Wall -Wextra -Werror
		Horse() = default; // added just to silence the flag
		virtual ~Horse() = default; // This line too
		void Gallop(){ cout << "Galloping...\n"; }
		virtual void Fly() { cout << "Horses can’t fly.\n" ; }
		int getAge() { return itsAge; }
	private:
		int itsAge;
};
class Pegasus : public Horse {
	public: void Fly() { cout<<"I can fly! I can fly! I can fly!\n";}
};
const int NumberHorses = 5;
int main() {
	Horse* Ranch[NumberHorses];
	Horse* pHorse;
	int choice,i;
	for (i=0; i<NumberHorses; i++) {
		cout << "(1)Horse (2)Pegasus: ";
		cin >> choice;
		if (choice == 2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}
	cout << endl;
	for (i=0; i<NumberHorses; i++) {
		Ranch[i]->Fly();
		delete Ranch[i];
	}
	return 0;
}
