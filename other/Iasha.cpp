#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  // put your code here
    int n,m,x,y;
    std:: cin >> n >> m >> x >> y;
    if (n<m) swap(n,m);
    int mi = 100500;
    mi = min(m-x,x);
    mi = min(y,mi);
    mi = min(n-y,mi);
    std::cout << mi;
  return 0;
}
