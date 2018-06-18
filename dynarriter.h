#ifndef DYNARRITER_HH
#define DYNARRITER_HH

template <typename P, bool back = false>
class DynArrIter : public std::iterator<std::bidirectional_iterator_tag, P*> {
  P* p;

 public:
  DynArrIter(P* x);
  DynArrIter(const DynArrIter& d);
  DynArrIter& operator++();
  DynArrIter operator++(int);
  DynArrIter& operator--();
  DynArrIter operator--(int);
  bool operator==(const DynArrIter& r) const;
  bool operator!=(const DynArrIter& r) const;
  P& operator*();
  ptrdiff_t operator-(const DynArrIter& r) const;
  DynArrIter operator-(const ptrdiff_t r) const;
};

#endif  // DYNARRITER_HH
