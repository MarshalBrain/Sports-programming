#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxN = 1e9;
int main()
{
    long long n;
    long long a,b,c;
    cin >> n >> a >> b >> c;
    //f (n%4 == 0) {cout << 0;return 0;}
    long long ans = maxN;
    for (int i = 0; i<=100;i++)
    {
        if ((n+i)%4 == 0)
        {
            long long mini = maxN;
            for (int j = 0;j<=i;j++)
                for (int l = 0;l<=i/2;l++)
                {
                    if (l*2+j>i) break;
                    if ((i-(l*2+j))%3 == 0)
                    {
                        mini = min(mini,j*a+l*b+(i-(l*2+j))/3*c);
                        /*cout << i << " " << j << " " << l << " " << i-(j+l*2) << endl;
                        system("pause");*/
                    }
                }
            ans = min(mini, ans);
        }
    }
    cout << ans;
    return 0;
}
