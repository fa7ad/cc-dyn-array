#ifndef DYNARR_HH
#define DYNARR_HH

#include <vector>
using uint = unsigned int;

template <class P>
class DynArrIter : public std::iterator<std::bidirectional_iterator_tag, P*> {
  P* p;

 public:
  DynArrIter(P* x) : p(x) {}
  DynArrIter(const DynArrIter& d) : p(d.p) {}
  DynArrIter& operator++() {
    ++p;
    return *this;
  }
  DynArrIter operator++(int) {
    DynArrIter tmp(*this);
    operator++();
    return tmp;
  }
  DynArrIter& operator--() {
    --p;
    return *this;
  }
  DynArrIter operator--(int) {
    DynArrIter tmp(*this);
    operator--();
    return tmp;
  }
  bool operator==(const DynArrIter& r) const { return p == r.p; }
  bool operator!=(const DynArrIter& r) const { return p != r.p; }
  P& operator*() { return *p; }
  ptrdiff_t operator-(const DynArrIter& r) const { return p - r.p; }
  template <class T>
  DynArrIter operator-(const T r) const {
    return p - r;
  }
};

template <class T, uint init_max_size = 1>
class DynArr {
  T* mem;
  void reAlloc(uint new_max_size) {
    max_size = new_max_size;
    T* tmp = new T[max_size];
    std::copy(mem, mem + max_size, tmp);
    delete[] mem;
    mem = tmp;
  }

 public:
  uint max_size, size;
  using iterator = DynArrIter<T>;
  using reverse_iterator = iterator;
  DynArr() {
    size = 0;
    max_size = init_max_size;
    mem = new T[max_size];
  }
  DynArr(std::vector<T> arr) {
    size = arr.end() - arr.begin();
    max_size = init_max_size < size ? size * 2 : init_max_size;
    mem = new T[max_size];
    std::copy(arr.begin(), arr.end(), mem);
  }
  void insert(T data, int in = -1) {
    uint idx = in;
    if (in == -1) idx = size;
    size++;
    for (uint i = max_size; i > idx; i--) mem[i] = mem[i - 1];

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
  iterator begin() { return mem; }
  iterator end() { return mem + size; }
  reverse_iterator rbegin() { return end() - 1; }
  reverse_iterator rend() { return begin() - 1; }
  T at(uint i) { return mem[i]; }
  T& operator[](uint idx) { return mem[idx]; }
  ~DynArr() { delete[] mem; }
};

#endif  // DYNARR_HH
