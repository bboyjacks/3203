#include "Vehicle.h"
#include "Showroom.h"
#include "Dealership.h"
#include <iostream>

using namespace std;

int main()
{
  {
    // Initialize some data. It's hard-coded here, but this data could come from a file, database, etc
    Vehicle vehicles[] =
    {
      Vehicle("Ford", "Mustang", 1973, 9500, 113000),
      Vehicle("Mazda", "CX-5", 2017, 24150, 5900),
      Vehicle("Dodge", "Charger", 2016, 18955, 9018),
      Vehicle("Telsa", "Model S", 2018, 74500, 31),
      Vehicle("Toyota", "Prius", 2015, 17819, 22987),
      Vehicle("Nissan", "Leaf", 2016, 12999, 16889),
      Vehicle("Chevrolet", "Volt", 2015, 16994, 12558),
    };

    // Showrooms to store the vehicles
    Showroom showroom("Primary Showroom", 3);
    showroom.AddVehicle(&vehicles[0]);
    showroom.AddVehicle(&vehicles[1]);

    Showroom secondary("Fuel-Efficient Showroom", 4);
    secondary.AddVehicle(&vehicles[3]);
    secondary.AddVehicle(&vehicles[4]);
    secondary.AddVehicle(&vehicles[5]);
    secondary.AddVehicle(&vehicles[6]);

    // A "parent" object to store the Showrooms
    Dealership dealerShip("COP3503 Vehicle Emporium", 2);
    dealerShip.AddShowroom(&showroom);
    dealerShip.AddShowroom(&secondary);

    dealerShip.ShowInventory();

    cout << endl << "Calling destructors..." << endl;
  }

  std::getchar();
  return 0;
}