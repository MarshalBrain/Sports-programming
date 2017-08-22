#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pb push_back
using namespace std;

int main()
{
    vector<int> tem;
    vector<int> a;
    int n,m;
    cin >> n >> m;
    int temp;
    for (int i = 0;i<m;i++)
    {
        cin >> temp;
        tem.pb(temp);
    }
    sort(tem.begin(),tem.end());


    for (int i = 1;i<m;i++)
    {
        a.pb(tem[i]-tem[i-1]);
    }
    int j = 0;
    int ans = 2147483647;
   /* for (int i = 0;i<a.size();i++) cout << a[i] << " ";
    cout << endl;*/
    while (j<=m-n)
    {
        temp = 0;
        for (int i = j;i<j+n-1;i++)
        {
            temp +=a[i];
        }
        if (temp<ans) ans = temp;
        j++;
    }
    cout << ans;
    return 0;
}
