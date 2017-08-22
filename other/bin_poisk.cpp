#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int maxN = 1e6+6;
vector<int> a(maxN),b(maxN);
int n,m;
int bin_search(int k)
{
    int l = 1;
    int r = n;
    while (l<r-1)
    {
        int m = (l+r)/2;
        if (a[m]<k) l = m;
        else r = m;
    }
    if (abs(a[l]-k)<=abs(a[r]-k)) return a[l];
    else return a[r];
}
int main()
{
    cin >> n >> m;
    for (int i = 1;i<=n;i++) cin >> a[i];
    for (int i = 1;i<=m;i++) cin >> b[i];
    for (int i = 1;i<=m;i++)
    {
        cout << bin_search(b[i]) << endl;
    }

    return 0;
}
