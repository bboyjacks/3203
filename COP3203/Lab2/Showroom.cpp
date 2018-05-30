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
  m_vehicles = new Vehicle[m_max_capacity];
}

Showroom::Showroom(const Showroom& _other_showroom) :
  m_showroom_name(_other_showroom.m_showroom_name),
  m_max_capacity(_other_showroom.m_max_capacity),
  m_cur_num_vehicle(_other_showroom.m_cur_num_vehicle)
{
  m_vehicles = new Vehicle[m_max_capacity];
  for (int i = 0; i < m_cur_num_vehicle; i++)
    m_vehicles[i] = _other_showroom.m_vehicles[i];
}

Showroom::Showroom(Showroom&& _other_showroom) noexcept
{
  m_showroom_name = std::move(_other_showroom.m_showroom_name);
  m_max_capacity = _other_showroom.m_max_capacity;
  m_cur_num_vehicle = _other_showroom.m_cur_num_vehicle;

  m_vehicles = new Vehicle[m_max_capacity];
  for (int i = 0; i < m_cur_num_vehicle; i++)
    m_vehicles[i] = _other_showroom.m_vehicles[i];
}

Showroom& Showroom::operator=(const Showroom& _other_showroom)
{
  m_showroom_name = _other_showroom.m_showroom_name;
  m_max_capacity = _other_showroom.m_max_capacity;
  m_cur_num_vehicle = _other_showroom.m_cur_num_vehicle;

  m_vehicles = new Vehicle[m_max_capacity];
  for (int i = 0; i < m_cur_num_vehicle; i++)
    m_vehicles[i] = _other_showroom.m_vehicles[i];
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
  {
    if (m_cur_num_vehicle < m_max_capacity)
    {
      Vehicle* new_vehicle = new Vehicle(*_vehicle);
      m_vehicles[m_cur_num_vehicle++] = *new_vehicle;
    }
  }
}

void Showroom::ShowInventory() const
{
  std::cout << "Show inventory " << m_showroom_name << std::endl;
}

const Vehicle* Showroom::GetVehicleList() const
{
  return m_vehicles;
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
  delete[] m_vehicles;
  std::cout << GetName() << " destructor called." << std::endl;
}
