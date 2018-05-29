#include "Showroom.h"
#include <iostream>


Showroom::Showroom(std::string _showroom_name, int _max_capacity) :
  m_showroom_name(std::move(_showroom_name)),
  m_vehicles{ nullptr },
  m_max_capacity(_max_capacity),
  m_cur_num_vehicle(0)
{
  m_vehicles = new Vehicle*[m_max_capacity];
}

Showroom::Showroom(Showroom&& _other_showroom) noexcept
{
  m_showroom_name = std::move(_other_showroom.m_showroom_name);
  m_vehicles = _other_showroom.m_vehicles;
  m_max_capacity = _other_showroom.m_max_capacity;
  m_cur_num_vehicle = _other_showroom.m_cur_num_vehicle;
}


Showroom& Showroom::operator=(Showroom&& _other_showroom) noexcept
{
  m_showroom_name = std::move(_other_showroom.m_showroom_name);
  m_vehicles = _other_showroom.m_vehicles;
  m_max_capacity = _other_showroom.m_max_capacity;
  m_cur_num_vehicle = _other_showroom.m_cur_num_vehicle;
  return *this;
}

void Showroom::AddVehicle(const Vehicle* _vehicle)
{
  if (m_vehicles != nullptr)
    m_vehicles[m_cur_num_vehicle++] = _vehicle;
}

void Showroom::ShowInventory() const
{
  std::cout << "Show inventory " << m_showroom_name << std::endl;
}

const Vehicle* Showroom::GetVehicleList() const
{
}

unsigned Showroom::GetCapacity() const
{
}

unsigned Showroom::GetCount() const
{
}

const char* Showroom::GetName() const
{
}

Showroom::~Showroom() = default;
