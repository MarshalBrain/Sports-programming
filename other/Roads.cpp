#include <iostream>
#include <stdlib.h>

using namespace std;
bool f[1001];
int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        f[x]=1;
        f[y]=1;
    }
    cout << n-1 << endl;
    for (int i = 1;i<=n;i++)
        if (f[i] == 0)
        {
            for (int j = 1;j<=n;j++)
            {
                if (j == i) continue;
                cout << i << " " << j << endl;
            }
            return 0;
        }
    return 0;
}
