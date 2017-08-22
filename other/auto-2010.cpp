#include <bits\stdc++.h>
#define pb push_back
using namespace std;

bool f[100000];
vector <vector<int> > a;
vector <int> c;
vector <int> an;
int ans = 0;
void dfs(int v)
{
    if (f[v] == 1)
    {
        return;
    }
    else
    {
        f[v] = 1;
        cout << v << " " << a << endl;
        for (int i = 0;i<(int)a[v].size();i++)
            if (f[i] == 0)
            {
       //         cout << "!" << endl;
                dfs(i);
            }
        cout << v << "!" <<  endl;
        ans+=c[v];
        an.pb(v+1);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0;i<n;i++)
    {
        int b;
        cin >> b;
        c.pb(b);
    }
    for (int i = 0;i<n;i++)
    {
        int k;
        a.pb(vector <int> ());
        cin >> k;
        for (int j = 0;j<k;j++)
        {
            int x;
            cin >> x;
            a[i].pb(x);
        }
    }
    dfs(0);
    cout << ans+c[0] << " " << an.size()+1 << endl;
    for (int i = 0; i<(int)an.size();i++) cout << an[i] << " ";
    cout << 1;
    return 0;
}
