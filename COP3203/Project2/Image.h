#pragma once
#include <string>
class Image
{
public:
  Image();
  void Load(const std::string& file);
  void Write();
  ~Image();
};

