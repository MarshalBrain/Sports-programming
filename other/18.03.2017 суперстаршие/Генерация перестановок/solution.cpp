#include <stdio>
int main()
{
 int a[100],b[100],n,m,j,i,k,p;
 FILE* f=fopen("a.in","r");
 fscanf(f,"%d",&n);
 for(i=0; i<=n; i++)
  {
   a[i]=i;
   b[i]=i;
  }
 f=fopen("a.out","w");
 while (a[0]==0)
  {
   for (i=1; i<=n; i++)
    fprintf(f,"%d",a[i]);
   fprintf(f,"\n");
   j=n;
   while (a[j-1]>a[j])
    j--;
   k=n;
   while (a[j-1]>a[k])
    k--;
   p=a[k];
   a[k]=a[j-1];
   a[j-1]=p;
   for (i=j; i<=n;i++)
    b[n-i+j]=a[i];
   for (i=j; i<=n;i++)
    a[i]=b[i];
  }
 fclose(f); 
 return 0;
}

