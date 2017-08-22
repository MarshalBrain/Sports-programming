#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int maxN = 50;
long long n;
vector<int> a(maxN);
int bin(int n)
{
    int j = 0;
    while (n>1)
    {
        a[j] = n%2;
        j++;
        n/=2;
    }
    a[j] = n;
    return j;
}
int main()
{
    cin >> n;
    int k = bin(n)+1;
    bool f = 0;
    int l = 0;
    for (int i = 0;i<=k;i++)
    {
        if (a[i] == 1 && a[i+1] == 0) {a[i] = 0; a[i+1]+=1; f = 1; l = i; break;}
    }
    int j = 0;
    while (j<l)
    {
        if (a[l] == 1)
        {
            while (a[j] == 1) j++;
            if (j>l) break;
            a[j] = 1;
            a[l] = 0;
        }
        l--;
    }
    if (a[k] == 0) k--;
    int ans = 0;
    for (int i = k;i>=0;i--)
    {
        ans+=a[i]*pow(2,i);
    }
    cout << ans;
    return 0;
}
