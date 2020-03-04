//Listing 11.12 Demonstration of Private Inheritance
#include <iostream>
using namespace std;
class ElectricMotor
{
public:
    ElectricMotor(){};
    virtual ~ElectricMotor(){};

public:
    void StartMotor()
    {
        Accelerate();
        Cruise();
    }
    void StopMotor()
    {
        cout << "Motor Speed" << endl;
    }

private:
    void Accelerate()
    {
        cout << "Motor started" << endl;
    }
    void Cruise()
    {
        cout << "Motor running at constant speed" << endl;
    }
};

class Fan : public ElectricMotor
{
public:
    Fan(){};
    ~Fan() {}
    void StartFan()
    {
        StartMotor();
    }
    void StopFan()
    {
        StopMotor();
    }
};
int main()
{
    Fan mFan;
    mFan.StartFan();
    mFan.StopFan();
    /*
Note: the next two lines access the base class ElectricMotor
However, as Fan features ‘private inheritance’ from ElectricMotor,
neither the base class instance nor its public methods are
accessible to the users of class Fan.
Un-comment them to see a compile failure! */
    //mFan.Accelerate ();
    // ElectricMotor * pMotor = &mFan;
    return 0;
};
