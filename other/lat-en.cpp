#include <iterator>
#include <iostream>
#include <map>
#include <cstdio>
#include <set>
#include <cctype>
#include <vector>
#include <cstring>
#define pb push_back
using namespace std;
int main() {
  // put your code here
  int n ;
    cin >> n;
    map < string, vector<string> > a;
    for (int i = 0;i<=n;i++)
    {
        char s[2000000];
        gets(s);
        int j = 0;
        string en;
        while (s[j]!=' ')
        {
           en+=s[j];
           j++;
        }
        while (j<strlen(s))
        {
            string lat;
            while (!isalpha(s[j])) j++;
            while (isalpha(s[j]))
            {
                lat+=s[j];
                j++;
            }
            a[en].pb(lat);
        }
    }
    map <string, vector<string> > b;
    map <string, vector<string> > :: iterator it = a.begin();
    while (it!=a.end())
    {
        for (int j = 0;j<it->second.size();j++) b[it->second[j]].pb(it->first);
        it++;
    }
    map <string, vector<string> > :: iterator jt = b.begin();
    cout << b.size() << endl;
    while (jt!=b.end())
    {
        cout << jt->first << " - ";
        for (int j = 0;j<jt->second.size();j++) if (j<jt->second.size()-1) cout << jt->second[j] << ", ";
                                                else cout << jt->second[j] << endl;
        jt++;
    }
  return 0;
}
