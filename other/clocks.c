#include <iostream>
using namespace std;
int main() {
  int n;
    cin >> n;
    int ch = n / 3600;
    n%=3600;
    if (ch>23) ch-=24;
    int m = n / 60;
    cout << ch << ":";
    if (m<10) cout << 0 << m;
    else cout << m;
    cout << ":";
    n%=60;
     if (n<10) cout << 0 << n;
    else cout << n;
  return 0;
}
