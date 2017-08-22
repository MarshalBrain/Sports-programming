#include <stdio>
int main()
{
 int a[100],n,m,i,j;
 FILE* f=fopen("b.in","r");
 fscanf(f,"%d %d",&n,&m);
 fclose(f);
 j=1;
 for (i=0; i<=m; i++)
  a[i]=i;
 f=fopen("b.out","w");
 while (j!=0)
  {
   j=m;
   for (i=1; i<=m; i++)
    fprintf(f,"%d",a[i]);
   fprintf(f,"\n");
   while ((a[j]>=n+j-m) && (j>0))
    j--;
   if (j!=0)
    {
     a[j]=a[j]+1;
     for (i=j+1; i<=m; i++)
      a[i]=a[i-1]+1;
    }
  }
 fclose(f); 
 return 0;
}