#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
const int maxN = 1e7;
int l[maxN];
int main()
{
    int n;
    cin >> n;
    vector<int> pr;
    for (int i = 2;i<=n;i++)
    {
        if (l[i] == 0)
        {
            l[i] = i;
            pr.push_back(i);
        }
        for (int j = 0;j<(int)pr.size() && pr[j]<=l[i] && i*pr[j]<=n;j++) l[i*pr[j]] = pr[j];
    }
    for (int i = 0;i<(int)pr.size();i++) cout << pr[i] << " ";

    return 0;
}
