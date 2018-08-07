#include <iostream>
#include "Image.h"

int main()
{
  Image image;
  image.Load("./input/car.tga");
  image.Write("./output/car_replica.tga");
  int option;
  std::cin >> option;
  return 0;
}