#include<iostream>
#include<cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
    vector <int> ab;
    vector <int> ba;
    string s;
    cin >> s;
    int j = 1,l = 1;
    for (int i = 0;i<s.size();i++)
    {
        if (s[i] == 'A' && s[i+1] == 'B') ab.pb(i);
        if (s[i] == 'B' && s[i+1] == 'A') ba.pb(i);
    }
    for (int i = 0;i<ab.size();i++)
        for (int j = 0;j<ba.size();j++)
        {
            if (fabs(ab[i]-ba[j])>=2) {cout << "YES";return 0;}
        }
    cout << "NO";
    return 0;
}
