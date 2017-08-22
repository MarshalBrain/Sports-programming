#include <bits\stdc++.h>

using namespace std;
bool f[3000000];
int a[2000000];
int main()
{
    freopen("2.in","r",stdin);
    int n,m;
    cin >> n >> m;
    int j = 1;
    for (int i = 2;i<=n*2;i++)
    {
        a[i] = j;
        if (i<=n) j++;
        else j--;
    }
    //for (int i = 2;i<=2*n;i++) cout << a[i] << " ";
    int ans = n*n;
    for (int i = 0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        if (f[x-y+n] == 0)
        {
            f[x-y+n] = 1;
            ans-=a[x+y];
            a[x+y] = 0;
            int temp = x+y;
            int xx = x, yy = y;
            while (temp>0 && xx>0 && yy > 0)
            {
                if (a[temp]!=0)
                {
                    a[temp]--;
                    ans--;
                }
                xx--;yy--;
                temp-=2;
            }
            temp = x+y+2;
            x++;y++;
            while (x<=n && y<=n)
            {
                if (a[temp]!=0)
                {
                    a[temp] --;
                    ans--;
                    temp+=2;
                }
                x++;y++;
            }
        }
        else
        {
      //      cout << "!";
            ans-=a[x+y];
            a[x+y] = 0;
        }
    }
    cout << ans;
    return 0;
}
