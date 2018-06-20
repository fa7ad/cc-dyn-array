#pragma once

template <typename T, typename D>
void copy_arr(T* start, T* end, D* target) {
  T* it;
  D* dest = target;
  for (it = start; it != end; it++) {
    *(dest) = *it;
    dest++;
  }
}