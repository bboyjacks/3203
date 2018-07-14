#pragma once
class Shape
{
public:
  virtual ~Shape() = default;
  virtual void Scale(float scaleFactor) = 0;
  virtual void Display() const = 0;
};

class Shape2D : virtual public Shape
{
public:
  virtual float Area() const = 0;
  virtual void ShowArea() const = 0;
  bool operator>(const Shape2D &rhs) const;
  bool operator<(const Shape2D &rhs) const;
  bool operator==(const Shape2D &rhs) const;
};

class Shape3D : virtual public Shape
{
public:
  virtual float Volume() const = 0;
  virtual void ShowVolume() const = 0;
  bool operator>(const Shape3D &rhs) const;
  bool operator<(const Shape3D &rhs) const;
  bool operator==(const Shape3D & rhs) const;
};

class Square : public Shape2D
{
public:
  Square() = default;
  explicit Square(float side);
  Square(const Square& other);
  Square(Square&& other) noexcept;
  Square& operator=(const Square& other);
  Square& operator=(Square&& other) noexcept;
  virtual ~Square() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Area() const override;
  virtual void ShowArea() const override;
private:
  float m_side{ 0.0f };
};

class Rectangle : public Shape2D
{
public:
  Rectangle() = default;
  Rectangle(float length, float width);
  Rectangle(const Rectangle& other);
  Rectangle(Rectangle&& other) noexcept;
  Rectangle& operator=(const Rectangle& other);
  Rectangle& operator=(Rectangle&& other) noexcept;
  virtual ~Rectangle() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Area() const override;
  virtual void ShowArea() const override;
private:
  float m_length{ 0.0f };
  float m_width{ 0.0f };
};

class Triangle : public Shape2D
{
public:
  Triangle() = default;
  Triangle(float base, float height);
  Triangle(const Triangle& other);
  Triangle(Triangle&& other) noexcept;
  Triangle& operator=(const Triangle& other);
  Triangle& operator=(Triangle&& other) noexcept;
  virtual ~Triangle() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Area() const override;
  virtual void ShowArea() const override;
private:
  float m_height{ 0.0f };
  float m_base{ 0.0f };
};

class Circle : public Shape2D
{
public:
  Circle() = default;
  Circle(float radius);
  Circle(const Circle& other);
  Circle(Circle&& other) noexcept;
  Circle& operator=(const Circle& other);
  Circle& operator=(Circle&& other) noexcept;
  virtual ~Circle() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Area() const override;
  virtual void ShowArea() const override;
private:
  float m_radius{ 0.0f };
};

class Ellipse : public Shape2D
{
public:
  Ellipse() = default;
  Ellipse(float length, float width);
  Ellipse(const Ellipse& other);
  Ellipse(Ellipse&& other) noexcept;
  Ellipse& operator=(const Ellipse& other);
  Ellipse& operator=(Ellipse&& other) noexcept;
  virtual ~Ellipse() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Area() const override;
  virtual void ShowArea() const override;
private:
  float m_length{ 0.0f };
  float m_width{ 0.0f };
};

class Trapezoid : public Shape2D
{
public:
  Trapezoid() = default;
  Trapezoid(float top, float bottom, float height);
  Trapezoid(const Trapezoid& other);
  Trapezoid(Trapezoid&& other) noexcept;
  Trapezoid& operator=(const Trapezoid& other);
  Trapezoid& operator=(Trapezoid&& other) noexcept;
  virtual ~Trapezoid() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Area() const override;
  virtual void ShowArea() const override;
private:
  float m_top{ 0.0f };
  float m_bottom{ 0.0f };
  float m_height{ 0.0f };
};

class Sector : public Shape2D
{
public:
  Sector() = default;
  Sector(float radius, float angle);
  Sector(const Sector& other);
  Sector(Sector&& other) noexcept;
  Sector& operator=(const Sector& other);
  Sector& operator=(Sector&& other) noexcept;
  virtual ~Sector() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Area() const override;
  virtual void ShowArea() const override;
private:
  float m_radius{ 0.0f };
  float m_angle{ 0.0f };
};

class TriangularPyramid : public Shape3D
{
public:
  TriangularPyramid() = default;
  TriangularPyramid(float height, float baseWidth, double baseLength);
  TriangularPyramid(const TriangularPyramid& other);
  TriangularPyramid(TriangularPyramid&& other) noexcept;
  TriangularPyramid& operator=(const TriangularPyramid& other);
  TriangularPyramid& operator=(TriangularPyramid&& other) noexcept;
  virtual ~TriangularPyramid() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Volume() const override;
  virtual void ShowVolume() const override;
private:
  float m_height{ 0.0f };
  float m_base_width{ 0.0f };
  double m_base_length{ 0.0 };
};

class RectangularPyramid : public Shape3D
{
public:
  RectangularPyramid() = default;
  RectangularPyramid(float height, float width, float length);
  RectangularPyramid(const RectangularPyramid& other);
  RectangularPyramid(RectangularPyramid&& other) noexcept;
  RectangularPyramid& operator=(const RectangularPyramid& other);
  RectangularPyramid& operator=(RectangularPyramid&& other) noexcept;
  virtual ~RectangularPyramid() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Volume() const override;
  virtual void ShowVolume() const override;
private:
  float m_height{ 0.0f };
  float m_width{ 0.0f };
  float m_length{ 0.0f };
};

class Cylinder : public Shape3D
{
public:
  Cylinder() = default;
  Cylinder(float length, float width);
  Cylinder(const Cylinder& other);
  Cylinder(Cylinder&& other) noexcept;
  Cylinder& operator=(const Cylinder& other);
  Cylinder& operator=(Cylinder&& other) noexcept;
  virtual ~Cylinder() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Volume() const override;
  virtual void ShowVolume() const override;
private:
  float m_length{ 0.0f };
  float m_width{ 0.0f };
};

class Sphere : public Shape3D
{
public:
  Sphere() = default;
  Sphere(float radius);
  Sphere(const Sphere& other);
  Sphere(Sphere&& other) noexcept;
  Sphere& operator=(const Sphere& other);
  Sphere& operator=(Sphere&& other) noexcept;
  virtual ~Sphere() noexcept = default;

  void Scale(float scaleFactor) override;
  void Display() const override;
  virtual float Volume() const override;
  virtual void ShowVolume() const override;
private:
  float m_radius{ 0.0f };
};