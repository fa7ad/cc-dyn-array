#ifndef DYNARR_HH
#define DYNARR_HH

typedef unsigned int uint;

template <class T, uint init_max_size = 1>
class DynArr {
  T* mem;
  void reAlloc(uint new_max_size) {
    max_size = new_max_size;
    T* tmp = new T[max_size];
    for (uint i = 0; i < max_size; i++)
      tmp[i] = mem[i];
    delete []mem;
    mem = tmp;
  }
public:
  uint max_size, size;
  DynArr() {
    size = 0;
    max_size = init_max_size;
    mem = new T[max_size];
  }
  void insert(T data, int i = -1) {
    uint idx = i;
    if (i == -1)
      idx = size;
    size++;
    for (uint i = max_size; i > idx; i--)
      mem[i] = mem[i-1];

    mem[idx] = data;

    if(size >= max_size/2)
      reAlloc(max_size*2);
    if(size < max_size/4)
      reAlloc(max_size/2);
  }
  void remove(uint idx) {
    for (uint i = idx; i < size; i++)
      mem[i] = mem[i+1];
    size--;

    if(size <= max_size/4)
      reAlloc(max_size/2);
    if(size > max_size/2)
      reAlloc(max_size*2);
  }
  T* begin() {
    return mem;
  }
  T* end() {
    return mem + size;
  }
  T at(uint i) {
    return mem[i];
  }
  T& operator[] (uint idx) {
    return mem[idx];
  }
  ~DynArr () {
    delete []mem;
  }
};

#endif // DYNARR_HH
