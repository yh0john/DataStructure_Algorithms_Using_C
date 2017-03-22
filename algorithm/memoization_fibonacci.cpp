/*
*	2017-03-18 함수 과다 호출을 피하기 위한 memoization 기법
*	이전 값을 미리 배열에 저장해놓고 함수 호출을 피하는 대신 배열에 접근하는 방식이다.
*
*
*/
 
#include<stdio.h>

#define MAX_LEN 1000



int fibonacci(int num) {
	int arr[MAX_LEN];

	//값이 저장 되어 있을 경우 리턴.
	if (arr[num] != 0) {
		return arr[num];
	}

	if (num == 1 || num == 2) {
		arr[num] = 1;
		return 1;
	}

	//Memoization 기법 적용 
	//한 번 호출 했던 함수의 값을 배열에 저장 해놓은 뒤 값을 리턴한다.
	//값이 없을 경우만 연산
	//함수호출 횟수를 급격하게 낮출 수 있다.
	int temp = fibonacci(num - 1) + fibonacci(num - 2);
	arr[num] = temp;
	return temp;
	
}

int main(void)
{
	return 0;
}