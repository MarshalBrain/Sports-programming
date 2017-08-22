#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n;
    pair <int, int> a[2000];
    cin >> n;
    long long ans = 0;
    for (int i = 0;i<n;i++)
    {
        cin >> a[i].second >> a[i].first;
        ans+=a[i].first;
    }
    sort(a,a+n);
    int i = 0,j = n-1,time = 0;
    while (a[i].first!=0)
    {
        time+=a[i].second;
        while (time>0 && j>i)
        {
            ans-=a[j].first;
            time--;
            a[j].first = 0;
            j--;
        }
        i++;
    }
    cout << ans;
    return 0;
}
