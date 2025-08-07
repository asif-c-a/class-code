#include <stdio.h>

void printSparseMat(int spMat[][3], int e)
{
    printf("Tuple Form : \n");
    for (int i = 0; i < e; i++)
	{
        printf("[%d %d %d]\n", spMat[i][0], spMat[i][1], spMat[i][2]);
    }
}

int sparseMat(int mat[][10], int r, int c, int spMat[][3])
{
    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
		{
            if (mat[i][j] != 0)
			{
                spMat[k][0] = i;
                spMat[k][1] = j;
                spMat[k][2] = mat[i][j];
                k++;
            }
        }
    }
    return k;
}

void addMat(int matA[][3], int matB[][3], int matC[][3], int aCount, int bCount)
{
    int i = 0, j = 0, k = 0;

    while (i < aCount && j < bCount)
	{
        if (matA[i][0] == matB[j][0] && matA[i][1] == matB[j][1])
		{
            matC[k][0] = matA[i][0];
            matC[k][1] = matA[i][1];
            matC[k++][2] = matA[i++][2] + matB[j++][2];
        } else if ((matA[i][0] < matB[j][0]) || (matA[i][0] == matB[j][0] && matA[i][1] < matB[j][1]))
		{
            matC[k][0] = matA[i][0];
            matC[k][1] = matA[i][1];
            matC[k][2] = matA[i][2];
            i++; k++;
        } else 
		{
            matC[k][0] = matB[j][0];
            matC[k][1] = matB[j][1];
            matC[k][2] = matB[j][2];
            j++; k++;
        }
    }

    while (i < aCount)
	{
        matC[k][0] = matA[i][0];
        matC[k][1] = matA[i][1];
        matC[k][2] = matA[i][2];
        i++; k++;
    }

    while (j < bCount)
	{
        matC[k][0] = matB[j][0];
        matC[k][1] = matB[j][1];
        matC[k][2] = matB[j][2];
        j++; k++;
    }

	printf("Sum of Matrices is : \n");
    printSparseMat(matC, k);
}

void transposeMat(int mat[][3], int count)
{
	int temp;
	
	for (int i = 0; i < count; i++)
	{
		temp = mat[i][0];
		mat[i][0] = mat[i][1];
		mat[i][1] = temp;
	}
	
	printf("Transpose of the Matrix is : \n");
	printSparseMat(mat, count);
}

int main() {
    int A[10][10], B[10][10], SpA[100][3], SpB[100][3], SpC[200][3];
    int ar, ac, br, bc, choice;

	printf("1. Addition\n2. Transpose\nInput selection[1/2] : ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		printf("Input size of matrix 1 | row col : ");
		scanf("%d %d", &ar, &ac);

		for (int i = 0; i < ar; i++)
		{
			for (int j = 0; j < ac; j++)
			{
				printf("Input element A.%d.%d : ", i + 1, j + 1);
				scanf("%d", &A[i][j]);
			}
		}

		printf("Input size of matrix 2 | row col : ");
		scanf("%d %d", &br, &bc);

		if (ar != br || ac != bc)
		{
			printf("Matrix dimensions must match for addition.\n");
			return 1;
		}

		for (int i = 0; i < br; i++)
		{
			for (int j = 0; j < bc; j++)
			{
				printf("Input element B.%d.%d : ", i + 1, j + 1);
				scanf("%d", &B[i][j]);
			}
		}

		int aCount = sparseMat(A, ar, ac, SpA);
		int bCount = sparseMat(B, br, bc, SpB);

		addMat(SpA, SpB, SpC, aCount, bCount);
		break;
	
	case 2:
		printf("Input size of matrix | row col : ");
		scanf("%d %d", &ar, &ac);

		for (int i = 0; i < ar; i++)
		{
			for (int j = 0; j < ac; j++)
			{
				printf("Input element A.%d.%d : ", i + 1, j + 1);
				scanf("%d", &A[i][j]);
			}
		}

		int count = sparseMat(A, ar, ac, SpA);

		transposeMat(SpA, count);

		break;
		
	default:
		break;
	}


   

    return 0;
}
