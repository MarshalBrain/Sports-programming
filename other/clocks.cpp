#include <iostream>
using namespace std;
int main() {
  string s;
    cin >> s;
  if (s.size()<4)
  {
      if (s.size() == 3) s = "0"+s;
      if (s.size() == 2) s = "00" + s;
      if (s.size() == 1) s = "000" + s;
  }
    bool f = false;
  int i = 0, j = 3;
    while (i<j)
    {
    if (s[i]!=s[j]) f = true;
    i++;j--;
    }
    if (f == false) cout << 1;
    else cout << 0;
  return 0;
}
