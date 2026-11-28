// Copyright 2026 Ivan Trushkov

#ifndef LIB_DISJOINT_SET_UNION_DSU_H_
#define LIB_DISJOINT_SET_UNION_DSU_H_

#include <stdexcept>
#include <vector>

class DSU {
 private:
  size_t* _data;
  size_t _size;
  size_t* _rank;

 public:
  DSU();
  explicit DSU(size_t size);
  ~DSU();

  void unions(int num1, int num2);
  int find(size_t elem);

  size_t get_size() const noexcept;
  const size_t* get_rank() const noexcept;
  const size_t* get_data() const noexcept;
};

#include "../lib_disjoint_set_union/dsu.cpp"
#endif  // LIB_DISJOINT_SET_UNION_DSU_H_
