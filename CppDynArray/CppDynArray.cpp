#include "stdafx.h"

#include <iostream>
#include "DynArray.h"

using namespace std;

int main(void) {
  // support for all primitive types using templates
  // support for brace initializer
  DynArray<double> da({ 1, 200.3, 3, 5 });
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
  // Note: this gives direct access to the underlying C-style array
  da[0] = 103.3;
  da[1] = 104.2;

  // iterators (like STL)
  for (DynArray<double>::iterator it = da.begin(); it != da.end(); it++)
    cout << *it << endl;

  cout << endl << "Now, reverse!" << endl;
  for (DynArray<double>::reverse_iterator r = da.rbegin(); r != da.rend(); r++)
    cout << *r << endl;

  // accessor function (like STL, again)
  cout << endl << da.at(0) << endl;

  // size and max_size (also like STL)
  cout << "max_size: " << da.max_size << " size: " << da.size << endl;

	return 0;
}

