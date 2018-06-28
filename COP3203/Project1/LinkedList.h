#pragma once
#include <string>
#include <vector>

template <typename T>
class LinkedList {
public:
  struct Node
  {
    T* data;
    Node* prev{ nullptr };
    Node* next{ nullptr };
  };

  T& operator[](unsigned int _index)
  {
    T* val = new T();
    return *val;
  }

  void AddHead(const T& _data)
  {

  }

  unsigned int NodeCount()
  {
    return 0;
  }

  void PrintForward()
  {

  }

  void PrintReverse()
  {

  }

  void AddTail(const T& _data)
  {

  }

  unsigned int Remove(const T& _data)
  {
    return 0;
  }

  bool RemoveHead()
  {
    return true;
  }

  bool RemoveTail()
  {
    return true;
  }

  bool RemoveAt(unsigned int _index)
  {
    return true;
  }

  void AddNodesHead(std::string* _list, unsigned int _size)
  {

  }

  void AddNodesTail(std::string* _list, unsigned int _size)
  {

  }

  Node* Find(const T& _data)
  {
    return nullptr;
  }

  void InsertBefore(const Node* _node, unsigned int _index)
  {

  }

  void InsertAfter(const Node* _node, unsigned int _index)
  {

  }

  Node* GetNode(const T& _data)
  {
    return nullptr;
  }

  void InsertAt(const T& _data, unsigned int _index)
  {

  }

  void FindAll(std::vector <Node*> _result_Nodes,
    T& _search_val)
  {

  }
};
