#include <bits\stdc++.h>

using namespace std;

char a[9][9];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ans = 0;
    for (int i = 0;i<8;i++)
    {
        for (int j = 0;j<8;j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0;i<8;i++)
        for(int j = 0;j<8;j++)
        {
            if (a[i][j] == 'B') ans+=1;
        }
    cout << ans << endl;
    if ((ans % 8)!=0) cout << ans/8+1;
    else cout << ans/8;
    return 0;
}
