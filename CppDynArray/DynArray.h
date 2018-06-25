#pragma once

#include <string>
#include <initializer_list>

#include "utils.h"
#include "DynArrayIter.h"
typedef unsigned int uint;

template <typename T, uint init_max_size = 1>
class DynArray {
  T* mem;
  void reAlloc(uint new_max_size) {
    max_size = new_max_size;
    T* tmp = new T[max_size];
    copy_arr(mem, mem + size, tmp);
    delete[] mem;
    mem = tmp;
  }

public:
  uint max_size, size;
  using iterator = DynArrayIter<T, false>;
  using reverse_iterator = DynArrayIter<T, true>;

  DynArray(void) {
    size = 0;
    max_size = init_max_size;
    mem = new T[max_size];
  }
  DynArray(std::initializer_list<T> arr) {
    size = arr.size();
    max_size = init_max_size < size ? size * 2 : init_max_size;
    mem = new T[max_size];
    copy_arr(arr.begin(), arr.end(), mem);
  }
  void insert(T data, int in = -1) {
    uint idx = in;
    if (in == -1 || in > int(max_size)) idx = size;
    size++;
    for (uint i = size; i > idx; i--) mem[i] = mem[i - 1];

    mem[idx] = data;

    if (size >= max_size / 2) reAlloc(max_size * 2);
    if (size < max_size / 4) reAlloc(max_size / 2);
  }
  void remove(uint idx) {
    for (uint i = idx; i < size; i++) mem[i] = mem[i + 1];
    size--;

    if (size <= max_size / 4) reAlloc(max_size / 2);
    if (size > max_size / 2) reAlloc(max_size * 2);
  }
  iterator begin() {
    return mem;
  }
  iterator end() {
    return mem + size;
  }
  reverse_iterator rbegin() {
    return mem + size - 1;
  }
  reverse_iterator rend() {
    return mem - 1;
  }
  T at(uint i) {
    return mem[i];
  }
  T& operator[](uint idx) {
    return mem[idx];
  }
  ~DynArray() {
    delete[] mem;
  }
};
