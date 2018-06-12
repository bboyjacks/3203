#pragma once

template <class T>
class DynamicArray  // NOLINT
{
public:
  unsigned int GetCapacity() const;
  unsigned int GetSize() const;
  const T* GetData() const;

  const T& operator[](unsigned int _index) const;
  T& operator[](unsigned int _index);

  const T& At(unsigned int _index) const;
  T& At(unsigned int _index);

  void Add(const T& _data);
  void Resize(unsigned int _new_size);
  void Remove(unsigned int _index);

  DynamicArray();
  explicit DynamicArray(unsigned int _size);
  DynamicArray(const DynamicArray& _d);
  DynamicArray &operator=(const DynamicArray& _d);
  virtual ~DynamicArray();
private:
  void RefreshData();

  T* m_data;
  unsigned int m_capacity;
  unsigned int m_size;

  static const int INCREMENT_CAPACITY = 1;
};


template <class T>
unsigned int DynamicArray<T>::GetCapacity() const
{
  return m_capacity;
}

template <class T>
unsigned int DynamicArray<T>::GetSize() const
{
  return m_size;
}

template <class T>
const T* DynamicArray<T>::GetData() const
{
  return m_data;
}

template <class T>
const T& DynamicArray<T>::operator[](unsigned int _index) const
{
  if (0 <= _index && _index < GetSize())
    return m_data[_index];
  throw "Error: Invalid index";
}

template <class T>
T& DynamicArray<T>::operator[](unsigned int _index)
{
  if (0 <= _index && _index < GetSize())
    return m_data[_index];
  throw "Error: Invalid index";
}

template <class T>
const T& DynamicArray<T>::At(unsigned int _index) const
{
  if (0 <= _index && _index < GetSize())
    return m_data[_index];
  throw "Error: Invalid index";
}

template <class T>
T& DynamicArray<T>::At(unsigned int _index)
{
  if (0 <= _index && _index < GetSize())
    return m_data[_index];
  throw "Error: Invalid index";
}

template <class T>
void DynamicArray<T>::Add(const T& _data)
{
  if (m_size >= m_capacity)
  {
    std::cout << "Resizing... old capacity: " << m_capacity << " New capacity: ";
    m_capacity += INCREMENT_CAPACITY;
    std::cout << m_capacity << std::endl;
    RefreshData();
  }
  m_data[m_size] = _data;
  m_size++;
}

template <class T>
void DynamicArray<T>::Resize(unsigned int _new_size)
{
  if (_new_size > 0)
  {
    std::cout << "Resizing... old capacity: " << m_capacity << " New capacity: ";
    m_capacity = _new_size;
    if (m_size > m_capacity)
      m_size = m_capacity;
    std::cout << m_capacity << std::endl;
    RefreshData();
  }
}

template <class T>
void DynamicArray<T>::Remove(unsigned int _index)
{
  if (0 <= _index && _index < m_size && m_size > 0)
  {
    for (unsigned int i = _index; i < m_size - 1; i++)
    {
      m_data[i] = m_data[i + 1];
    }
    m_size--;

    if (m_capacity - m_size > 10)
    {
      const int num = m_size / 10;
      m_capacity = ((num + 1) * 10);
      RefreshData();
    }
  }
  else
    throw "Error! Invalid index";
}

template <class T>
DynamicArray<T>::DynamicArray() :
  m_data(nullptr),
  m_capacity(0),
  m_size(0)
{
  RefreshData();
}

template<class T>
DynamicArray<T>::DynamicArray(unsigned int _size) :
  m_data(nullptr),
  m_capacity(0),
  m_size(0)
{
  if (_size > 0)
  {
    m_capacity = _size;
  }
  RefreshData();
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& _d) :
  m_capacity(_d.m_capacity),
  m_size(_d.m_size)
{
  m_data = new T[m_size];
  for (unsigned int i = 0; i < m_size; i++)
  {
    m_data[i] = _d.m_data[i];
  }
  RefreshData();
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& _d)
{
  m_capacity = _d.m_capacity;
  m_size = _d.m_size;

  m_data = new T[m_size];
  for (unsigned int i = 0; i < m_size; i++)
  {
    m_data[i] = _d.m_data[i];
  }
  return *this;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete[] m_data;
  m_data = nullptr;
}

template<class T>
void DynamicArray<T>::RefreshData()
{
  if (m_capacity > 0)
  {
    T* new_data = new T[m_capacity];
    for (unsigned int i = 0; i < m_size; i++)
    {
      if (m_data != nullptr)
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
  }
}