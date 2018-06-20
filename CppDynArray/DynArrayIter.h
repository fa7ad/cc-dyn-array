#pragma once

#include <iterator>

template <typename P, bool backward = false>
class DynArrayIter : std::iterator<std::bidirectional_iterator_tag, P*> {
  P* p;

public:
  DynArrayIter(P* x) : p(x) {}
  DynArrayIter(const DynArrayIter& d) : p(d.p) {}
  DynArrayIter& operator++() {
    p += backward ? -1 : 1;
    return *this;
  }
  DynArrayIter operator++(int) {
    DynArrayIter tmp(*this);
    operator++();
    return tmp;
  }
  DynArrayIter& operator--() {
    p += backward ? 1 : -1;
    return *this;
  }
  DynArrayIter operator--(int) {
    DynArrayIter tmp(*this);
    operator--();
    return tmp;
  }
  bool operator==(const DynArrayIter& r) const {
    return p == r.p;
  }
  bool operator!=(const DynArrayIter& r) const {
    return p != r.p;
  }
  P& operator*() {
    return *p;
  }
  long int operator-(const DynArrayIter& r) const {
    return p - r.p;
  }
  DynArrayIter operator-(const long int r) const {
    return p - r;
  }
};
