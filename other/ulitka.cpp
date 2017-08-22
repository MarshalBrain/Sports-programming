#include <iostream>

using namespace std;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    if ((n/a)%(a-b)!=0) cout << (n-a)/(a-b)+2;
    else cout << (n-a)/(a-b)+1;
    return 0;
}
