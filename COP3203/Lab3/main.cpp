#include <iostream>
#include "DynamicArray.h"

int main()
{
  DynamicArray<int> dynamic_array;
  std::cout << dynamic_array[0] << std::endl;

  dynamic_array.Add(1);
  std::cout << dynamic_array.GetCapacity() << std::endl;
  std::cout << dynamic_array.GetSize() << std::endl;

  dynamic_array.Add(1);
  std::cout << dynamic_array.GetCapacity() << std::endl;
  std::cout << dynamic_array.GetSize() << std::endl;

  dynamic_array.Add(1);
  std::cout << dynamic_array.GetCapacity() << std::endl;
  std::cout << dynamic_array.GetSize() << std::endl;

  dynamic_array.Add(1);
  std::cout << dynamic_array.GetCapacity() << std::endl;
  std::cout << dynamic_array.GetSize() << std::endl;

  std::getchar();
  return 0;
}