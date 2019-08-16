#include <stdio.h>
#include <stdlib.h>
#include <math.h>




// автор - Кичатова Анна

/*
14. * Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
Например, 25 \ :sup: '2' = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все
автоморфные числа, не превосходящие N.
*/
int main(int argc, const char* argv[])
{

	int x, s, m, r, n;
	printf("Enter N: ");
	scanf_s("%d", &n);
	printf("Automorphic numbers %d:", n);

	for (x = 0; x < n; x++)
	{
		s = pow(x, 2);

		for (m = 10; m < x; m *= 10);
		r = s % m;

		if (x == r)
			printf("%d\n", x);
	}

	system("pause");
	return 0;
}

/*
13. * Написать функцию, генерирующую случайное число от 1 до 100.
a. с использованием стандартной функции rand().
b. без использования стандартной функции rand().
*/

int main(int argc, char *argv[])
{

	srand(time(NULL));

	printf("Rand: %d\n", rand() % 100 + 1);

	int r = (rand() % 100) + 1;
	r = ((r * 651) + 1) % 100;
	if (r == 0) { r = 1; }
	printf("MyRand : %d\n", r);

	system("pause");

	return 0;
}

// 12. Написать функцию нахождения максимального из трех чисел.

int main(int argc, char *argv[])
{
	int a, b, c, max;

	printf("a, b, c: ");
	scanf_s("%d %d %d", &a, &b, &c);
	if (a > b) {
		max = a;
	}
	else {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	printf("Max: %d\n", max);

	system("pause");

	return 0;
}

/*
11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных
чисел, оканчивающихся на 8.
*/

int main(int argc, char *argv[])

{
	int a, sum = 0;

	do {
		printf("enter a or 0 to exit: ");
		scanf_s("%d", &a);
		if (a > 0 && (a % 2) == 0 && (a % 10) == 8) {
			sum += a;
		}
	} while (a != 0);

	printf("Sum = %d\n", sum);

	system("pause");

	return 0;
}

