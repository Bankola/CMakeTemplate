// Copyright 2026 Trushkov Ivan
#include <cstddef>
#include <stdexcept>

template <class T>
class TStackOnMass {
  T* _data;
  std::size_t _size;
  int _top;

 public:
  explicit TStackOnMass(std::size_t size);
  TStackOnMass(const TStackOnMass& other);
  TStackOnMass& operator=(const TStackOnMass& other);
  ~TStackOnMass();

  bool is_empty() const noexcept;
  bool is_full() const noexcept;
  void push(const T& val);
  T pop();
  T top();
};
