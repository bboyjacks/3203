#include "DynamicArray.h"


template <class T>
unsigned int DynamicArray<T>::GetCapacity() const
{
  return 0;
}

template <class T>
unsigned int DynamicArray<T>::GetSize() const
{
  return 0;
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
  return nullptr;
}

template <class T>
void DynamicArray<T>::Add(const T& _data)
{

}

template <class T>
void DynamicArray<T>::Resize(unsigned int _new_size)
{
}

template <class T>
void DynamicArray<T>::Remove(unsigned int _index)
{
}

template <class T>
DynamicArray<T>::DynamicArray() :
  m_data(nullptr)
{
}

template<class T>
DynamicArray<T>::DynamicArray(unsigned int _size) :
  m_data(nullptr)
{
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& _d) :
  m_data(_d.m_data)
{
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& _d)
{
  m_data = _d.m_data;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete[] m_data;
}