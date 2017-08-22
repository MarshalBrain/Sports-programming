#include <bits\stdc++.h>

using namespace std;
const int MAXN = 2e9;
const int siz = 1e5;
int a[siz],b[siz];
int main()
{
    int n;
    cin >> n;
    int l = 0,r = 0;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
        l+=a[i];
        r+=b[i];
    }
    int ans = 0,ma = abs(r-l);

    for (int i = 1;i<=n;i++)
    {
        if (abs(l-2*a[i]+2*b[i]-r)>ma) {ma = abs(l-2*a[i]+2*b[i]-r);ans = i;}
    }
    cout << ans;
    return 0;
}
