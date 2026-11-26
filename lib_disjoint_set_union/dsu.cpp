// Copyright 2026 Ivan Trushkov
#include "../lib_disjoint_set_union/dsu.h"

DSU::DSU() {
  _size = 9;
  _data = new size_t[_size];
  _rank = new size_t[_size];
  for (int i = 0; i < _size; i++) {
    _data[i] = i;
  }

  for (int i = 0; i < _size; i++) {
    _rank[i] = 0;
  }
}
DSU::DSU(int size) {
  _size = size;
  _rank = new size_t[_size];
  _data = new size_t[_size];
  for (int i = 0; i < _size; i++) {
    _data[i] = i;
  }

  for (int i = 0; i < _size; i++) {
    _rank[i] = 0;
  }
}

void DSU::unions(int num1, int num2) {
        
}

int DSU::find(int elem) { //DO NOT WORKING, RECURSION IS UNSTOPABLE
  int i = _data[elem - 1];
  if (_data[i] != i) {
    find(i);
  } 
  return _data[i];
}
