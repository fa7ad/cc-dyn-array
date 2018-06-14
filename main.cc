#include <iostream>
#include "dynarr.hh"

using namespace std;

int main () {
  // support for all primitive types using templates
  DynArr<double> da;
  // insert at end
  da.insert(100);
  da.insert(106.2);
  // insert at specific index
  da.insert(105.4, 1);
  // insert at end
  da.insert(107);
  da.insert(108.9);
  // insert at head
  da.insert(255.2, 0);
  // remove from specific index
  da.remove(4);
  // index auto-updates
  da.remove(4);
  // replace/update at specific index
  // Note: this does not auto update container size
  da[0] = 103.3;
  da[1] = 104.2;

  // iterators (like STL, except this is without std::iterator class)
  for (double* it = da.begin(); it != da.end(); it++)
    cout << *it << endl;

  // size and max_size (also like STL)
  cout << "max_size: " << da.max_size << " size: " << da.size;

  // accessor function (like STL, again)
  cout << endl << da.at(0) << endl;
  return 0;
}
