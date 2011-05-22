/* main.cpp
 * 11. Factorial
 * Vladimir Rutsky <altsysrq@gmail.com>
 * 22.05.2011
 *
 * Read problem.
 * Find solution.
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main()
{
  vector<size_t> pows;
  {
    int pow = 5;
    for (size_t i = 0; i < 14; ++i, pow *= 5)
      pows.push_back(pow);
  }

  size_t  T;
  assert(T >= 0);
  cin >> T;
  for (size_t idx = 0; idx < T; ++idx)
  {
    size_t N;
    cin >> N;

    assert(N >= 0);
    if (N < 10)
    {
      cout << "0";
    }
    else
    {
      size_t const ns = N / 5;
      
      size_t idx(1), zeroes(0);
      for (; idx < pows.size(); ++idx)
      {
        if (pows[idx] > N)
        {
          break;
        }
        else
        {
          zeroes += idx;
        }
      }
      
      cout << ns - idx + zeroes;
    }

    cout << "\n";
  }
}

// vim: set ts=2 sw=2 et:
