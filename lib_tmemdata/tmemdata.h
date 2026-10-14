// Copyright 2026 Ivan Trushkov

#pragma once
#include <initializer_list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

#define MEM_STEP 15

template <typename vector_type>
class Vector;

template <typename vector_type>
class MemData {
    vector_type* _data;
    size_t _size;
    size_t _capacity;

public:
    explicit MemData(size_t size = 0);
    MemData(std::initializer_list<vector_type>);
    MemData(const vector_type*, size_t);
    MemData(const MemData&);
    MemData(MemData&&) noexcept;
    ~MemData();

    inline bool is_empty() const noexcept {
        return (_size == 0);
    }

    inline size_t get_size() const noexcept {
        return _size;
    }

    inline size_t get_capacity() const noexcept {
        return _capacity;
    }

    inline const vector_type* const get_data_const() const noexcept {
        return _data;
    }

    inline vector_type* const get_data_changeable() noexcept {
        return _data;
    }

    void set_memory(size_t) noexcept;
    void reset_memory(size_t size, size_t start_index = 0);
    void clear_memory() noexcept;
    void shrink_to_fit(size_t size, size_t start_index = 0);
    inline void set_size(size_t size) {
        if (size > _capacity) {
            throw std::invalid_argument("ERROR: Size is bigger than capacity!");
        } else {
            _size = size;
        }
    }

    MemData& operator=(const MemData&) noexcept;
    MemData& operator=(MemData&&) noexcept;
    bool operator==(const MemData&) const noexcept;

    template <typename vector_type>
    friend void quick_sort(MemData<vector_type>& md);
    template <typename vector_type>
    friend void shuffle(MemData<vector_type>&);
    friend class Vector<vector_type>;

private:
    inline bool is_full() const noexcept {
        return (_size >= _capacity);
    }
};

int calculate_capacity(size_t);
template <typename vector_type>
void quick_sort_recursive(vector_type* data, int left, int right);
template <typename vector_type>
int partition(vector_type* data, int left, int right);
