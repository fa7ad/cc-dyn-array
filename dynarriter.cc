#include "dynarriter.h"

template <typename P, bool b>
DynArrIter<P, b>::DynArrIter(P* x) : p(x) {}

template <typename P, bool b>
DynArrIter<P, b>::DynArrIter(const DynArrIter<P, b>& d) : p(d.p) {}

template <typename P, bool b>
DynArrIter<P, b>& DynArrIter<P, b>::operator++() {
  p += !b ? 1 : -1;
  return *this;
}

template <typename P, bool b>
DynArrIter<P, b> DynArrIter<P, b>::operator++(int) {
  DynArrIter<P, b> tmp(*this);
  operator++();
  return tmp;
}

template <typename P, bool b>
DynArrIter<P, b>& DynArrIter<P, b>::operator--() {
  p += !b ? -1 : 1;
  return *this;
}

template <typename P, bool b>
DynArrIter<P, b> DynArrIter<P, b>::operator--(int) {
  DynArrIter<P, b> tmp(*this);
  operator--();
  return tmp;
}

template <typename P, bool b>
bool DynArrIter<P, b>::operator==(const DynArrIter<P, b>& r) const {
  return p == r.p;
}

template <typename P, bool b>
bool DynArrIter<P, b>::operator!=(const DynArrIter<P, b>& r) const {
  return p != r.p;
}

template <typename P, bool b>
P& DynArrIter<P, b>::operator*() {
  return *p;
}

template <typename P, bool b>
ptrdiff_t DynArrIter<P, b>::operator-(const DynArrIter<P, b>& r) const {
  return p - r.p;
}

template <typename P, bool b>
DynArrIter<P, b> DynArrIter<P, b>::operator-(const ptrdiff_t r) const {
  return p - r;
}
