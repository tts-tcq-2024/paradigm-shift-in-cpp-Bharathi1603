#include <assert.h>
#include <iostream>
using namespace std;

void printMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

bool isBatteryTemperatureOk(float temperature)
{
    if(temperature < 0 || temperature > 45)
    {
        printMessage("Temperature out of range!");
        return false; 
    }    
    return true;
}

bool isBatteryChargeStateOk(float soc)
{
    if(soc < 20 || soc > 80) 
    {
        printMessage("State of Charge out of range!");
        return false;
    }    
    return true;
}

bool isBatteryChargeRateOk(float chargeRate)
{
    if(chargeRate > 0.8) 
    {
        printMessage("Charge Rate out of range!");
        return false;
  }
    
    return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate)
{
    return ((isBatteryTemperatureOk(temperature)) && (isBatteryChargeStateOk(soc)) && (isBatteryChargeRateOk(chargeRate)));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
