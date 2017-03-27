#include<stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];	//�ǹ��� ��ġ�� ���� ����!
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		//�ǹ����� ū ���� ã�� ����
		while(pivot > arr[low])
			low++;
		
		//�ǹ����� ���� ���� ã�� ����
		while (pivot < arr[high])
			high--;

		//���� ���� �ʴ� ���¶�� Swap
		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;

}

void quickSort(int arr[], int left, int right)
{
	//�� ��Ʈ�� ����� ����
	int pivot = partition(arr, left, right);
	quickSort(arr, left, pivot-1);
	quickSort(arr, pivot + 1, right);

}