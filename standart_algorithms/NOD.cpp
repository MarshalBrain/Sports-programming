#include <bits\stdc++.h>

using namespace std;
/*int NOD(int a, int b)
{
    return b ? NOD(b,a%b) : a;
}*/
int NOD(int a, int b)
{
    while (a*b!=0)
    {
        if (a>b) a%=b;
        else b%=a;
    }
    return a+b;
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout << NOD(a,b);
    return 0;
}
