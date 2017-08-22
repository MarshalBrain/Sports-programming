#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ku = 0, na = 0;
    for (int i = 0;i<n;i++)
    {
        if (s[i]=='G') ku = i;
        if (s[i] == 'T') na = i;
    }
    int su = abs(ku-na);
    if (su%k != 0) {cout << "NO";return 0;}
    if (ku<na)
    {
          int j = ku;
          while (j<n && s[j]!='T')
          {
              //cout << j << endl;
              j+=k;
              if (s[j] == '#') {cout << "NO";return 0;}
              if (s[j] == 'T') {cout << "YES";return 0;}
              if (j>=n) break;
          }
          if (j>=n) cout << "NO";
    }
    else
    {
        int j = ku;
        while (j<n && s[j]!='T')
            {
                //cout << j << endl;
                j-=k;
                if (s[j] == '#') {cout << "NO";return 0;}
                if (s[j] == 'T') {cout << "YES";return 0;}
                if (j>=n) break;
            }
            if (j<0) cout << "NO";
    }

    return 0;
}
