// Copyright 2026 Ivan Trushkov

#ifndef LIB_DISJOINT_SET_UNION_DSU_H_
#define LIB_DISJOINT_SET_UNION_DSU_H_

#include <stdexcept>

class DSU {
 private:
  size_t* _data;
  size_t _size;
  size_t* _rank;  // под вопросом, мб по другому сделаю, для реализации при помощи

 public:
  DSU();
  DSU(int size);
  ~DSU() { delete[] _data; }

  void unions(int num1, int num2);
  int find(int elem);
};
#endif  // LIB_DISJOINT_SET_UNION_DSU_H_
