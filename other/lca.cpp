#include <bits\stdc++.h>

using namespace std;
vector <int> g[MAXN];
const int MAXN = 1e5;
int timeIN(MAXN),timeOUT(MAXN)
int main()
{
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    dfs(1,1);
    return 0;
}
