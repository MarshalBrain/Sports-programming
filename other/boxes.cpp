#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
  // put your code h-ere
    int x,y,z,xx,yy,zz;
    cin >> x >> y >> z >> xx >> yy >> zz;
    if (x>z) swap(x,z);
    if (x>y) swap(x,y);
    if (y>z) swap(y,z);
    if (xx>zz) swap(xx,zz);
    if (xx>yy) swap(xx,yy);
    if (yy>zz) swap(yy,zz);
   // cout << x << y << z << xx << yy << zz << endl;
    if (x == xx && y == yy && z == zz)
    {
        cout << "Boxes are equal";
        return 0;
    }
    if (x<=xx && y<=yy && z<=zz) {
        cout << "The first box is smaller than the second one";
        return 0;
    }
    if (x>=xx && y>=yy && z>=zz) {
        cout << "The first box is large than the second one";
        return 0;
    }
    cout << "Boxes are incomparable";
  return 0;
}
