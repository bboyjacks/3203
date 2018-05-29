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

  virtual ~Dealership();
private:
  std::string m_dealer_name;
  int m_num_showroom;
  std::vector<const Showroom*> m_showrooms;
};

