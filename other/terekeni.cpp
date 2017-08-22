#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n ;
    string s,s1,s2;
    cin >> n >> s;
    int r = 0, b = 0;
    for (int i = 0;i<n;i++)
    {
        if (i%2 == 0)
        {
            s1+='r';s2+='b';
        }
        else
        {
            s2+='r';s1+='b';
        }
    }
    for (int i = 0;i<n;i++)
    {
        if (s1[i]!=s[i] && s[i] == 'r') r++;
        if (s1[i]!=s[i] && s[i] == 'b') b++;
    }
    int ans1 = 0,ans2 = 0;
    ans1+=max(r,b);
    r = 0;b = 0;
    for (int i = 0;i<n;i++)
    {
        if (s2[i]!=s[i] && s[i] == 'r') r++;
        if (s2[i]!=s[i] && s[i] == 'b') b++;
    }
    ans2+=max(r,b);
    cout << min(ans1,ans2) << endl;
    /*cout << s1 << endl;
    cout << s << endl;
    cout << s2 << endl;*/
    return 0;
}
