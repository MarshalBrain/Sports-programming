#include <bits\stdc++.h>

using namespace std;
const int siz = 5e3+1;
int a[siz],f[siz];
int main()
{
    freopen("12.in","r",stdin);
    int n,l;
    cin >> l >> n;
    int ch = 0,ans = 0;
    char s[15];
    for (int i = 0;i<n;i++)
    {
        cin >> a[i];
        itoa(a[i],s,10);
        ch+=strlen(s)+1;
    }
    ans = ch;
    sort(a,a+n);
    int i = 0;
    while (i<n)
    {
        if (a[i+1] == a[i]+1)
        {
            int j = i;
            while (a[i+1] == a[i]+1 && i<n)
            {
                itoa(a[i],s,10);
                i++;
                ch+=strlen(s)+1;
            }
            itoa(a[i],s,10);
           // cout << i << " " << j << endl;
            ch+=strlen(s)+1;
            if (i-j>1)
            {
                f[j] = 1;
                f[i] = 2;
                ans-=ch;
                itoa(a[j],s,10);
                ans+=strlen(s)+2;
                itoa(a[i],s,10);
                ans+=strlen(s)+1;
            }
        }
        i++;
    }
    i = 0;
    cout << "[";
    while (i<n)
    {
        if (f[i] == 1)
        {
            cout << a[i] << "..";
            while (f[i]!=2) i++;
            cout << a[i] << ",";
            i++;
        }
        else if (i!=n-1) {cout << a[i] << ",";i++;}
             else {cout << a[i] << "]";i++;}
    }
    return 0;
}
