#include <stdio>
#include <math>
bool simple(int n)
{
 int i;
 if (n==1)
  return false;
 for (i=2; i<=sqrt(n); i++)
  if (n%i==0)
   return false;
 return true;
}
int main()
{
 FILE* f=fopen("primes.in","r");
 int n,m;
 fscanf(f,"%d%d",&n,&m);
 fclose(f);
 int i;
 int k=0;
 f=fopen("primes.out","w");
 for (i=n; i<=m; i++)
  if (simple(i))
   {
    k++;
    fprintf(f,"%d\n",i);
   }
 if (k!=0)
  fclose(f);
 else
  {
   fprintf(f,"Absent");
   fclose(f);
  }
}