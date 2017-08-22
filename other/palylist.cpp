#include <bits\stdc++.h>

using namespace std;
int a[5000],b[5000];
bool f[5000];
int main()
{
    int n,m,k = 0;
    cin >> n >> m;
    for (int i = 0;i<n;i++)
    {
        cin >> a[i];
        if (a[i] > m) f[i] = true;
        else
        {
            b[a[i]]++;
            k++;
        }
    }
    int sr = n/m,ost = n-k;
    int i = 1;
    int ans2 = 0;
    bool ff = 0;
    //cout << endl << ost << endl;
    for (int i = 1;i<=m;i++) if (b[i]<sr) {ff = 1;break;}
    if (ff == 0)
    {
        cout << sr <<  " " << 0 << endl;
        for (int i = 0;i<n;i++) cout << a[i] << " ";
        return 0;
    }
    while (ost!=0)
    {
        ff = 0;
        for (int j = 1;j<=m;j++) if (b[j]<sr) {ff = 1;break;}
        if (ff == 0)
        {
            cout << sr <<  " " << ans2 << endl;
            for (int j = 0;j<n;j++) cout << a[j] << " ";
            return 0;
        }
        if (b[i]<sr)
        {
            b[i]++;
            ost--;
            for (int j = 0;j<n;j++) if (f[j] == true) {a[j] = i;f[j] = false;ans2++;}
        }
        i++;
        if (i>m) i = 1;
    }
    i = 1;
    //cout << sr << endl;
    while (i<=m)
    {
        if (b[i]-sr>0)
        {
            for (int j = 1;j<=m;j++)
            {
                if (b[j]<sr)
                {
                    while (true)
                    {
                        if (b[i]-sr>0 && b[j]<sr)
                        {
                            b[j]++;b[i]--;
                            for (int l = 0;l<n;l++) if (a[l] == i) {a[l] = j;ans2++;break;}
                        }
                        else break;
                    }
                }
            }
        }
        i++;
    }
    int ans1 = 2147483647;
    for (int i = 1;i<=m;i++)
    {
        if (b[i]<ans1) ans1 = b[i];
    }
    cout << ans1 << " " << ans2 << endl;
    for (int i = 0;i<n;i++) cout << a[i] << " ";
    return 0;
}
