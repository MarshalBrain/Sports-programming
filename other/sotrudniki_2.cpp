#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1;i<=n;i++) cin >> a[i];
    int ma = 0;
    for (int i = 1;i<=n;i++)
    {
        int ch = a[i],siz = 1;
        while (ch!=-1)
        {
            ch = a[ch];
            siz++;
        }
        if (siz>ma) ma = siz;
    }
    cout << ma;
    return 0;
}


