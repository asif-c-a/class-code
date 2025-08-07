#include <stdio.h>

void printSparseMat(int spMat[][3], int e)
{
  printf("\nTuple Form : \n");
	for (int i = 0; i < e; i++)
	{
		printf("[%d %d %d]\n", spMat[i][0], spMat[i][1], spMat[i][2]);
	}
}

void sparseMat(int mat[][10], int r, int c, int spMat[][3])
{
	int k = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if(mat[i][j] != 0)
			{
				spMat[k][0] = i;
				spMat[k][1] = j;
				spMat[k][2] = mat[i][j];
				k++;
			}
		}
	}
	
	printSparseMat(spMat, k);
}

void main()
{
	int A[10][10], B[10][10], SpA[100][3], SpB[100][3];
	int ar, ac, br, bc;

	printf("Input size of matrix 1 | row col : ");
	scanf("%d %d", &ar, &ac);

	for (int i = 0; i < ar; i++)
	{
		for (int j = 0; j < ac; j++)
		{
			printf("Input element A.%d.%d : ", i+1, j+1);
			scanf("%d", &A[i][j]);	
		}
	}
	
	printf("Input size of matrix 2 | row col : ");
	scanf("%d %d", &br, &bc);

	for (int i = 0; i < br; i++)
	{
		for (int j = 0; j < bc; j++)
		{
			printf("Input element B.%d.%d : ", i+1, j+1);
			scanf("%d", &B[i][j]);	
		}
	}

	sparseMat(A, ar, ac, SpA);
	sparseMat(B, br, bc, SpB);
}
