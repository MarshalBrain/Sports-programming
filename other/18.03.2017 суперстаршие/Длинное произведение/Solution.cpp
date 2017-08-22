#include <stdio>
#include <string>
#include <algorithm>
using namespace std;
int a[2502]={0};
int b[2502]={0};
int c[5004]={0};
void input()
{
 FILE* f=fopen("longprod.in","r");
 char* s=new char[2501];
 fgets(s,2503,f);
 a[0]=strlen(s);
 if (s[a[0]-1]=='\n')
  a[0]--;
 int i;
 for (i=a[0]; i>=1; i--)
  a[i]=s[a[0]-i]-'0';
 fgets(s,2503,f);
 b[0]=strlen(s);
 if (s[b[0]-1]=='\n')
  b[0]--;
 for (i=b[0]; i>=1; i--)
  b[i]=s[b[0]-i]-'0';
 fclose(f);
}
void sum()
{
 int i,j;
 int k=a[0]+b[0];
 for (i=1; i<=a[0]; i++)
  for (j=1; j<=b[0]; j++)
   c[i+j-1]=a[i]*b[j]+c[i+j-1];
 for (i=1; i<=k; i++)
  if (c[i]>9)
   {
    c[i+1]=c[i+1]+c[i]/10;
    c[i]=c[i]%10;
   }
 while (c[k]==0 && k>1)
  k--;
 c[0]=k;   
}
void out()
{
 FILE* f=fopen("longprod.out","w");
 int i;
 for (i=c[0]; i>=1; i--)
  fprintf(f,"%d",c[i]);
 fclose(f); 
}
int main()
{
 input();
 sum();
 out();
 return 0;
}