#pragma once

template<class T>
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
  T* m_data;
};
