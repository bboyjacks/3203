#pragma once
#include <string>
#include "Showroom.h"
class Dealership
{
public:

  Dealership(std::string _dealer_name, const int _num_showroom);
  Dealership(const Dealership& _other);
  Dealership(Dealership&& _other) noexcept;
  Dealership& operator=(const Dealership& _other);
  Dealership& operator=(Dealership&& _other) noexcept;

  void AddShowroom(const Showroom* _showroom);
  void ShowInventory() const;
  float GetAveragePrice() const;

  virtual ~Dealership();
private:
  std::string m_dealer_name;
  unsigned int m_num_showroom;
  unsigned int m_showroom_index;
  Showroom* m_showrooms;
  mutable float m_total_car_price;
  mutable int m_total_car_count;
};

