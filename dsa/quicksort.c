#include <stdio.h>

int array[10];

int partition(int low, int high)
{
	int x = array[high], j = low - 1;

	for (int i = low; i < high - 1; i++)
	{
		if (array[i] <= x)
		{
			j++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	int tempo = array[j+1];
	array[j+1] = array[high];
	array[high] = tempo;
	
	return j+1;
}

void quicksort(int low, int high)
{
	if (low < high)
	{
		int pivot = partition(low, high);
		quicksort(low, pivot - 1);
		quicksort(pivot + 1, high);
	}
}

void main()
{
	int n;

	printf("Input number of elements : ");
	scanf("%d", &n);

	for (int k = 0; k < n; k++)
	{
		printf("Input element %d : ", k+1);
		scanf("%d", &array[k]);
	}
	
	quicksort(0, n);
	
	printf("[ ");
	for (int k = 1; k <= n; k++)
	{
		printf("%d ", array[k]);
	}
	printf("]\n");

}