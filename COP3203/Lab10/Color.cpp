#include "Color.h"
#include <vector>
#include <string>

Color::Color()
{
}

void Color::SetValue(int value)
{
  m_value = value;
  m_red = (m_value >> 16) & 255;
  m_green = (m_value >> 8) & 255;
  m_blue = (m_value) & 255;
}

void Color::SetName(const char* name)
{
  m_name = name;
}

unsigned char Color::GetR() const
{
  return m_red;
}

unsigned char Color::GetG() const
{
  return m_green;
}

unsigned char Color::GetB() const
{
  return m_blue;
}

std::string Color::GetHexValue() const
{
  std::string hex_str = "0x" + ConverCharToString(m_red) +
                                ConverCharToString(m_green) +
                                ConverCharToString(m_blue);
  return hex_str;
}

std::string Color::GetName() const
{
  return m_name;
}


Color::~Color()
{
}

std::string Color::ConverCharToString(unsigned char color) const
{
  unsigned char first = color / 16;
  unsigned char second = (color % 16);

  char f_char = ConvertCharToHexChar(first);
  char s_char = ConvertCharToHexChar(second);

  std::vector<char> result = { f_char, s_char };
  std::string result_str(result.begin(), result.end());

  return result_str;
}

char Color::ConvertCharToHexChar(unsigned char c) const
{
  if (9 < c && c < 16)
  {
    return 65 + c - 10;
  }
  else
  {
    return c + '0';
  }
}
