#include<stdio.h>
#include<stdlib.h>

int det(const int**M, unsigned const int x);

int det(const int**M, unsigned const int x)
{
	int i, j, k, d;
	for(k=0; k<x; k++)
	{
		for(i=0, j=0; i<x ; i++, j=i)
		{
			
		}
	}
	return d;
}

void output(const int**M, unsigned const int x)
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
	int**M;

	printf("Sqare matrix dim: ");
	scanf("%d", &x);

	M = (int**)malloc(x*sizeof(int*));

	for(i=0; i<x; i++)
	{
		M[i] = (int*)malloc(x*sizeof(int));
	}

	printf("Input matrix\n");
	
	for(i=0; i<x; i++)
	{
		for(j=0; j<x; j++)
		{
			scanf("%d", &M[i][j]);
		}
	}

	output(M, x);
}
