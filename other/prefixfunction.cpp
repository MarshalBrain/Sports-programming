#include <bits\stdc++.h>
using namespace std;
vector <int> pref_func(const string& s)
{
    vector <int> pref(s.length());
    pref[0] = 0;
    int k = 0;
    for (int i = 1;i<s.length(); i++)
    {
        int j = i;
        while (s[j]!=s[k] && k>0)
        {
            k = pref[k-1];
        }
        if (s[i] == s[k]) k++;
        pref[i] = k;
    }
    for (int i = 0;i<s.length();i++) cout << pref[i];
    return pref;
}
/*vector<int> compute_prefix_function(const string& s)
{
	int len = s.length();
	vector<int> p(len); // значения префикс-функции
	                    // индекс вектора соответствует номеру последнего символа аргумента
	p[0] = 0; // для префикса из нуля и одного символа функция равна нулю

    int k = 0;
	for (int i = 1; i < len; ++i) {
		while ((k > 0) && (s[k] != s[i]))
			k = p[k - 1];
		if (s[k] == s[i])
			++k;
		p[i] = k;
	}
	for (int i = 0;i<s.length();i++) cout << p[i];
	return p;
}*/
int main()
{
    string s;
    cin >> s;
    pref_func(s);
   //compute_prefix_function(s);
    return 0;
}
