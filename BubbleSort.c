#include<stdio.h>

void BubbleSort(int array[], int length) 
{
	int i, j;
	int temp;

	for (i = 0; i < length-1; i++)
	{
		for (j = 0; j < length-i-1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	int arr[4] = { 3,2,5,1 };
	int i;
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	
	for (i = 0; i < 4; i++)
		printf("%d \n", arr[i]);

	return 0;
}