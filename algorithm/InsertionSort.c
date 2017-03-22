#include<stdio.h>

void InsertionSort(int arr[], int length)
{
	int i, j;
	int insData;

	for (i = 1; i < length; i++) 
	{
		insData = arr[i];		//정렬 대상을 insData에 저장

		for(j=i-1;j>=0;j--)
		{
			if (arr[j] > insData)
			{
				arr[j + 1] = arr[j];
			}
			else
				break;
			
		}

		arr[j] = insData;
	}
}

int main(void)
{

	int arr[5] = { 5,3,2,4,1 };
	int i;

	InsertionSort(arr, sizeof(arr) / sizeof(int));
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	return 0;
}