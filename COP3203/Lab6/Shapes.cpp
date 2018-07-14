#include "Shapes.h"
#include <iostream>

static const float S_PI = 3.14159265359f;

bool Shape2D::operator>(const Shape2D& rhs) const
{
  return Area() > rhs.Area();
}

bool Shape2D::operator<(const Shape2D& rhs) const
{
  return Area() < rhs.Area();
}

bool Shape2D::operator==(const Shape2D& rhs) const
{
  return Area() == rhs.Area();
}

bool Shape3D::operator>(const Shape3D& rhs) const
{
  return Volume() > rhs.Volume();
}

bool Shape3D::operator<(const Shape3D& rhs) const
{
  return Volume() < rhs.Volume();
}

bool Shape3D::operator==(const Shape3D & rhs) const
{
  return Volume() == rhs.Volume();
}

Square::Square(float side)
{
  m_side = side;
}

Square::Square(const Square& other)
  : m_side{ other.m_side }
{
}

Square::Square(Square&& other) noexcept
  : m_side{other.m_side}
{
}

Square& Square::operator=(const Square& other)
{
  Square tmp(other);
  *this = std::move(tmp);
  return *this;
}

Square& Square::operator=(Square&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }
  m_side = other.m_side;
  return *this;
}

void Square::Scale(float scaleFactor)
{
  m_side *= scaleFactor;
}

void Square::Display() const
{
  ShowArea();
  std::cout << "Length of side: " << m_side << std::endl;
}

float Square::Area() const
{
  return m_side * m_side;
}

void Square::ShowArea() const
{
  std::cout << "The area of the Square is : " << Area() << std::endl;
}

Rectangle::Rectangle(float length, float width)
{
  m_length = length;
  m_width = width;
}

Rectangle::Rectangle(const Rectangle& other)
  : m_length{other.m_length},
    m_width{other.m_width}
{
}

Rectangle::Rectangle(Rectangle&& other) noexcept
  : m_length{other.m_length},
    m_width{other.m_width}
{
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
  Rectangle tmp(other);
  *this = std::move(tmp);
  return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  m_length = other.m_length;
  m_width = other.m_width;
  return *this;
}

void Rectangle::Scale(float scaleFactor)
{
  m_length *= scaleFactor;
  m_width *= scaleFactor;
}

void Rectangle::Display() const
{
  ShowArea();
  std::cout << "Length: " << m_length << std::endl;
  std::cout << "Width: " << m_width << std::endl;
}

float Rectangle::Area() const
{
  return m_length * m_width;
}

void Rectangle::ShowArea() const
{
  std::cout << "The area of the Rectangle is : " << Area() << std::endl;
}

Triangle::Triangle(float base, float height)
  : m_height{ height },
    m_base{base}
{
}

Triangle::Triangle(const Triangle& other)
  : m_height{ other.m_height },
  m_base{     other.m_base }
{
}

Triangle::Triangle(Triangle&& other) noexcept
  : m_height{ other.m_height },
  m_base{ other.m_base }
{
}

Triangle& Triangle::operator=(const Triangle& other)
{
  Triangle tmp(other);
  *this = std::move(tmp);
  return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }
  m_height = other.m_height;
  m_base = other.m_base;
  return *this;
}

void Triangle::Scale(float scaleFactor)
{
  m_height *= scaleFactor;
  m_base *= scaleFactor;
}

void Triangle::Display() const
{
  ShowArea();
  std::cout << "Base: " << m_base << std::endl;
  std::cout << "Height: " << m_height << std::endl;
}

float Triangle::Area() const
{
  return m_height * m_base * 0.5f;
}

void Triangle::ShowArea() const
{
  std::cout << "The area of the Triangle is : " << Area() << std::endl;
}

Circle::Circle(float radius)
{
  m_radius = radius;
}

Circle::Circle(const Circle& other)
  : m_radius{other.m_radius}
{
}

Circle::Circle(Circle&& other) noexcept
  : m_radius{ other.m_radius }
{
}

Circle& Circle::operator=(const Circle& other)
{
  Circle tmp(other);
  *this = std::move(tmp);
  return *this;
}

Circle& Circle::operator=(Circle&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  return *this;
}

void Circle::Scale(float scaleFactor)
{
  m_radius *= scaleFactor;
}

void Circle::Display() const
{
  ShowArea();
  std::cout << "Radius: " << m_radius << std::endl;
}

float Circle::Area() const
{
  return m_radius * m_radius * S_PI;
}

void Circle::ShowArea() const
{
  std::cout << "The area of the Circle is : " << Area() << std::endl;
}


Ellipse::Ellipse(float length, float width)
  : m_length{length},
    m_width{width}
{
}

Ellipse::Ellipse(const Ellipse& other)
  : m_length{other.m_length},
    m_width{other.m_width}
{
}

Ellipse::Ellipse(Ellipse&& other) noexcept
  : m_length{ other.m_length },
  m_width{ other.m_width }
{
}

Ellipse& Ellipse::operator=(const Ellipse& other)
{
  Ellipse tmp(other);
  *this = std::move(tmp);
  return *this;
}

Ellipse& Ellipse::operator=(Ellipse&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  return *this;
}

void Ellipse::Scale(float scaleFactor)
{
  m_length *= scaleFactor;
  m_width *= scaleFactor;
}

void Ellipse::Display() const
{
  ShowArea();
  std::cout << "Length of semi-major axis: " << m_length << std::endl;
  std::cout << "Length of semi-minor axis: " << m_width << std::endl;
}

float Ellipse::Area() const
{
  return S_PI * m_length * m_width;
}

void Ellipse::ShowArea() const
{
  std::cout << "The area of the Ellipse is : " << Area() << std::endl;
}

Trapezoid::Trapezoid(float top, float bottom, float height)
  : m_top{top},
    m_bottom{bottom},
    m_height{height}
{
}

Trapezoid::Trapezoid(const Trapezoid& other)
  : m_top{  other.m_top },
  m_bottom{ other.m_bottom },
  m_height{ other.m_height }
{
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept
  : m_top{  other.m_top },
  m_bottom{ other.m_bottom },
  m_height{ other.m_height }
{
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other)
{
  Trapezoid tmp(other);
  *this = std::move(tmp);
  return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  return *this;
}

void Trapezoid::Scale(float scaleFactor)
{
  m_top *= scaleFactor;
  m_bottom *= scaleFactor;
  m_height *= scaleFactor;
}

void Trapezoid::Display() const
{
  ShowArea();
  std::cout << "Length of side A: " << m_top << std::endl;
  std::cout << "Length of side B: " << m_bottom << std::endl;
  std::cout << "Height: " << m_height << std::endl;
}

float Trapezoid::Area() const
{
  return 0.5f * (m_top + m_bottom) * m_height;
}

void Trapezoid::ShowArea() const
{
  std::cout << "The area of the Trapezoid is : " << Area() << std::endl;
}


Sector::Sector(float radius, float angle)
  : m_radius{ radius },
    m_angle{ angle }
{
}

Sector::Sector(const Sector& other)
  : m_radius{ other.m_radius },
  m_angle{    other.m_angle }
{
}

Sector::Sector(Sector&& other) noexcept
  : m_radius{ other.m_radius },
  m_angle{ other.m_angle }
{
}

Sector& Sector::operator=(const Sector& other)
{
  Sector tmp(other);
  *this = std::move(tmp);
  return *this;
}

Sector& Sector::operator=(Sector&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  return *this;
}

void Sector::Scale(float scaleFactor)
{
  m_radius *= scaleFactor;
  m_angle *= scaleFactor;
}

void Sector::Display() const
{
  ShowArea();
  std::cout << "Radius: " << m_radius << std::endl;
  std::cout << "Angle in radians: " << m_angle * S_PI / 180 << std::endl;
  std::cout << "Angle in degrees: " << m_angle << std::endl;
}

float Sector::Area() const
{
  return (m_angle * S_PI / 180) * 0.5f * m_radius * m_radius;
}

void Sector::ShowArea() const
{
  std::cout << "The area of the Sector is : " << Area() << std::endl;
}

TriangularPyramid::TriangularPyramid(float height, float baseWidth, double baseLength)
  : m_height{height},
  m_base_width{baseWidth},
  m_base_length{ baseLength }
{
}

TriangularPyramid::TriangularPyramid(const TriangularPyramid& other)
  : m_height{    other.m_height },
  m_base_width{  other.m_base_width },
  m_base_length{ other.m_base_length }
{
}

TriangularPyramid::TriangularPyramid(TriangularPyramid&& other) noexcept
  : m_height{ other.m_height },
  m_base_width{ other.m_base_width },
  m_base_length{ other.m_base_length }
{
}

TriangularPyramid& TriangularPyramid::operator=(const TriangularPyramid& other)
{
  TriangularPyramid tmp(other);
  *this = std::move(tmp);
  return *this;
}

TriangularPyramid& TriangularPyramid::operator=(TriangularPyramid&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  return *this;
}

void TriangularPyramid::Scale(float scaleFactor)
{
  m_height *= scaleFactor;
  m_base_width *= scaleFactor;
  m_base_length *= scaleFactor;
}

void TriangularPyramid::Display() const
{
  ShowVolume();
  std::cout << "The height is: " << m_height << std::endl;
  std::cout << "The area of the Triangle is : " << (m_base_width * m_base_length) * 0.5f << std::endl;
  std::cout << "Base: " << m_base_width << std::endl;
  std::cout << "Height: " << m_base_length << std::endl;
}

float TriangularPyramid::Volume() const
{
  const float area = m_base_width * static_cast<float>(m_base_length) * 0.5f;
  const float pre_cal = 0.33333333333f;
  const float answer = pre_cal*(area) * m_height;
  return answer;
}

void TriangularPyramid::ShowVolume() const
{
  std::cout << "The volume of the Triangular Pyramid is : " << Volume() << std::endl;
}

RectangularPyramid::RectangularPyramid(float height, float width, float length)
  : m_height{ height },
  m_width{ width },
  m_length{ length }
{
}

RectangularPyramid::RectangularPyramid(const RectangularPyramid& other)
  : m_height{ other.m_height },
  m_width{    other.m_width },
  m_length{   other.m_length }
{
}

RectangularPyramid::RectangularPyramid(RectangularPyramid&& other) noexcept
  : m_height{ other.m_height },
  m_width{ other.m_width },
  m_length{ other.m_length }
{
}

RectangularPyramid& RectangularPyramid::operator=(const RectangularPyramid& other)
{
  RectangularPyramid tmp(other);
  *this = std::move(tmp);
  return *this;
}

RectangularPyramid& RectangularPyramid::operator=(RectangularPyramid&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  return *this;
}

void RectangularPyramid::Scale(float scaleFactor)
{
  m_length *= scaleFactor;
  m_width *= scaleFactor;
  m_height *= scaleFactor;
}

void RectangularPyramid::Display() const
{
  ShowVolume();
  std::cout << "The height is: " << m_height << std::endl;
  std::cout << "The area of the Rectangle is : " << (m_width * m_length) << std::endl;
  std::cout << "Length: " << m_width << std::endl;
  std::cout << "Width: " << m_length << std::endl;
}

float RectangularPyramid::Volume() const
{
  return 0.3333333333f * m_length * m_width * m_height;
}

void RectangularPyramid::ShowVolume() const
{
  std::cout << "The volume of the Rectangular Pyramid is : " << Volume() << std::endl;
}

Cylinder::Cylinder(float length, float width)
: m_length{ length },
m_width{ width }
{
}

Cylinder::Cylinder(const Cylinder& other)
  : m_length{ other.m_length },
  m_width{    other.m_width }
{
}

Cylinder::Cylinder(Cylinder&& other) noexcept
  : m_length{ other.m_length },
  m_width{    other.m_width }
{
}

Cylinder& Cylinder::operator=(const Cylinder& other)
{
  Cylinder tmp(other);
  *this = std::move(tmp);
  return *this;
}

Cylinder& Cylinder::operator=(Cylinder&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  return *this;
}

void Cylinder::Scale(float scaleFactor)
{
  m_length *= scaleFactor;
  m_width *= scaleFactor;
}

void Cylinder::Display() const
{
  ShowVolume();
  std::cout << "The height is: " << m_length << std::endl;
  std::cout << "The area of the Circle is : " << S_PI * m_width * m_width << std::endl;
  std::cout << "Radius: " << m_width << std::endl;
}

float Cylinder::Volume() const
{
  return S_PI * m_width * m_width * m_length;
}

void Cylinder::ShowVolume() const
{
  std::cout << "The volume of the Cylinder is : " << Volume() << std::endl;
}

Sphere::Sphere(float radius)
  : m_radius{radius}
{
}

Sphere::Sphere(const Sphere& other)
  : m_radius{other.m_radius}
{
}

Sphere::Sphere(Sphere&& other) noexcept
  : m_radius{ other.m_radius }
{
}

Sphere& Sphere::operator=(const Sphere& other)
{
  Sphere tmp(other);
  *this = std::move(tmp);
  return *this;
}

Sphere& Sphere::operator=(Sphere&& other) noexcept
{
  if (this == &other)
  {
    return *this;
  }

  return *this;
}

void Sphere::Scale(float scaleFactor)
{
  m_radius *= scaleFactor;
}

void Sphere::Display() const
{
  ShowVolume();
  std::cout << "The area of the Circle is : " << m_radius * S_PI * m_radius << std::endl;
  std::cout << "Radius: " << m_radius << std::endl;
}

float Sphere::Volume() const
{
  return 1.333333333333f * S_PI * m_radius * m_radius * m_radius;
}

void Sphere::ShowVolume() const
{
  std::cout << "The volume of the Sphere is : " << Volume() << std::endl;
}