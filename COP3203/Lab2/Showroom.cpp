#include "Showroom.h"
#include <iostream>


Showroom::Showroom() :
  m_showroom_name(""),
  m_vehicles(nullptr),
  m_max_capacity(0),
  m_cur_num_vehicle(0)
{
}

Showroom::Showroom(std::string _showroom_name, const int _max_capacity) :
  m_showroom_name(std::move(_showroom_name)),
  m_max_capacity(_max_capacity),
  m_cur_num_vehicle(0)
{
  m_vehicles = static_cast<const Vehicle**>(malloc(sizeof(Vehicle*) * m_max_capacity));
}

Showroom::Showroom(const Showroom& _other_showroom)
{
  m_showroom_name = _other_showroom.m_showroom_name;
  m_vehicles = _other_showroom.m_vehicles;
  m_max_capacity = _other_showroom.m_max_capacity;
  m_cur_num_vehicle = _other_showroom.m_cur_num_vehicle;
}

Showroom::Showroom(Showroom&& _other_showroom) noexcept
{
  m_showroom_name = std::move(_other_showroom.m_showroom_name);
  m_vehicles = _other_showroom.m_vehicles;
  m_max_capacity = _other_showroom.m_max_capacity;
  m_cur_num_vehicle = _other_showroom.m_cur_num_vehicle;
}

Showroom& Showroom::operator=(const Showroom& _other_showroom)
{
  m_showroom_name = _other_showroom.m_showroom_name;
  m_vehicles = _other_showroom.m_vehicles;
  m_max_capacity = _other_showroom.m_max_capacity;
  m_cur_num_vehicle = _other_showroom.m_cur_num_vehicle;
  return *this;
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
  if (_vehicle != nullptr)
    m_vehicles[m_cur_num_vehicle++] = _vehicle;
}

void Showroom::ShowInventory() const
{
  std::cout << "Show inventory " << m_showroom_name << std::endl;
}

const Vehicle* Showroom::GetVehicleList() const
{
  return m_vehicles[0];
}

unsigned int Showroom::GetCapacity() const
{
  return m_max_capacity;
}

unsigned int Showroom::GetCount() const
{
  return m_cur_num_vehicle;
}

const char* Showroom::GetName() const
{
  return m_showroom_name.c_str();
}

Showroom::~Showroom() 
{
  for (unsigned int i = 0; i < m_cur_num_vehicle; i++)
    m_vehicles[i]->~Vehicle();
  std::cout << GetName() << " destructor called." << std::endl;
}
