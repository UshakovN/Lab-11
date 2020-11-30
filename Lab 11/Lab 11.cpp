/*Необходимо генерировать исключения в следующих ситуациях: попытка повторного добавления элемента в множество; 
попытка добавить элемент, значение которого лежит вне диапазона разрешённых элементов.*/

#include <cstdio>
#include <locale.h>
#include "SETNUM.h"
#include "EXCEPTIONS.h"
#pragma warning (disable:6064)

int main() {
	setlocale(LC_ALL, "RUS");
	int z = 0; char end = NULL;
	try {
		printf("Ввод множества.\n");
		printf("Проинициализируйте множество числом.\n");
		scanf_s("%d", &z);
		SETNUM Set(z);
		Set.Output();
		printf("Нажмите z чтобы завершить.\n");
		while (end != 'z') {
			printf("Введите число, которое следует добавить в множество.\n");
			scanf_s("%d", &z);
			Set += z;
			Set.Output();
			scanf_s("%c", &end);
		}
		printf("Числа добавлены.\n"); end = NULL;

		while (end != 'z') {
			printf("Введите число, которое следует удалить из множество.\n");
			scanf_s("%d", &z);
			Set -= z;
			Set.Output();
			scanf_s("%c", &end);
		}
	}
	catch (const BAD_VALUE ExceptionValue) {
		ExceptionValue.GetInfo();
	}
	catch (const REPEAT_ADD ExceptionRepeat) {
		ExceptionRepeat.GetInfo();
	}
	catch (const REPEAT_DEL ExceptionDel) {
		ExceptionDel.GetInfo();
	}
}
