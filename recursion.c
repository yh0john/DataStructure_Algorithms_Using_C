/*
*
*	2017.03.16 
*	���� ȸ�翡�� ���� ����ִ� �ڵ带 �߰��ߴ�.
*	int ���� ������ �Ѿ������ overflow�� ���ؼ� ���� �� �� �� �ִ� �ڵ忴��.
*	���� �������� ����� ���� ó���� ���ؼ��� ã�ƺ��Ұ� �ָ��� �����ؼ� ���ε� �� �����̴�.
*	��Ʈ������ 4�ڸ��� �߶� ���̴°��� ���÷ȴµ� ���� �˻������� ����� �亯�� �־���.
*	�ڵ�� ������ ������ ¥���� ���������
*	
*
*
*
*/



//�Ʒ� �ڵ尡 ū ���� �������� �� ����� 0�� ���´�.
//int ���� overflow �ϰ� �Ǹ� ��ȣ��Ʈ�� �����Ǿ �ٽ� �ּҰ����� ���ư���.
#include<stdio.h>

int Fatorial(int num)
{
	if (num == 1) return 1;
	else if (num > 1) return num*Fatorial(num-1);
	return 0;
}
//�Ʒ��� ���� �����Ѵ�.

int FactorialChange(int num)
{
	if (num > 1) return num*FactorialChange(num - 1);
	else return 1;
}

int main(void)
{
	int input;
	int output;
	
	printf("�� �Է� :"); scanf("%d", &input);

	printf("%d\n", Fatorial(input));
	printf("%d\n", FactorialChange(input));

	return 0;
}