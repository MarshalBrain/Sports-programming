#include <stdio>
#include <math>
int simple[1000]={0};
int k_simple=0;
void Eratosfen()
{
 int b[2000]={0};
 int n=505;
 int i;   
 b[1]=2;
 for (i=2; i<=n; i++)
  b[i]=2*i-1;
 int j=2;
 while (j<=n)
  {
   i=j+b[j];
   while (i<=n)
    {
     b[i]=0;
     i+=b[j];
    }
   j++;
   while (j<=n && b[j]==0)
    {
     j++;
    }
  }
 for (i=1; i<=n; i++)
  if (b[i]!=0)
   {
    k_simple++;
    simple[k_simple]=b[i];
   }
}
bool is_simple(int n)
{
 int root=sqrt(n);
 int i;
 for (i=1; simple[i]<=root; i++)
  if (n%simple[i]==0)
   return false;
 return true;
}
void Solve()
{
 FILE* f=fopen("primes2.in","r");
 int n,m;
 fscanf(f,"%d",&n);
 fscanf(f,"%d",&m);
 int k=0;
 fclose(f);
 f=fopen("primes2.out","w");
 int i;
 for (i=n; i<=m; i++)
  if (is_simple(i))
   {
    fprintf(f,"%d\n",i);
    k++;
   }
 if (k==0)
  fprintf(f,"Absent");
 fclose(f); 
}
int main()
{
 Eratosfen();
 Solve();
 return 0;
}