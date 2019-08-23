#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//����� - �������� ����
//1. ����������� ������� �������� ����� �� ���������� ������� � ��������, ��������� ��������.

void task01(int x, char *result)
{
	if (x)
	{
		task01(x / 2, result);
		strcat(result, (x % 2) ? "1" : "0");
	}
}

/*
2. ����������� ������� ���������� ����� a � ������� b:
a. ��� ��������;
b. ����������;
c. *����������, ��������� �������� �������� �������.
*/

float task02(int a, int n, int f)
{
	float A = 1;

	switch (f) {
		// a
	case 0:
		for (int i = 0; i < n; i++) A *= a;
		break;
		// b
	case 1:
		if (!n) return A;
		return a * task02(a, --n, 1);
		break;
		// c
	case 2:
		if (!n) return A;
		if (n % 2) return a * task02(a, n - 1, 2);
		return task02(a * a, n / 2, 2);
		break;
	}
	return A;
}



int main() {
	int b;

	
	// task01
	char R[20] = "b";
	printf("Number to bin: ");
	scanf("%d", &b);
	task01(b, R);
	printf("%d = %s\n", b, R);

	// task02
	int a = 5;
	b = 4;
	// a)
	printf("%d ^ %d: %.0f\n", a, b, task02(a, b, 0));
	// b)
	printf("%d ^ %d: %.0f\n", a, b, task02(a, b, 1));
	// c)
	printf("%d ^ %d: %.0f\n", a, b, task02(a, b, 2));

	
	return 0;
}
