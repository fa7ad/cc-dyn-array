#include "dynarr.h"

using uint = unsigned int;
template <typename T, uint I>
void DynArr<T, I>::reAlloc(uint new_max_size) {
  max_size = new_max_size;
  T* tmp = new T[max_size];
  std::copy(mem, mem + size, tmp);
  delete[] mem;
  mem = tmp;
}

template <typename T, uint I>
DynArr<T, I>::DynArr() {
  size = 0;
  max_size = I;
  mem = new T[max_size];
}

template <typename T, uint I>
DynArr<T, I>::DynArr(std::initializer_list<T> arr) {
  size = arr.size();
  max_size = I < size ? size * 2 : I;
  mem = new T[max_size];
  std::copy(arr.begin(), arr.end(), mem);
}

template <typename T, uint I>
void DynArr<T, I>::insert(T data, int in) {
  uint idx = in;
  if (in == -1 || in > max_size) idx = size;
  size++;
  for (uint i = size; i > idx; i--) mem[i] = mem[i - 1];

  mem[idx] = data;

  if (size >= max_size / 2) reAlloc(max_size * 2);
  if (size < max_size / 4) reAlloc(max_size / 2);
}

template <typename T, uint I>
void DynArr<T, I>::remove(uint idx) {
  if (idx > size) throw DynArrException("Index out of bounds.");

  for (uint i = idx; i < size; i++) mem[i] = mem[i + 1];
  size--;

  if (size <= max_size / 4) reAlloc(max_size / 2);
  if (size > max_size / 2) reAlloc(max_size * 2);
}

template <typename T, uint I>
typename DynArr<T, I>::iterator DynArr<T, I>::begin() {
  return mem;
}

template <typename T, uint I>
typename DynArr<T, I>::iterator DynArr<T, I>::end() {
  return mem + size;
}

template <typename T, uint I>
typename DynArr<T, I>::reverse_iterator DynArr<T, I>::rbegin() {
  return mem + size - 1;
}

template <typename T, uint I>
typename DynArr<T, I>::reverse_iterator DynArr<T, I>::rend() {
  return mem - 1;
}

template <typename T, uint I>
T DynArr<T, I>::at(uint i) {
  return mem[i];
}

template <typename T, uint I>
T& DynArr<T, I>::operator[](uint idx) {
  if (idx >= max_size) throw DynArrException("Index out of bounds.");

  return mem[idx];
}

template <typename T, uint I>
DynArr<T, I>::~DynArr() {
  delete[] mem;
}
