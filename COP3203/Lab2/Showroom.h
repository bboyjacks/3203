#pragma once
#include <string>
#include <vector>
#include "Vehicle.h"

class Showroom
{
public:
  Showroom(std::string _showroom_name, int _max_capacity);
  Showroom(const Showroom& _other_showroom) = default;
  Showroom(Showroom&& _other_showroom) noexcept;
  Showroom& operator=(const Showroom& _other_showroom) = default;
  Showroom& operator=(Showroom&& _other_showroom) noexcept;

  void AddVehicle(const Vehicle* _vehicle);
  void ShowInventory() const;

  const Vehicle* GetVehicleList() const;
  unsigned int GetCapacity() const;
  unsigned int GetCount() const;
  const char* GetName() const;

  virtual ~Showroom();
private:
  std::string m_showroom_name;
  std::vector<const Vehicle*> m_vehicles;
  int m_max_capacity;
  int m_cur_num_vehicle;
};

