
#include <stdio.h>

FILE *I,*O;
int n,m,k,l,i,id;
int a[3],b[3];
int w[105][105][105];

void set(int p, int q)
{
	for (int i = 1; i<=n; i++)
		for (int j = 1; j<=m; j++)
			for (int v = 1; v<=k; v++)
				if (w[i][j][v] == p)
					w[i][j][v] = q;
}

void f1(int q)
{
	int t,e;

	if (a[q]>b[q])
		t = -1;
	else
		t = 1;

	if (w[a[0]][a[1]][a[2]]==0)
	{
		e = id;
		id++;
		w[a[0]][a[1]][a[2]] = e;
	}
	else
	{
		e = w[a[0]][a[1]][a[2]];
	}

	do
	{
		a[q] += t;
		int h = w[a[0]][a[1]][a[2]];

		if (h==e)
		{
			a[q] -= t;
			fprintf(O, "%i %i %i ", a[0], a[1], a[2]);
			a[q] += t;
			fprintf(O, "%i %i %i\n", a[0], a[1], a[2]);

			e = h;
			set(e,h);
		}
		else if (h==0)
		{
			w[a[0]][a[1]][a[2]] = e;
		}
		else
		{
			set(h, e);
		}
	}
	while ((a[0]!=b[0]) || (a[1]!=b[1]) || (a[2]!=b[2]));
}


int main()
{
	I = fopen("input.txt", "r");
	O = fopen("output.txt", "w");

	fscanf(I, "%i %i %i %i\n", &n, &m, &k, &l);

	id = 1;

	for (i = 0; i<l; i++)
	{
		fscanf(I, "%i %i %i ", &a[0], &a[1], &a[2]);
		fscanf(I, "%i %i %i\n", &b[0], &b[1], &b[2]);

		if (a[0]!=b[0])
			f1(0);
		else if (a[1]!=b[1])
			f1(1);
		else
			f1(2);
	}
}