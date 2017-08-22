#include <bits\stdc++.h>
using namespace std;

int main()
{
    freopen("T.cpp","w",stdout);
    for (int i = 2;i<=1000000; i++)
        {
        bool f = 0;
        for (int j = 2;j<floor(sqrt(i))+1;j++)
        {
            if (i%j == 0)
            {
                f = 1;
                break;
            }
        }
        if (f == 0) cout << i << ", ";
    }
    return 0;
}
