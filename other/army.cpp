#include <bits\stdc++.h>

using namespace std;
int a[100001];
int main()
{
    freopen("army.in","r",stdin);
    freopen("army.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 0;i<m;i++)
    {
        int ch,l,r;
        cin >> ch >> l >> r;
        if (ch == 0)
        {
            for (int j = l;j<=r;j++) a[j]++;
        }
        int ans = 1;
        if (ch == 1)
        {
            for (int j = l;j<=r;j++)
            {
                ans = (ans*a[j])%1000003;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
