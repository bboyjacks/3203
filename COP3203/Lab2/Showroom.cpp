#include "Showroom.h"
#include <iostream>


Showroom::Showroom(std::string _showroom_name, int _max_capacity) :
  m_showroom_name(std::move(_showroom_name)),
  m_vehicles{ nullptr },
  m_max_capacity(_max_capacity),
  m_cur_num_vehicle(0)
{
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
  m_vehicles.push_back(_vehicle);
}

void Showroom::ShowInventory() const
{
  std::cout << "Show inventory " << m_showroom_name << std::endl;
}

const Vehicle* Showroom::GetVehicleList() const
{
  if (!m_vehicles.empty())
    return m_vehicles[0];
  else
    return nullptr;
}

unsigned int Showroom::GetCapacity() const
{
  return m_max_capacity;
}

unsigned int Showroom::GetCount() const
{
  return m_vehicles.size();
}

const char* Showroom::GetName() const
{
  return m_showroom_name.c_str();
}

Showroom::~Showroom() = default;
