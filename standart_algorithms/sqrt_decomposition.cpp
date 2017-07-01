#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n,0);
    for (int i = 0;i<n;i++) cin >> a[i];
    int m;
    int b_size = ceil(sqrt(n));
    vector<int> b(b_size,0);
    for (int i = 0;i<n;i++)
    {
        b[i/b_size]+=a[i];
    }
    //for (int i = 0;i<b_size;i++) cout << b[i] << " ";
    cin >> m;
    for (int i = 0;i<m;i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int lb = l/b_size, rb = r/b_size,sum = 0;
        if (lb == rb)
        {
            for (int i = l;i<=r;i++) sum+=a[i];
            cout << sum << endl;
            continue;
        }
        else
        {
            int lb_end = (lb+1)*b_size-1, rb_begin = rb*b_size;
            for (int i = l;i<=lb_end;i++) sum+=a[i];
            for (int i = rb_begin;i<=r;i++) sum+=a[i];
            for (int i = lb+1;i<rb;i++) sum+=b[i];
            cout << sum << endl;
        }
    }
    return 0;
}
