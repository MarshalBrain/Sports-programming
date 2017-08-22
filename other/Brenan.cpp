#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = n+1; i<2*n;i++)
    {
        bool f = 0;
        //if (pow(round(sqrt(i)),2) > 2*n) break;
        for (int j = 2;j<i/2;j++)
        {
            if (i%j == 0) { f = 1;break;}
        }
        if (f == 0) {ans ++; /*cout << i << endl;*/}
    }
    cout << ans;
}
