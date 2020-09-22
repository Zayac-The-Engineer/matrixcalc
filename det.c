#include<stdio.h>
#include<stdlib.h>

int det(int **M, unsigned int x);
void output(int **M, unsigned int x);

int det(int **M, unsigned int x)
{
	int *buf = (int *)calloc(x, sizeof(int));
	int i, j, k;
	int b = 1;
	int d = 0;

	for(k=0; k<x; k++)
	{
		for(i=0; i<x; i++)
		{
			for(j=0; j<x; j++)
			{
				if((i+k)%x==j)
				{
					buf[j] = M[i][j];
				}
			}
		}

		for(i=0; i<x; i++)
		{
			b *= buf[i];
		}
		d += b;
		b = 1;
	}

	//I dunno, should probably work
	for(k=0; k<x; k++)
	{
		for(i=0; i<x; i++)
		{
			for(j=x; j>0; j--)
			{
				if((i+k)%x==x-j)
				{
					buf[j] = M[i][j];
				}
			}
		}

		for(i=0; i<x; i++)
		{
			b *= buf[i];
		}
		d -= b;
		b = 1;
	}

	return d;
}

void output(int **M, unsigned int x)
{
	int i, j;

	for(i=0; i<x; i++)
	{
		for(j=0; j<x; j++)
		{
			printf("%d\t", M[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int x, i, j;
	int **M;

	printf("Sqare matrix dim: ");
	scanf("%d", &x);

	M = (int **)malloc(x*sizeof(int *));

	for(i=0; i<x; i++)
	{
		M[i] = (int *)malloc(x*sizeof(int));
	}

	printf("Input matrix\n");
	
	for(i=0; i<x; i++)
	{
		for(j=0; j<x; j++)
		{
			scanf("%d", &M[i][j]);
		}
	}

	/* output(M, x); */
	printf("det: %d\n", det(M, x));
}
