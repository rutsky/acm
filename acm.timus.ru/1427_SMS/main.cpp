/* main.cpp
 * 1427. SMS.
 * Vladimir Rutsky <altsysrq@gmail.com>
 * 18.08.2009
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
  int N, M;
  
  {
    string str;
    getline(cin, str);
    istringstream istr(str);
    istr >> N >> M;
  }
  
  string ad;
  getline(cin, ad);
  
  if (ad[ad.length() - 1] == '\n')
    ad.resize(ad.length() - 1);
    
  int const adlen = ad.length();
  
/*
On the 11-th of February, 2006 the contest "Timus Top Coders: First Challenge" is held!
*/
  
  //cout << N << " " << M << "\n'" << ad << "'\n";
  
  if (N >= M)
  {
    cout << (adlen / N) + (adlen % N != 0) << "\n";
  }
  else
  {
    int nLastPos(0);
    int nLastSms(0);
    for (int i = 0; i < adlen; ++i)
    {
      int j;
      for (j = 0; j < adlen && (isalpha(ad[i + j]) || ad[i + j] == ' ') && j < M; ++j)
        ;
        
      if (j > 0)
      {
        int const usingN = (i + j - nLastPos) / N + ((i + j - nLastPos) % N != 0);
        int const usingM = (i - nLastPos) / N + ((i - nLastPos) % N != 0) + 1;
        
        if (usingM <= usingN)
        {
          nLastPos = i + j + M;
          nLastSms += usingM;
        }
      }
    }
    
    cout << nLastSms + (adlen - nLastPos) / N + ((adlen - nLastPos) % N != 0) << "\n";
  }
}
