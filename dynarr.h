#ifndef DYNARR_HH
#define DYNARR_HH

#include "dynarriter.cc"
using uint = unsigned int;

template <typename T, uint init_max_size = 1>
class DynArr {
  T* mem;
  void reAlloc(uint new_max_size);

 public:
  uint max_size, size;
  using iterator = DynArrIter<T, false>;
  using reverse_iterator = DynArrIter<T, true>;
  DynArr();
  DynArr(std::initializer_list<T> arr);
  void insert(T data, int in = -1);
  void remove(uint idx);
  iterator begin();
  iterator end();
  reverse_iterator rbegin();
  reverse_iterator rend();
  T at(uint i);
  T& operator[](uint idx);
  ~DynArr();
};

struct DynArrException : public std::exception {
  std::string message;
  DynArrException(std::string m) : message(m) {}
  const char* what() { return message.c_str(); }
};

#endif  // DYNARR_HH
