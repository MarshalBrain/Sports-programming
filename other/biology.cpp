#include <bits\stdc++.h>

using namespace std;
int mi[35],ma[35],a[35];
int main()
{
    int n,sum;
    cin >> n >> sum;
    for (int i = 0;i<n;i++)
    {
        cin >> mi[i] >> ma[i];
        if (sum == 0 && mi[i]>0)
        {
            cout << "NO";
            return 0;
        }
        a[i] = mi[i];
        sum-=mi[i];
    }
    //cout << "!";
    int i = 0;
    while (sum>0 && i<n)
    {
        if (sum>ma[i]-mi[i])
        {
            a[i]+=(ma[i]-mi[i]);
            sum-=(ma[i]-mi[i]);
        }
        else
        {
            a[i]+=sum;
            sum = 0;
            break;
        }
        i++;
    }
    if (sum>0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++) cout << a[i] << " ";
    return 0;
}
