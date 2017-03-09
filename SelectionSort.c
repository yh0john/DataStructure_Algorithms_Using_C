#include<stdio.h>

void SelectionSort(int arr[], int length)
{
	int i, j;
	int temp;
	int maxIdx;

	for (i = 0; i < length - 1; i++)
	{
		maxIdx = i;

		for (j = i+1; j < length; j++) 
		{
			if (arr[j] < arr[maxIdx])
			{
				maxIdx = j;
			}
		}
		temp = arr[j];
		arr[j] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main(void)
{
	return 0;
}