#include <bits\stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool f = 0;
    int ans1 = 0, ans2 = 0;
    int i = 0;
    while(i<s.size())
    {
        if (s[i] == '_' && i<s.size())
        {
            i++;
            continue;
        }
        if ((int)s[i]>=65 && (int)s[i]<=90 || (int)s[i]>=97 && (int)s[i]<=122)
        {
            int ch = 0;
            while ((int)s[i]>=65 && (int)s[i]<=90 || (int)s[i]>=97 && (int)s[i]<=122)
            {
                ch++;
                i++;
                if (i==s.size()) break;
            }
            if (ch>ans1) ans1 = ch;
            continue;
        }
        if (s[i] == '(' && i<s.size())
        {
            int ch = 0;
            i++;
            //cout << s[i] << "!" << endl;
            while (s[i]!=')' && i<s.size())
            {
                if (s[i] == '_')
                {
                    i++;
                    /*cout << s[i] << endl;*/
                    continue;
                }
               // cout << (int)s[i] << endl;
                if ((int)s[i]>=65 && (int)s[i]<=90 || (int)s[i]>=97 && (int)s[i]<=122)
                {
                    int ch = 0;
                    while ((int)s[i]>=65 && (int)s[i]<=90 || (int)s[i]>=97 && (int)s[i]<=122 )
                    {
                        if (i == s.size()) break;
                        i++;
                    }
                    ans2++;
                    continue;
                }
                if (i>=s.size()) break;
            }
        }
        i++;
    }
    cout << ans1 << " " << ans2;
    return 0;
}
