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
  
  int const inf = 1000000000;
  vector<int> nsms(110010, inf);
  nsms[0] = 0;
  
  for (int i = 0; i < adlen; ++i)
  {
    for (int j = 1; j <= N; ++j)
      nsms[i + j] = std::min(nsms[i + j], nsms[i] + 1);
      
    for (int j = 1; j <= M && (isalpha(ad[i + j - 1]) || ad[i + j - 1] == ' '); ++j)
      nsms[i + j] = std::min(nsms[i + j], nsms[i] + 1);
  }
  
  int const minsms = nsms[adlen];
  
  //std::copy(nsms.begin(), nsms.begin() + ad.length() + std::max(N, M), ostream_iterator<int>(cout, " "));
  
  std::cout << minsms << "\n";
}
