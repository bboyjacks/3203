#pragma once

#include <string>

class Vehicle
{
public:
  Vehicle();
  Vehicle(std::string _make,
          std::string _model,
          const int _year,
          const int _price,
          const int _miles);
  Vehicle(const Vehicle& _other_vehicle);
  Vehicle(Vehicle&& _other_vehicle) noexcept;
  Vehicle& operator=(const Vehicle& _other_vehicle);
  Vehicle& operator=(Vehicle&& _other_vehicle) noexcept;

  void Display() const;
  std::string GetYearMakeModel() const;
  float GetPrice() const;

  virtual ~Vehicle();
private:
  std::string m_make;
  std::string m_model;
  int m_year;
  int m_price;
  int m_miles;
};