// Copyright 2026 Ivan Trushkov
#include "../lib_disjoint_set_union/dsu.h"

DSU::DSU() {
  _size = 9;
  _data = new size_t[_size];
  _rank = new size_t[_size];
  for (size_t i = 0; i < _size; i++) {
    _data[i] = i;
  }

  for (size_t i = 0; i < _size; i++) {
    _rank[i] = 0;
  }
}
DSU::DSU(size_t size) {
  _size = size;
  _rank = new size_t[_size];
  _data = new size_t[_size];
  for (size_t i = 0; i < _size; i++) {
    _data[i] = i;
  }

  for (size_t i = 0; i < _size; i++) {
    _rank[i] = 0;
  }
}

DSU::~DSU() {
  delete[] _rank;
  delete[] _data;
}

size_t DSU::get_size() const noexcept { return _size; }

const size_t* DSU::get_rank() const noexcept { return _rank; }

const size_t* DSU::get_data() const noexcept { return _data; }

void DSU::unions(int num1, int num2) { return; }

int DSU::find(size_t elem) {
  if (elem == 0 || elem > _size) {
    throw std::logic_error("Out of range!");
  }
  elem--;
  if (_data[elem] == elem) {
    return elem + 1;
  } else {
    size_t tmp = find(_data[elem] + 1) - 1;
    _data[elem] = tmp;
    return tmp + 1;
  }
}
