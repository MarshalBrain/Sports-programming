#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int j = 1;
    while (pow(2,j)<n) j++;
    cout << j;
}

