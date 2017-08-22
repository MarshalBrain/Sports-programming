#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int main()
{
    int k2,k3,k5,k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int ans = min(min(k5,k6),k2)*256+min(k2-min(min(k5,k6),k2),k3)*32;
    cout << ans;
    return 0;
}
