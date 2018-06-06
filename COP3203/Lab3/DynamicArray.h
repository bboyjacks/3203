#pragma once

template <class T>
class DynamicArray  // NOLINT
{
public:
  unsigned int GetCapacity() const;
  unsigned int GetSize() const;
  const T* GetData() const;

  const T& operator[](unsigned int _index) const;

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

  static const int INCREMENT_CAPACITY = 10;
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
  if (_index < GetSize())
    return m_data[_index];
  return -1;
}

template <class T>
void DynamicArray<T>::Add(const T& _data)
{
  if (m_size >= m_capacity)
  {
    m_capacity += INCREMENT_CAPACITY;
    RefreshData();
  }
  m_data[m_size] = _data;
  m_size++;
}

template <class T>
void DynamicArray<T>::Resize(unsigned int _new_size)
{
  m_capacity = _new_size;
  RefreshData();
}

template <class T>
void DynamicArray<T>::Remove(unsigned int _index)
{
  if (m_capacity > 0)
  {
    m_size--;
    const int num = m_size / 10;
    m_capacity = ((num + 1) * 10);
    RefreshData();
  }
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
  RefreshData();
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& _d) :
  m_data(_d.m_data),
  m_capacity(0),
  m_size(0)
{
  RefreshData();
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& _d)
{
  m_data = _d.m_data;
  m_capacity = _d.m_capacity;
  m_size = _d.m_size;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete[] m_data;
}

template<class T>
void DynamicArray<T>::RefreshData()
{
  if (m_capacity > 0)
  {
    delete[] m_data;
    m_data = new T[m_capacity];
  }
}