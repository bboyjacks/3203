#pragma once
#include <string>
class Image
{
public:
  Image();
  void Load(const std::string& file);
  void Write(const std::string& out_file);
  ~Image();
private:
  unsigned char* m_image;

  struct Header
  {
    char m_id_length;
    char m_coluor_map_type;
    char m_data_type_code;
    short m_colour_map_origin;
    short m_colour_map_length;
    char m_colour_map_depth;
    short m_xorigin;
    short m_yorigin;
    short m_width;
    short m_height;
    char m_bit_per_pixel;
    char m_image_descriptor;
  } m_header;
};

