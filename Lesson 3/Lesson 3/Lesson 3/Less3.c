
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS



//Kichatova Anna
/*
1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество
операций сравнения оптимизированной и не оптимизированной программы. Написать
функции сортировки, которые возвращают количество операций.
*/

int task01a(int *arr, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	return count;
}


int task01b(int *arr, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++) {
		int bubble = 0;
		for (int j = len - 1 - i; j > i; j--) {
			count++;
			if (arr[j - 1] > arr[j]) {
				swap(&arr[j - 1], &arr[j]);
				bubble++;
			}
		}
		
		if (bubble <= 1) {
			break;
		}
	}
	return count;
}


// 2. *Реализовать шейкерную сортировку.

int task02(int *arr, int len)
{
	int n = 0;
	int left = 1;
	int right = len - 1;

	while (left <= right) {
		for (int i = right; i >= left; i--)
			if (arr[i - 1] > arr[i]) swap(&arr[i], &arr[i - 1]);
		left++;


		for (int i = left; i <= right; i++)
			if (arr[i - 1] > arr[i]) swap(&arr[i], &arr[i - 1]);
		right--;

		n += left - 1;
	}
	return n;
}

/*
3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный
массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
*/
int task03(int x, int *arr, int len)
{
	int left = 0, right = len - 1;
	int m = right / 2;

	while (left <= right && arr[m] != x) {
		if (arr[m] < x) {
			left = m + 1;
		}
		else {
			right = m - 1;
		}
		m = left + (right - left) / 2;
	}
	if (arr[m] == x) {
		return m;
	}
	else {
		return -1;
	}
}


int main() {
	int x = 45;
	const int SIZE = 20;
	int *arr1 = calloc(SIZE, sizeof(int));
	int *arr2 = calloc(SIZE, sizeof(int));
	int *arr3 = calloc(SIZE, sizeof(int));

	fill_array(arr1, SIZE);
	memcpy(arr2, arr1, sizeof(int) * SIZE);
	memcpy(arr3, arr1, sizeof(int) * SIZE);
	printarray(arr1, SIZE);
	printarray(arr2, SIZE);
	printarray(arr3, SIZE);

	printf("Original bubble sort %d.\n", task01a(arr1, SIZE));
	printarray(arr1, SIZE);
	printf("Optimaze bubble sort %d.\n", task01b(arr2, SIZE));
	printarray(arr2, SIZE);

	printf("%d.\n", task02(arr3, SIZE));
	printarray(arr3, SIZE);

	printf("%d.\n", x, task03(x, arr1, SIZE));

	
	return 0;
}
