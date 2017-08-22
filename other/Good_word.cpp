#include <iostream>
#include <string>
#include <vector>
#define pb push_back

using namespace std;
int f[26];
int main()
{
    int n ;
    string s;
    cin >> s;
    n = s.size();

    for (int i = 0;i<26;i++)
    {
        if (s[i]!='?') f[(int)s[i]-65]++;
    }
    bool ff = 0;
    for (int i = 0;i<25;i++)
    {
        if (f[i]>1)
        {
            ff++;
            break;
        }
    }
    if (ff == 0)
    {
        for (int i = 0;i<26;i++)
        {
            if (f[i] == 0)
            {
                for (int j = 0;j<26;j++)
                {
                    if (s[j]=='?') s[j] = (char)i+65;
                }
            }
        }
        for (int i = 0;i<n;i++)
        {
            if (s[i] == '?') s[i] = 'B';
        }
        cout << s;
        return 0;
    }
    int i = 1, j = 26;
    while (j<n)
    {
        if (s[i-1]!='?') f[(int)s[i-1]-65]--;
        if (s[j]!='?') f[(int)s[j]-65]++;
        ff = 0;
        for (int k = 0;k<26;k++)
        {
            if (f[k]>1)
            {
                ff++;
                break;
            }
        }
        if (ff == 0)
        {
            for (int k = 0;k<26;k++)
            {
                if (f[k] == 0)
                {
                    for (int l = i;l<=j;l++)
                    {
                        if (s[l]=='?') s[l] = (char)k+65;
                    }
                }
            }
            for (int k = 0;k<n;k++)
            {
                if (s[k] == '?') s[k] = 'B';
            }
            cout << s;
            return 0;
        }
        i++;
        j++;
    }
    cout << -1;
    return 0;
}
