#pragma once

template <typename T>
class ABS {
public:
  ABS()
  {
    m_values = new T[m_capacity];
  }

  ABS(unsigned int _initial_capacity)
  {
    m_capacity = _initial_capacity;
    m_values = new T[m_capacity];
  }

  ABS(const ABS& _d)
  {
    m_capacity = _d.m_capacity;
    m_size = _d.m_size;
    m_scale_factor = _d.m_scale_factor;
    m_values = new T[m_capacity];
    for (unsigned int i = 0; i < m_size; i++)
      m_values[i] = _d.m_values[i];
  }

  ABS& operator=(const ABS& _d)
  {
    m_capacity = _d.m_capacity;
    m_size = _d.m_size;
    m_scale_factor = _d.m_scale_factor;
    m_values = new T[m_capacity];
    for (unsigned int i = 0; i < m_size; i++)
      m_values[i] = _d.m_values[i];
    return this;
  }
 
  ~ABS()
  {
    delete[] m_values;
  }

  unsigned int getSize() const
  {
    return m_size;
  }

  unsigned int getMaxCapacity() const
  {
    return m_capacity;
  }

  void push(const T& _value)
  {
    if (m_size + 1 > m_capacity)
    {
      m_capacity *= m_scale_factor;

      T* temp = new T[m_capacity];
      for (unsigned int i = 0; i < m_size; i++)
        temp[i] = m_values[i];

      delete[] m_values;
      m_values = temp;
    }

    m_values[m_size++] = _value;
  }

  T peek()
  {
    if (m_size < 1)
      throw -1;
    return m_values[m_size-1];
  }

  T pop()
  {

    if (m_size != 0 && m_capacity != 1)
    {
      T value = m_values[m_size - 1];
      m_size -= 1;

      if (m_capacity / m_scale_factor > m_size)
      {
        m_capacity /= m_scale_factor;
        T* temp = new T[m_capacity];
        for (unsigned int i = 0; i < m_size; i++)
          temp[i] = m_values[i];

        delete[] m_values;
        m_values = temp;
      }
      return value;
    }
    else
      throw -1;
  }

  T* getData()
  {
    return m_values;
  }

private:
  unsigned int m_size{0};
  float m_scale_factor{ 2.0f };
  unsigned int m_capacity{ 1 };
  T* m_values;
};