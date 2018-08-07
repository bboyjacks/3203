#pragma once
#include <string>

class Color
{
public:
  Color();

  void SetValue(int value);
  void SetName(const char* name);

  unsigned char GetR() const;
  unsigned char GetG() const;
  unsigned char GetB() const;
  std::string GetHexValue() const;
  std::string GetName() const;

  ~Color();
private:
  std::string ConverCharToString(unsigned char color) const;
  char ConvertCharToHexChar(unsigned char c) const;

  std::string m_name{ "" };
  int m_value{ 0 };
  unsigned char m_red{ 0 };
  unsigned char m_green{ 0 };
  unsigned char m_blue{ 0 };

};

