/*
*
*	2017.03.16 
*	오늘 회사에서 아주 재미있는 코드를 발견했다.
*	int 값의 범위를 넘어버리는 overflow에 대해서 생각 해 볼 수 있는 코드였다.
*	물론 정수값을 벗어나는 값의 처리에 대해서도 찾아보았고 주말에 정리해서 업로드 할 예정이다.
*	스트링으로 4자리씩 잘라서 붙이는것을 떠올렸는데 구글 검색에서도 비슷한 답변이 있었다.
*	코드는 무조건 손으로 짜보고 디버깅하자
*	
*
*
*
*/



//아래 코드가 큰 수를 대입했을 때 실행시 0이 나온다.
//int 값이 overflow 하게 되면 부호비트가 반전되어서 다시 최소값으로 돌아간다.
#include<stdio.h>

int Fatorial(int num)
{
	if (num == 1) return 1;
	else if (num > 1) return num*Fatorial(num-1);
	return 0;
}
//아래와 같이 변경한다.

int FactorialChange(int num)
{
	if (num > 1) return num*FactorialChange(num - 1);
	else return 1;
}

int main(void)
{
	int input;
	int output;
	
	printf("값 입력 :"); scanf("%d", &input);

	printf("%d\n", Fatorial(input));
	printf("%d\n", FactorialChange(input));

	return 0;
}