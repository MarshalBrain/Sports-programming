#include <bits\stdc++.h>
#define pb push_back
using namespace std;

vector<bool> prime(1000005, true);
vector<long long> tp;
int main()
{
    int n;
    cin >> n;
    int k = 0;
    prime[0] = prime[1] = false;
    for (int i = 2;i<=1000000;i++)
    {
        if (prime[i])
        {
            tp.pb(i*1ll*i);
            if ((long long)i*i<=1000000)
                for (int j = i * 1ll * i;j<=1000000;j+=i) prime[j] = false;
        }
    }
    for (int i = 0;i<n; i++)
    {
        long long b;
        bool f = 0;
        cin >> b;
        int l = 0, r = (int)tp.size() - 1;
        while (l < r)
        {
            int mid = (r+l)/2;
            if (b<=tp[mid]) r = mid;
            else l = mid +1;
        }
        if (b == tp[l]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
