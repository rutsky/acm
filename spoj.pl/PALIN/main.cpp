/* main.cpp
 * 5. The Next Palindrome
 * Vladimir Rutsky <altsysrq@gmail.com>
 * 22.05.2011
 */

#include <iostream>
#include <cassert>

using namespace std;

int main()
{
  int t;
  cin >> t;
  
  string str;
  str.reserve(1000000 + 1);
  for (; t > 0; --t)
  {
    str.resize(0);
    cin >> str;

    size_t const len = str.length();
    cassert(len > 0);
    cassert(str[0] > '0');
    if (str.length() == 1)
    {
      if (str[0] < '8')
        cout << str[0] + 1;
      else
        cout << "11";
    }
    else
    {
      size_t const half = len / 2;
      bool less(false);
      for (size_t i = 0; i < half; ++i)
      {
        if (str[len - half + i] < str[half - 1 - i])
        {
          less = true;
          break;
        }
        else if (str[len - half + i] > str[half - 1 - i])
          break;
      }

      if (less)
      {
        for (size_t i = 0; i < half; ++i)
          cout << str[i];
        if (len % 2 == 1)
          cout << str[half];
        for (size_t i = 0; i < half; ++i)
          cout << str[half - 1 - i];
      }
      else
      {
        if (len % 2 == 1 && str[half] < '9')
        {
          for (size_t i = 0; i < half; ++i)
            cout << str[i];
          cout << str[half] + 1;
          for (size_t i = 0; i < half; ++i)
            cout << str[half - 1 - i];
        }
        else
        {
          int non9idx = half - 1;
          for (; non9idx >= 0 && str[i] == '9'; --non9idx)
            ;
          if (non9idx >= 0)
          {
            for (size_t i = 0; i < non9idx; ++i)
              cout << str[i];
            cout << str[non9idx] + 1;
            for (size_t i = non9idx + 1; i < half; ++i)
              cout << '0';
            if (len % 2 == 1)
              cout << '0';
            for (size_t i = non9idx + 1; i < half; ++i)
              cout << '0';

            for (int i = non9idx - 1; i >= 0; --i)
              cout << str[i];
          }
          else
          {
            cout << '1';
            for (size_t i = 0; i < len - 1; ++i)
              cout << '0';
            cout << '1';
          }
        }
      }
    }

    cout << "\n";
  }
}

// vim: set ts=2 sw=2 et:
