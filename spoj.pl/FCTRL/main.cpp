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
    int pow = 1;
    for (size_t i = 0; i < 14; ++i, pow *= 5)
      pows.push_back(pow);
  }

  size_t T;
  cin >> T;
  for (size_t idx = 0; idx < T; ++idx)
  {
    size_t N;
    cin >> N;

    if (N < 5)
    {
      cout << "0";
    }
    else
    {
      size_t zeroes = 0;
      for (size_t nn = N; nn >= 5; nn /= 5)
        zeroes += nn / 5;

      cout << zeroes;
    }

    cout << "\n";
  }
}

// vim: set ts=2 sw=2 et:
