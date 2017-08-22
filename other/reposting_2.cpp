#include <bits\stdc++.h>

using namespace std;

int main()
{
//    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    map <string, int> mp;
    vector <int> a(n+10);
    mp["polycarp"] = 1;
    a[mp["polycarp"]] = 0;
    string n1,n2,tmp;
    int k = 2;
    for (int i = 1;i<=n;i++)
    {
        cin >> n1 >> tmp >> n2;
        for (int j = 0;j<n1.size();j++)
        {
            n1[j] = tolower(n1[j]);
        }
        for (int j = 0;j<n2.size();j++)
        {
            n2[j] = tolower(n2[j]);
        }
        mp[n1] = i+1;
        a[mp[n1]] = mp[n2];
    }
   /* for (int i = 1;i<=n+1;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;*/
    vector <int> ans(n+10);
    int maxi = 0;
    for (int i = n+1;i>=1;i--)
    {
        ans[a[i]] = max(ans[i]+1,ans[a[i]]);
        maxi = max(maxi,ans[i]+1);
    }
    cout << maxi;
    /*for (int i = 0;i<n;i++)
        cout << ans[i] << " ";*/
    return 0;
}
