#include <bits\stdc++.h>

using namespace std;
int b[50];
int rasl(int m)
{
    int j = 0;
    int de = 2;
    while (m>1)
    {
        if (m%de == 0) {b[j] = de;j++;m/=de;}
        else de++;
    }
    return j;
}
int main()
{
    freopen("01.in","r",stdin);
    vector<int> a(1000);
    int n;
    cin >> n;
    int l = 0;
    bool f[1000];
    for (int i = 1;i<=n;i++)
    {
        fill(b,b+50,0);
        int k = rasl(i);
        fill(f,f+l,0);
        for (int i = 0;i<k;i++)
        {
            bool ff = 0;
            for (int j = 0;j<l;j++)
            {
                if (a[j] == b[i] && !f[j]) {f[j] = 1;ff = 1;break;}
            }
            if (ff == 0) {a[l] = b[i];l++;}
        }
    }
    long long ans = 1;
    for (int i = 0;i<l;i++)
    {
        ans*=a[i];
    }
    cout << ans;
    return 0;
}
