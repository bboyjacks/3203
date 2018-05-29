#include "Dealership.h"
#include <iostream>


Dealership::Dealership(std::string _dealer_name, const int _num_showroom):
  m_dealer_name(std::move(_dealer_name)),
  m_num_showroom(_num_showroom)
{
}

Dealership::Dealership(const Dealership& _other)
{
  m_dealer_name = _other.m_dealer_name;
  m_num_showroom = _other.m_num_showroom;
}

Dealership::Dealership(Dealership&& _other) noexcept
{
  m_dealer_name = std::move(_other.m_dealer_name);
  m_num_showroom = _other.m_num_showroom;
}

Dealership& Dealership::operator=(const Dealership& _other)
{
  if (this == &_other)
    return *this;
  return *this;
}

Dealership& Dealership::operator=(Dealership&& _other) noexcept
{
  if (this == &_other)
    return *this;
  return *this;
}

void Dealership::AddShowroom(const Showroom* _showroom)
{
  m_showrooms.push_back(_showroom);
}

void Dealership::ShowInventory() const
{
  std::cout << "Inventory of COP3503 Vehicle Emporium" << std::endl;

  for (auto showroom : m_showrooms)
  {
    std::cout << "Vehicles in " << showroom->GetName() << std::endl;
    const Vehicle* vehicles = showroom->GetVehicleList();
    if (vehicles != nullptr)
    {
      for (unsigned int i = 0; i < showroom->GetCount() && i < showroom->GetCapacity(); i++)
      {
        vehicles[i].Display();
      }
    }

  }
}

Dealership::~Dealership()
{
}
