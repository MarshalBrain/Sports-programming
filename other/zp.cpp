#include <bits\stdc++.h>
using namespace std;
const int siz = 1e5+5;
int l[2][siz];
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("salary_09_input.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(n);
    vector<int> f(n);
    for (int i = 0;i<n;i++) {cin >> a[i];b[i] = m;}
    for (int i = 0;i<n;i++)
    {
        if (a[i]>b[i]) f[i] = 1;
        if (a[i]<b[i]) f[i] = 0;
        if (a[i] == b[i]) f[i] = -1;
    }
    for (int i = 0;i<n;i++)
    {
        if (f[i] == -1) continue;
        if (f[i] == 1)
        {
            for (int j = i;j<n;j++)
                if (f[j] == 0)
                {
                    b[i]+=b[j]-a[j];
                    l[0][j] = b[j]-a[j];
                    l[1][j] = i+1;
                    b[j] = a[j];
                    if (b[i]>a[i]) {f[i] = 0;break;}
                    if (b[i] == a[i]) {f[i] = -1;break;}
                }
        }
        if (f[i] == 0)
        {
            for (int j = i;j<n;j++)
                if (f[j] == 1)
                {
                    b[j]+=b[i]-a[i];
                    l[0][i] = b[i]-a[i];
                    l[1][i] = j+1;
                    b[i] = a[i];
                    if (b[j]>a[j]) f[j] = 0;
                    if (b[j] == a[j]) f[j] = -1;
                    break;
                }
            f[i] = -1;
        }
    }
    for (int i = 0;i<n;i++)
        cout << l[1][i] << " " << l[0][i] << endl;
    return 0;
}

