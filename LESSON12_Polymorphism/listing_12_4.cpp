// Listing .
// Calling multiple constructors
#include <iostream>
using namespace std;

typedef int HANDS;
enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown } ;

class Horse {
	public:
		Horse(COLOR color, HANDS height);
		virtual ~Horse() { cout << "Horse destructor...\n"; }
		virtual void Whinny()const { cout << "Whinny!... "; }
		virtual HANDS GetHeight() const { return itsHeight; }
		virtual COLOR GetColor() const { return itsColor; }
	private:
		HANDS itsHeight;
		COLOR itsColor; 
};
Horse::Horse(COLOR color, HANDS height): itsColor(color),itsHeight(height)
{
	cout << "Horse constructor...\n"; 
}
class Bird {
	public:
		Bird(COLOR color, bool migrates);
		virtual ~Bird() {cout << "Bird destructor...\n"; }
		virtual void Chirp()const { cout << "Chirp... "; }
		virtual void Fly() const { cout << "I can fly! I can fly! I can fly! "; }
		virtual COLOR GetColor()const { return itsColor; }
		virtual bool GetMigration() const { return itsMigration; }
	private:
		COLOR itsColor;
		bool itsMigration;
};
Bird::Bird(COLOR color, bool migrates): itsColor(color), itsMigration(migrates) 
{
	cout << "Bird constructor...\n"; 
}
class Pegasus : public Horse, public Bird {
	public:
		void Chirp()const { Whinny(); }
		Pegasus(COLOR, HANDS, bool,long);
		~Pegasus() {cout << "Pegasus destructor...\n";}
		virtual long GetNumberBelievers() const { return itsNumberBelievers; }
	private:
		long itsNumberBelievers;
};
Pegasus::Pegasus( COLOR aColor, HANDS height, bool migrates, long NumBelieve):
	Horse(aColor, height),
	Bird(aColor, migrates),
	itsNumberBelievers(NumBelieve)
{
	cout << "Pegasus constructor..." << endl;
}

int main()
{
	Pegasus *pPeg = new Pegasus(Red, 5, true, 10);
	pPeg->Fly();
	pPeg->Whinny();
	cout << "\nYour Pegasus is " << pPeg->GetHeight();
	cout << " hands tall and";
	if (pPeg->GetMigration())
		cout << "it does migrate.";
	else
		cout << "it does not migrate.";
	cout << "\nA total of " << pPeg->GetNumberBelievers();
	cout << " people believe it exists." << endl;
	delete pPeg;
	return 0;
}

