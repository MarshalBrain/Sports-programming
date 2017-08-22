#include <bits\stdc++.h>

using namespace std;
int sum(int i)
{
    int s = 0;
    while (i!=0) {s+=i%10;i/=10;}
    return s;
}
int main()

{
    long long int n;
    cin >> n;
    for (int i = round(sqrt(n)-1000);i<=round(sqrt(n));i++)
    {
        int temp = sum(i);
        if ((-temp + sqrt(pow(temp,2)+4*n))/2== i || (-temp - sqrt(pow(temp,2)+4*n))/2== i) { cout << abs(i);return 0;}
    }
    cout << -1;
    return 0;
}
