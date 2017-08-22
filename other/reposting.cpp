#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map <string, string> a;
    for (int i = 0;i<n;i++)
    {
        string n1,n2,tmp;
        cin >> n1 >> tmp >> n2;
        for (int j = 0;j<n1.size();j++)
        {
            n1[j] = tolower(n1[j]);
        }
        for (int j = 0;j<n2.size();j++)
        {
            n2[j] = tolower(n2[j]);
        }
        a[n1] = n2;
    }
    map<string, string> :: iterator it = a.end();
    map<string, int> ans;
    map<string, int> :: iterator jt = ans.end();
    while (it!=a.begin())
    {
        jt = max(ans[a[it]]+1,ans[jt]);
        jt--;
        it--;
    }
    cout << ans[a.begin()];
    return 0;
}
