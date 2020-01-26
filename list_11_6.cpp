 //Listing 11.6 Hiding methods
 #include <iostream>
 using std::cout;

 class Mammal
 {
 public:
 void Move() const { cout << "Mammal move one step.\n"; }
 void Move(int distance) const
 {
 cout << "Mammal move ";
 cout << distance <<" steps.\n";
 }
 protected:
 int itsAge;
 int itsWeight;
 };

 class Dog : public Mammal
 {
 public:
 // You might receive a warning that you are hiding a function!
 void Move() const { cout << "Dog move 5 steps.\n"; }
 };

 int main()
 {
 Mammal bigAnimal;
 Dog Fido;
 bigAnimal.Move();
 bigAnimal.Move(2);
 Fido.Move();
 Fido.Mammal::Move(10);
 return 0;
 }