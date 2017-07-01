#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    node *next;
    string data;
};
node **hash_table;
int hashtablesize = 5101;
int hashh(string s)
{
    int ch = 0;
    for (int i = 0;i<s.size();i++)
        ch+=(int)s[i];
    return (ch%hashtablesize);
}
void insert_hash(string s)
{
    node *p, *p0;
    int buck = hashh(s);
    p = new node;
    //cout << buck << endl;
    p0 = hash_table[buck];
    //hash_table[buck] = new node;
    hash_table[buck] = p;
    p->next = p0;
    p->data = s;
}
bool find_hash(string s)
{
    int buck = hashh(s);
    node *p;
    if (hash_table[buck] != NULL) p = hash_table[buck];
    else return 0;
    while (p->data != s && p->next != NULL)
    {
        p = p->next;
    }
    if (p->next == NULL && p->data != s) return 0;
    else return 1;
}
void delete_hash(string s)
{
    node *p, *p0;
    p = hash_table[hashh(s)];
    p0 = 0;
    while (p != NULL && p->data != s)
    {
        //cout << "?" << endl;
        p0 = p;
        p = p->next;
    }
    if (p == NULL && p0->data!=s) return;
    if (p0) p0->next = p->next;
    else hash_table[hashh(s)] = p->next;
    free(p);
}
int main()
{
    hash_table = new node*[hashtablesize];
    for (int i = 0;i<hashtablesize;i++)
    {
        hash_table[i] = NULL;
    }
    string s;
    char s1;
    while (s1!='#')
    {
        cin >> s1;
        if (s1 == '#') break;
        cin >> s;
        if (s1 == '+') insert_hash(s);
        if (s1 == '-') delete_hash(s);
        if (s1 == '?')
            if (find_hash(s)) cout << "YES" << endl;
            else cout << "NO" << endl;
    }
    for (int i = 0;i<hashtablesize;i++)
    {
        if (hash_table[i] == NULL) continue;
        //cout << i << endl;
        node *p, *p0;
        p = hash_table[i];
        //cout << hash_table[i]->data;
       // system("pause");
        while (p != NULL)
        {
            p0 = p->next;
           // cout << "?" << endl;
            delete p;
            p = p0;
        }
    }
    delete []hash_table;
    return 0;
}
