#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long i = 2, ch1 = 1, ch2 = 1;
    while (i<n)
    {
        int temp = ch1;
        ch1=ch2;
        ch2+=temp;
        i++;
    }
    cout << ch2;
    return 0;
}
