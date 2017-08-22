#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <cstdio>

using namespace std;
int f[100000];
int main()
{
    string s;
    cin >> s;
    int f1 = 0, f2 = 0;
    for (int i = 0;i<s.size();i++) f[i] = 0;
    int i = 0;
    while (i<s.size())
    {
        if (s[i]=='A' && s[i+1] == 'B' && f[i] == f[i+1] && f[i] == 0 && f1 == 0)
        {
            f1 = 1;
            f[i] = 1;
            f[i+1] = 1;
            i+=2;
            //continue;
        }
        if (s[i]=='B' && s[i+1] == 'A' && f[i] == f[i+1] && f[i] == 0 && f2 == 0)
        {
            f2 = 1;
            f[i] = 1;
            f[i+1] = 1;
            i+=2;
        }
        else i++;
    }
    if (f1+f2 == 2) cout << "YES";
    else cout << "NO";
    return 0;
}
