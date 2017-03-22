/*
*	2017-03-18 �Լ� ���� ȣ���� ���ϱ� ���� memoization ���
*	���� ���� �̸� �迭�� �����س��� �Լ� ȣ���� ���ϴ� ��� �迭�� �����ϴ� ����̴�.
*
*
*/
 
#include<stdio.h>

#define MAX_LEN 1000



int fibonacci(int num) {
	int arr[MAX_LEN];

	//���� ���� �Ǿ� ���� ��� ����.
	if (arr[num] != 0) {
		return arr[num];
	}

	if (num == 1 || num == 2) {
		arr[num] = 1;
		return 1;
	}

	//Memoization ��� ���� 
	//�� �� ȣ�� �ߴ� �Լ��� ���� �迭�� ���� �س��� �� ���� �����Ѵ�.
	//���� ���� ��츸 ����
	//�Լ�ȣ�� Ƚ���� �ް��ϰ� ���� �� �ִ�.
	int temp = fibonacci(num - 1) + fibonacci(num - 2);
	arr[num] = temp;
	return temp;
	
}

int main(void)
{
	return 0;
}