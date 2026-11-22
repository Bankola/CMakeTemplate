// Copyright 2026 Ivan Trushkov

#ifndef LIB_QUEUE_ON_MASS_QUEUE_ON_MASS_H_
#define LIB_QUEUE_ON_MASS_QUEUE_ON_MASS_H_

#include <cstddef>
#include <stdexcept>

template <class T>
class TQueueOnMass {
 private:
  T* _data;
  size_t _size;
  int _head;
  int _count;

 public:
  explicit TQueueOnMass(size_t size = 10);
  TQueueOnMass(const TQueueOnMass& other);
  ~TQueueOnMass();

  TQueueOnMass& operator=(const TQueueOnMass& other);

  inline bool is_empty() const noexcept;
  inline bool is_full() const noexcept;
  inline size_t size() const noexcept;

  inline void push(const T& val);
  inline T pop();
  inline T& front();
  inline T& back();
};

#include "queue.cpp"

#endif  // LIB_QUEUE_ON_MASS_QUEUE_ON_MASS_H_
