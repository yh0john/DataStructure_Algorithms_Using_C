
/*
*	2017.03.18 mamoization을 위한 fibonacci 작성
*	함수 호출 횟수를 줄이는 것이 key point !!
*	Recursion을 반복문으로 변경하거나 memoization을 활용 한다.
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