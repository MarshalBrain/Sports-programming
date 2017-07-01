#include <iostream>
#include <vector>

using namespace std;

struct ed
{
    int a,b,cost;
};
int main()
{
    int n,m;
    cin >> n >> m;
    vector<ed> e(m+3);
    for (int j = 1;j<=m;j++) cin >> e[j].a >> e[j].b >> e[j].cost;
    vector<int> d(n+3,30000);
    d[1] = 0;
    for (int i = 1;i<n;i++)
    {
        bool f = 0;
        for (int j = 1;j<=m;j++)
        {
            if (d[e[j].a]<30000)
                if (d[e[j].b]>d[e[j].a]+e[j].cost) {d[e[j].b] = d[e[j].a] + e[j].cost;f = 1;}
        }
        if (!f) break;
    }
    for (int j = 1;j<=n;j++) cout << d[j] << " ";
    return 0;
}
