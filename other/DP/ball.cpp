#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n+1,0);
    int i = n;
    a[i] = 0;
    while (i>1)
    {
        if (i-3>=0) a[i-3]+=a[i]+1;
        if (i-2>=0) a[i-2]+=a[i]+1;
        if (i-1>=0) a[i-1]+=a[i]+1;
        i--;
    }
    cout << a[0]+1;
    return 0;
}
