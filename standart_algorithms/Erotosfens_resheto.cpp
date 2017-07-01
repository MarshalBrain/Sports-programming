#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector<bool> f(n+1, false);
    for (int i = 2;i<=n;i++)
        if (!f[i])
        {
            if (i*1ll*i <=n)
                for (int j = i*i;j<=n;j+=i) f[j] = true;
        }
    for (int i = 2;i<=n;i++) if (!f[i]) cout << i << " ";
    return 0;
}
