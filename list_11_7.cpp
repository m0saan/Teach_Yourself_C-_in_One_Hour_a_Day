//Listing 11.7 Calling a base method from a overridden method.
#include <iostream>

using namespace std;

class Mammal {
public:
    void Move() const { cout << "Mammal move one step\n"; }
    void Move(int distance) const
    {
        cout << "Mammal move " << distance;
        cout << " steps." << endl;
    }

protected:
    int itsAge;
    int itsWeight;
};

class Dog : public Mammal {
public:
    void Move() const {
        cout << "In dog move...\n";
        Mammal::Move(3);
    }
};

int main() {
    Mammal bigAnimal;
    Dog Fido;
    bigAnimal.Move(2);
    Fido.Mammal::Move(6);
    return 0;
}