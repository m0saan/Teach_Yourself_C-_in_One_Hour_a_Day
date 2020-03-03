//Listing 11.13 Version of class Fan that aggregates ElectricMotor
#include <iostream>
class Fan
{
public:
    Fan(){};
    ~Fan() {}
    void StartFan()
    {
        m_ElectricMotor.StartMotor();
    }
    void StopFan()
    {
        m_ElectricMotor.StopMotor();
    }

private:
    ElectricMotor m_ElectricMotor;
};