#include <iostream>
#include "DynamicArray.h"

int main()
{
  DynamicArray<int> dynamic_array;
  std::cout << dynamic_array[0] << std::endl;

  for (unsigned int i = 0; i < 12; i++)
  {
    dynamic_array.Add(1);
    std::cout << dynamic_array.GetCapacity() << std::endl;
    std::cout << dynamic_array.GetSize() << std::endl;
  }

  std::cout << "---------------------------" << std::endl;
  dynamic_array.Remove(0);
  dynamic_array.Remove(0);
  std::cout << dynamic_array.GetCapacity() << std::endl;
  std::cout << dynamic_array.GetSize() << std::endl;

  dynamic_array.Remove(0);
  std::cout << dynamic_array.GetCapacity() << std::endl;
  std::cout << dynamic_array.GetSize() << std::endl;

  //dynamic_array.Add(1);
  //std::cout << dynamic_array.GetCapacity() << std::endl;
  //std::cout << dynamic_array.GetSize() << std::endl;

  //dynamic_array.Add(1);
  //std::cout << dynamic_array.GetCapacity() << std::endl;
  //std::cout << dynamic_array.GetSize() << std::endl;

  //dynamic_array.Add(1);
  //std::cout << dynamic_array.GetCapacity() << std::endl;
  //std::cout << dynamic_array.GetSize() << std::endl;

  std::getchar();
  return 0;
}