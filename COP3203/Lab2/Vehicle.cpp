#include "Vehicle.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

// Helper consts
static const std::string TAB = "\t";

Vehicle::Vehicle(std::string _make,
                 std::string _model,
                 const int _year,
                 const int _price,
                 const int _miles) :
  m_make(std::move(_make)),
  m_model(std::move(_model)),
  m_year(_year),
  m_price(_price),
  m_miles(_miles)
{
}

Vehicle::Vehicle(const Vehicle& _other_vehicle)
{
  m_make = _other_vehicle.m_make;
  m_model = _other_vehicle.m_model;
  m_price = _other_vehicle.m_price;
  m_year = _other_vehicle.m_year;
  m_miles = _other_vehicle.m_miles;
}

Vehicle::Vehicle(Vehicle&& _other_vehicle) noexcept
{
  m_make = std::move(_other_vehicle.m_make);
  m_model = std::move(_other_vehicle.m_model);
  m_price = _other_vehicle.m_price;
  m_year = _other_vehicle.m_year;
  m_miles = _other_vehicle.m_miles;
}

Vehicle& Vehicle::operator=(const Vehicle& _other_vehicle)
{
  m_make = _other_vehicle.m_make;
  m_model = _other_vehicle.m_model;
  m_price = _other_vehicle.m_price;
  m_year = _other_vehicle.m_year;
  m_miles = _other_vehicle.m_miles;
  return *this;
}

Vehicle& Vehicle::operator=(Vehicle&& _other_vehicle) noexcept
{
  m_make = std::move(_other_vehicle.m_make);
  m_model = std::move(_other_vehicle.m_model);
  m_price = _other_vehicle.m_price;
  m_year = _other_vehicle.m_year;
  m_miles = _other_vehicle.m_miles;
  return *this;
}

void Vehicle::Display() const
{
  std::cout << GetYearMakeModel() << " " + TAB + "$" << static_cast<int>(GetPrice()) << TAB + std::to_string(m_miles) << std::endl;
}

std::string Vehicle::GetYearMakeModel() const
{
  return std::to_string(m_year) + " " + TAB + m_make + " " +  m_model;
}

float Vehicle::GetPrice() const
{
  return m_price;
}

Vehicle::~Vehicle() = default;
