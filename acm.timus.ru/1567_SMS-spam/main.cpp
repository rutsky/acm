/* main.cpp
 * 1567. SMS-spam.
 * Vladimir Rutsky <altsysrq@gmail.com>
 * 18.08.2009
 */

#include <iostream>

int main()
{
  int cost(0);
  
  char c;
  while (std::cin.get(c))
  {
    if (c >= 'a' && c <= 'z')
      cost += 1 + (c - 'a') % 3;
    else
    {
      switch(c)
      {
      case '.': 
        cost += 1;
        break;
      case ',': 
        cost += 2;
        break;
      case '!': 
        cost += 3;
        break;
      case ' ': 
        cost += 1;
        break;
      default:
        throw "";
      }
    }
  }
  
  std::cout << cost << "\n";
}
