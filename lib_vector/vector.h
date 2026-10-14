#pragma once
#include <iostream>
#include<cstdlib>
#include "../lib_tmemdata/tmemdata.h"

template<typename vector_type>
class Vector {
    MemData<vector_type> _mem;
    size_t _front;
    size_t _back;

public:
    Vector(size_t size = 0);
    Vector(std::initializer_list<vector_type>);
    Vector(vector_type*, size_t);
    Vector(const Vector<vector_type>&);
    Vector(Vector<vector_type>&&) noexcept;
    ~Vector() = default;

    inline bool is_empty() const noexcept {
        return _mem.is_empty();
    }
    inline bool is_full() const noexcept {
        return _mem.is_full();
    }

    inline size_t get_size() const noexcept {
        return _mem._size;
    }
    inline size_t get_capacity() const noexcept {
        return _mem._capacity;
    }
    inline vector_type get_front() const {
        if (_mem._size != 0) {
            return (_mem._data)[_front];
        }
        else {
            throw std::logic_error("ERROR: Vector is empty! Can't get front");
        }
    }
    inline vector_type get_back() const {
        if (_mem._size != 0) {
            return (_mem._data)[_back];
        }
        else {
            throw std::logic_error("ERROR: Vector is empty! Can't get back");
        }
    }
    inline MemData<vector_type> get_mem_copy() const noexcept {
        return _mem;
    }
    inline const MemData<vector_type>& get_mem_original() const noexcept {
        return _mem;
    }

    inline vector_type& front_ref() {
        if (_mem._size != 0) {
            return (_mem._data)[_front];
        }
        else {
            throw std::logic_error("ERROR: Vector is empty! Can't set front");
        }
    }
    inline vector_type& back_ref() {
        if (_mem._size != 0) {
            return (_mem._data)[_back];
        }
        else {
            throw std::logic_error("ERROR: Vector is empty! Can't set back");
        }
    }

    void push_front(vector_type) noexcept;
    void push_front_many(vector_type*, size_t) noexcept;
    void push_back(vector_type) noexcept;
    void push_back_many(vector_type*, size_t) noexcept;	
    void insert(vector_type, size_t);
    void insert_many(vector_type*, size_t, size_t);

    void pop_front();
    void pop_front_many(size_t);
    void pop_back();
    void pop_back_many(size_t);
    void erase(size_t);
    void erase_many(size_t, size_t);
    void shrink_to_fit();

    Vector<vector_type>& operator=(const Vector<vector_type>&) noexcept;
    Vector<vector_type>& operator=(Vector<vector_type>&&) noexcept;
    vector_type operator[](size_t) const noexcept;
    vector_type& operator[](size_t) noexcept;

    template <typename vector_type>
    friend std::ostream& operator<< (std::ostream&, const Vector<vector_type>&);
    template <typename vector_type>
    friend std::istream& operator>> (std::istream&, Vector<vector_type>&);
    template <typename vector_type>
    friend void quick_sort(Vector<vector_type>&);
    template <typename vector_type>
    friend void shuffle(Vector<vector_type>&);

private:
    inline size_t get_mem_index(size_t i) const {
        return ((i + _front) % _mem._capacity);
    }
};