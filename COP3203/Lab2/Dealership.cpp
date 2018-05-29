#include "Dealership.h"
#include <iostream>
#include <iomanip>


Dealership::Dealership(std::string _dealer_name, const int _num_showroom):
  m_dealer_name(std::move(_dealer_name)),
  m_num_showroom(_num_showroom),
  m_showroom_index(0)
{
  m_showrooms = new Showroom[m_num_showroom];
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
  if (_showroom != nullptr)
  {
    if (m_showroom_index < m_num_showroom)
    {
      m_showrooms[m_showroom_index++] = *_showroom;
    }
  }
}

void Dealership::ShowInventory() const
{
  std::cout << "Inventory of " << m_dealer_name << std::endl;

  m_total_car_price = 0.0f;
  m_total_car_count = 0.0f;
  for (unsigned int x = 0; x < m_showroom_index; x++)
  {
    std::cout << "Vehicles in " << m_showrooms[x].GetName() << std::endl;
    const Vehicle* vehicles = m_showrooms[x].GetVehicleList();
    if (vehicles != nullptr)
    {
      for (unsigned int i = 0; i < m_showrooms[x].GetCount() && i < m_showrooms[x].GetCapacity(); i++)
      {
        vehicles[i].Display();
        m_total_car_price += vehicles[i].GetPrice();
        m_total_car_count++;
      }
      std::cout << std::endl;
    }
  }

  std::cout << "Average car price: $" << std::setprecision(7) << GetAveragePrice() << std::endl;
}

float Dealership::GetAveragePrice() const
{
  return m_total_car_price / m_total_car_count;
}

Dealership::~Dealership()
{
  delete[] m_showrooms;
  std::cout << m_dealer_name << " destructor called." << std::endl;
}
