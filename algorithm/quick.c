#include<stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];	//피벗의 위치는 가장 왼쪽!
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		//피벗보다 큰 값을 찾는 과정
		while(pivot > arr[low])
			low++;
		
		//피벗보다 작은 값을 찾는 과정
		while (pivot < arr[high])
			high--;

		//교차 되지 않는 상태라면 Swap
		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;

}

void quickSort(int arr[], int left, int right)
{
	//퀵 소트의 재귀적 구현
	int pivot = partition(arr, left, right);
	quickSort(arr, left, pivot-1);
	quickSort(arr, pivot + 1, right);

}