#include <stdio>
FILE* f;
int a[30]={0};
int n;
void solve(int i)
{
 int j;
 if (i<=n)
  {
   for (j=i; j<=n; j++)
    {
     if (a[j]==0)
      {
       a[j]=1;
       for (int t=1; t<=n; t++)
        if (a[t]==1)
         fprintf(f,"%d",t);
       fprintf(f,"\n");
       solve(j+1);
       a[j]=0;
     }
    } 
  }
}
int main()
{
 f=fopen("c.in","r");
 fscanf(f,"%d",&n);
 fclose(f);
 int i;
 f=fopen("c.out","w");
 solve(1);
 fclose(f);
 return 0;
}