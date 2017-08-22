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
const int MAXN = 2e9;

int main()
{
    long long n,m,k;
    cin >> n >> m >> k;
    long long x,s;
    vector<pair<long long, long long> > a(m+2);
    vector<pair<long long, long long> > b(k+2);
    cin >> x >> s;
    for (int i = 1;i<=m;i++) cin >> a[i].second;
    for (int i = 1;i<=m;i++) cin >> a[i].first;
    for (int i = 1;i<=k;i++) cin >> b[i].second;
    for (int i = 1;i<=k;i++) cin >> b[i].first;
    long long ans = 1LL * n*x;
    bool ff = 0;
    for (int i = 1;i<=m;i++)
    {
        int lm = s - a[i].first;
        if (lm < 0) continue;
        int l = 0, r = k+1;
        while (l<r)
        {
            int temp = (l+r+1)/2;
            if (b[temp].first<=lm) l = temp;else r = temp-1;
        }
        ans = min(ans,(long long)(n-b[l].second)*(long long)a[i].second);
    }
    cout << ans;
    return 0;
}
