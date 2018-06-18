#ifndef DYNARRITER_HH
#define DYNARRITER_HH

template <typename P, bool back = false>
class DynArrIter : public std::iterator<std::bidirectional_iterator_tag, P*> {
  P* p;

 public:
  DynArrIter(P* x) : p(x) {}
  DynArrIter(const DynArrIter& d) : p(d.p) {}
  DynArrIter& operator++() {
    p += !back ? 1 : -1;
    return *this;
  }
  DynArrIter operator++(int) {
    DynArrIter tmp(*this);
    operator++();
    return tmp;
  }
  DynArrIter& operator--() {
    p += !back ? -1 : 1;
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
  DynArrIter operator-(const ptrdiff_t r) const { return p - r; }
};

#endif  // DYNARRITER_HH
