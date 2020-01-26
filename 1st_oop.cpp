#include <iostream>
class Car {
	public:        // the next five are public
		void Start();
		void Accelerate();
		void Brake();
		void SetYear(int year);
		int GetYear();
	private:
		int Year;
		char Model[255];
};
void	Car::Start()
{
	std::cout << "Move the whell forward! "<< std::endl;
}
void	Car::SetYear(int year)
{
	Year = year;
}
int Car::GetYear()
{
	return Year;
}
int main()
{
	Car OldFaithful;
	int bought;
	OldFaithful.SetYear(84);
	bought = OldFaithful.GetYear();
	std::cout << bought << std::endl;
	OldFaithful.Start();
	return 0;
}
