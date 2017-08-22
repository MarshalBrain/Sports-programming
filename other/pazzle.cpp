#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    cin >> k >> n;
    vector<int> a;
    for (int i = 1;i<=n;i++) {int temp;cin >> temp;a.push_back(temp);}
    sort(a.begin(),a.end());
    int i = 0, ans = 1e9;
    while (i<n-k)
    {
        ans = min(ans,a[i+k-1]-a[i]);
        i++;
    }
    cout << ans;
    return 0;
}
