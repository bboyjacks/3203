#include "Image.h"
#include <fstream>
#include <iostream>


Image::Image()
{
}

void Image::Load(const std::string & file)
{
  std::ifstream is(file, std::ifstream::binary);

  if (is.is_open())
  {
    is.seekg(12);
    is.read((char *)&m_header.m_width, sizeof(m_header.m_width));
    is.seekg(14);
    is.read((char *)&m_header.m_height, sizeof(m_header.m_height));

    int image_size = m_header.m_width * m_header.m_height * 3;
    m_image = new unsigned char[image_size];
    is.seekg(18);
    is.read((char *)m_image, sizeof(unsigned char) * image_size);
  }
}

void Image::Write(const std::string& out_file)
{
  std::ofstream out(out_file, std::ofstream::binary);

  if (out.is_open())
  {
    out.seekp(12);
    out.write((char *)&m_header.m_width, sizeof(m_header.m_width));
    out.seekp(14);
    out.write((char *)&m_header.m_height, sizeof(m_header.m_height));
    out.seekp(18);
    int image_size = m_header.m_width * m_header.m_height * 3;
    out.write((char *)m_image, sizeof(unsigned char) * image_size);
  }
}

Image::~Image()
{
  delete[] m_image;
}
