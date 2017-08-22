#include <bits\stdc++.h>

using namespace std;
const int maxN = 2e2+3;
map<string, int> a;
vector<int> b(maxN);
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    a["polycarp"] = 1;
    int l = 2;
    b[1] = 0;
    for (int i = 0;i<n;i++)
    {
        string s1,s,s2;
        cin >> s1 >> s >> s2;
        for (int j = 0;j<s1.size();j++)
        {
            if ((int)s1[j]>64 && (int)s1[j]<91) s1[j] = (char)((int)s1[j]+32);
        }
        for (int j = 0;j<s2.size();j++)
        {
            if ((int)s2[j]>64 && (int)s2[j]<91) s2[j] = (char)((int)s2[j]+32);
        }
        a[s1] = l;
        b[l] = a[s2];
        l++;
    }
    int ans = 0;
    //for (int i = 1;i<l;i++) cout << b[i] << " ";
    for (int i = 1;i<l;i++)
    {
        int gl = 1, ch = b[i];
        while (ch!=0)
        {
            gl++;
            //cout << gl << " ";
            ch = b[ch];
        }
        ans = max(gl,ans);
    }
    cout << ans;
    return 0;
}
