
/*
*	2017.03.18 mamoization�� ���� fibonacci �ۼ�
*	�Լ� ȣ�� Ƚ���� ���̴� ���� key point !!
*	Recursion�� �ݺ������� �����ϰų� memoization�� Ȱ�� �Ѵ�.
*/

#include<stdio.h>

int fibonacci(int num) {
	if (num <= 2) return 1;
	return fibonacci(num - 1) + fibonacci(num - 2);
}

int main(void) {

	int i;
	for (i = 1; i < 11; i++)
	{
		printf("%d ",fibonacci(i));
	}
	return 0;
}