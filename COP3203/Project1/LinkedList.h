#pragma once
#include <string>
#include <vector>
#include <iostream>

template <typename T>
class LinkedList {
public:
  struct Node
  {
    Node(const T& _data)
    {
      data = _data;
    }

    T data;
    Node* prev{ nullptr };
    Node* next{ nullptr };
  };

  LinkedList() {}

  LinkedList(LinkedList<T>& _other)
  {
    Node* cur = _other.m_root;
    while (cur != nullptr)
    {
      AddTail(cur->data);
      cur = cur->next;
    }
    m_count = _other.m_count;
  }

  void Clear()
  {
    while (m_root != nullptr)
    {
      Node* node_to_delete = m_root;
      m_root = m_root->next;
      delete node_to_delete;
    }
    m_count = 0;
    m_root = nullptr;
    m_tail = nullptr;
  }

  ~LinkedList()
  {
    Clear();
  }

  Node* m_root{ nullptr };
  Node* m_tail{ nullptr };
  int m_count{ 0 };

  LinkedList<T>& operator=(LinkedList<T>& l2)
  {
    Node* cur = l2.m_root;
    while (cur != nullptr)
    {
      AddTail(cur->data);
      cur = cur->next;
    }
    m_count = l2.m_count;
    return *this;
  }

  bool operator==(LinkedList<T>& l2)
  {
    bool equal{ true };
    if (m_count != l2.m_count)
      return false;
    Node* cur = m_root;
    Node* cur2 = l2.m_root;
    while (cur != nullptr && cur2 != nullptr)
    {
      if (cur->data != cur2->data)
      {
        equal = false;
        break;
      }
      cur = cur->next;
      cur2 = cur2->next;
    }
    return equal;
  }

  T& operator[](unsigned int _index)
  {
    Node* cur = m_root;
    for (unsigned int i = 0; i < _index; ++i)
    {
      cur = cur->next;
      if (cur == nullptr)
        break;
    }

    if (cur == nullptr)
      throw -1;
    else
      return cur->data;
  }

  void AddHead(const T& _data)
  {
    Node* new_node = new Node(_data);
    if (m_root != nullptr)
    {
      new_node->next = m_root;
      m_root->prev = new_node;
    }
    else if (m_root == nullptr)
    {
      m_tail = new_node;
    }

    m_root = new_node;
    m_count++;
  }

  unsigned int NodeCount()
  {
    return m_count;
  }

  void PrintForward()
  {
    Node* cur = m_root;
    while (cur != nullptr)
    {
      std::cout << cur->data << std::endl;
      cur = cur->next;
    }
  }

  void PrintReverse()
  {
    PrintReverse(m_root);
  }

  void PrintReverse(Node* _root)
  {
    if (_root == nullptr)
      return;
    PrintReverse(_root->next);
    std::cout << _root->data << std::endl;
  }

  void AddTail(const T& _data)
  {
    Node* new_node = new Node(_data);
    if (m_root == nullptr || m_tail == nullptr)
    {
      m_root = new_node;
      m_tail = new_node;
    }
    else if (m_tail != nullptr)
    {
      m_tail->next = new_node;
      new_node->prev = m_tail;
      m_tail = new_node;
    }
    m_count++;
  }

  unsigned int Remove(const T& _data)
  {
    Node* cur = m_root;
    int num_node_deleted = 0;
    while (cur != nullptr)
    {
      if (cur->data == _data)
      {
        cur->prev->next = cur->next;
        cur->prev->next->prev = cur->prev;
        Node* node_to_delete = cur;
        cur = cur->prev;
        delete node_to_delete;
        num_node_deleted += 1;
      }
      cur = cur->next;
    }
    m_count -= num_node_deleted;
    return num_node_deleted;
  }

  bool RemoveHead()
  {
    Node* node_to_delete = m_root;
    if (m_root != nullptr)
    {
      m_root = m_root->next;
      if (m_root != nullptr)
        m_root->prev = nullptr;
    }
    else
      return false;
    delete node_to_delete;
    m_count--;
    return true;
  }

  bool RemoveTail()
  {
    Node* node_to_delete = m_tail;
    if (m_tail == nullptr)
    {
      return false;
    }
    else if (m_root == m_tail)
    {
      m_root = nullptr;
      m_tail = nullptr;
    }
    else if (m_tail != nullptr)
    {
      m_tail = m_tail->prev;
      if (m_tail != nullptr)
        m_tail->next = nullptr;
    }
    delete node_to_delete;
    m_count--;
    return true;
  }

  bool RemoveAt(unsigned int _index)
  {
    Node* cur = m_root;
    for (unsigned int i = 0; i < _index && cur != nullptr; ++i)
    {
      cur = cur->next;
    }

    if (cur != nullptr)
    {
      if (cur == m_root)
      {
        RemoveHead();
      }
      else if (cur == m_tail)
      {
        RemoveTail();
      }
      else
      {
        Node* node_to_delete = cur;
        cur = cur->prev;
        cur->next = cur->next->next;
        cur->next->prev = cur;
        delete node_to_delete;

      }
    }
    else
      return false;
    m_count--;
    return true;
  }

  void AddNodesHead(std::string* _list, unsigned int _size)
  {
    for (int i = _size - 1; i >= 0; --i)
    {
      AddHead(_list[i]);
      m_count++;
    }
  }

  void AddNodesTail(std::string* _list, unsigned int _size)
  {
    for (unsigned int i = 0; i < _size; ++i)
    {
      AddTail(_list[i]);
      m_count++;
    }
  }

  Node* Find(const T& _data)
  {
    Node* cur = m_root;
    while (cur != nullptr)
    {
      if (cur->data == _data)
      {
        break;
      }
      cur = cur->next;
    }

    if (cur != nullptr)
      return cur;
    return nullptr;
  }

  void InsertBefore(Node* _node, unsigned int _index)
  {
    if (_node == m_root)
    {
      AddHead(_index);
    }
    else if (_node == m_tail)
    {
      AddTail(_index);
    }
    else
    {
      Node* new_node = new Node(_index);
      new_node->next = _node;
      _node->prev->next = new_node;
      new_node->prev = _node->prev;
      _node->prev = new_node;
      m_count++;
    }
  }

  Node* Head()
  {
    return m_root;
  }

  Node* Tail()
  {
    return m_tail;
  }

  void InsertAfter(Node* _node, const T& _index)
  {
    if (_node == m_root)
    {
      AddHead(_index);
    }
    else if (_node == m_tail)
    {
      AddTail(_index);
    }
    else
    {
      Node* new_node = new Node(_index);
      new_node->next = _node->next;
      _node->next->prev = new_node;
      _node->next = new_node;
      new_node->prev = _node;
      m_count++;
    }
  }

  Node* GetNode(int _index)
  {
    Node* cur = m_root;
    for (int i = 0; i < _index && cur != nullptr; ++i)
    {
      cur = cur->next;
    }

    if (cur != nullptr)
      return cur;
    else
      throw "Out of bounds";
  }

  void InsertAt(const T& _data, int _index)
  {
    Node* cur = m_root;
    for (int i = 1; i < _index && cur != nullptr; ++i)
    {
      cur = cur->next;
    }

    if (cur != nullptr)
    {
      InsertAfter(cur, _data);
    }
    else
      throw "Out of bounds";
  }

  void FindAll(std::vector <Node*>& _result_Nodes,
    T& _search_val)
  {
    Node* cur = m_root;
    while (cur != nullptr)
    {
      if (cur->data == _search_val)
      {
        _result_Nodes.push_back(cur);
      }
      cur = cur->next;
    }
  }
};
