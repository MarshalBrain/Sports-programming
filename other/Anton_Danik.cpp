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
    int n;
    cin >> n;
    int a = 0,d = 0;
    for (int i = 0;i<n;i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'A') a++;
        else d++;
    }
    if (a>d) cout << "Anton";
    if (d>a) cout << "Danik";
    if (d == a) cout << "Friendship";
    return 0;
}
