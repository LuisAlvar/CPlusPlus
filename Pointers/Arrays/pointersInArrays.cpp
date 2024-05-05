#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
Pointer arithmetic means adding an integer offset to an array pointer, yielding
a pointer that skips past the given number of elements.

The array/pointer duality law states that a[n] is identical to *(a + n),
where a is a pointer into an array and n is an interger offset. 



*/

double maximum(const double * a, int a_size)
{
  if(a_size == 0) return 0;
  double highest = *a;

  int count = a_size - 1;

  //since we already record a[0] as the highest, then we set *p to point to the address a[1]
  const double* p = a + 1;

  while (count > 0)
  {
    if (*p > highest)
    {
      highest = *p;
    }
    ++p;
    --count;
  }
  
  return highest;
}

double max(const double* a, int a_size)
{
  if (a_size == 0) return 0;
  double highest = *a;

  while (--a_size > 0)
  {
    if (*++a > highest)
    {
      highest = *a;
    }
  }

  return highest;
}

vector<double> minmax(const vector<double>&a )
{
  assert(a.size() > 0);
  vector<double> result(2);
  result[0] = a[0];
  result[1] = a[0];

  for (size_t i = 0; i < a.size(); i++)
  {
    if (a[i] < result[0]) result[0] = a[i];
    if (a[i] > result[1]) result[1] = a[i];
  }
  
  return result;
}

int main()
{

  double a[10] = {4,25,62,14,1,4,7,9,5,24};

  double* p = a;

  cout << *p  << " " << a[0] << "\n";

  if(a[3] == *(p + 3))
  {
    cout << "true\n";
  }

  if(a[0] == *(a + 0))
  {
    cout << "true\n";
  }

  cout << maximum(p, 10) << "\n";
  cout << max(p, 10) << "\n";

}