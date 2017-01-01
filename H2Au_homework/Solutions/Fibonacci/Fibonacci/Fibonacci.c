#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Pretest1_5(clock_t*);
void FlushBuffer();
void makeFibonacci(int*, int);
int countNumberFibonacci(int*, int, int);

void main() {
	
	clock_t ProcessingStartTime, InputTime = 0,  ProcessingTime;

	ProcessingStartTime = clock();

	if (Pretest1_5(&InputTime) == 0)
		printf("- ���� ���� -\n\n");
	else {
		printf("- error -");
		return;
	}

	ProcessingTime = clock() - ProcessingStartTime - InputTime;

	printf("���α׷� ���� �ð� : %f��\n\n", (double)clock() / 1000);
	printf("�Է¿� �Ҹ�� �ð� : %f��\n\n", (double)InputTime / 1000);
	printf("���� �ð� : %f��\n\n", (double)ProcessingTime / 1000);

}

int Pretest1_5(clock_t* InputTime) {

	int *Fibonacci;
	int FibonacciLength, TheNumberOfZero, TheNumberOfOne;
	int i;
	clock_t InputStartTime, InputEndTime;

	for (;;) {
		printf("������ ����� �Է� ���ּ��� : ");
		InputStartTime = clock();
		scanf_s("%d", &FibonacciLength);
		InputEndTime = clock();
		*InputTime += (InputEndTime - InputStartTime);
		FlushBuffer();

		if (FibonacciLength >= 1 && FibonacciLength <= 40) 
			break;
		else
			printf("1~40 ������ �������� �Է� ���ּ���.\n\n");
	}

	printf("\n");

	Fibonacci = (int*)malloc(sizeof(int) * FibonacciLength);
	makeFibonacci(Fibonacci, FibonacciLength);

	printf("�Ǻ���ġ ���� : ");

	for (i = 0; i < FibonacciLength; i++)
		printf("%d ", Fibonacci[i]);
	
	printf("\n\n");

	TheNumberOfZero = countNumberFibonacci(Fibonacci, FibonacciLength, 0);
	TheNumberOfOne = countNumberFibonacci(Fibonacci, FibonacciLength, 1);

	printf("0�� ���� : %d\n\n", TheNumberOfZero);
	printf("1�� ���� : %d\n\n", TheNumberOfOne);

	free(Fibonacci);

	return 0;
}

void FlushBuffer() {

	for (;;)
		if (getchar() == '\n')
			return;
}

void makeFibonacci(int* Fibonacci, int FibonacciLength) {

	if (FibonacciLength >= 1)
		Fibonacci[0] = 1;
	
	if (FibonacciLength >= 2)
		Fibonacci[1] = 1;

	if (FibonacciLength < 3)
		return;

	for (int i = 2; i < FibonacciLength; i++) 
		Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
}

int countNumberFibonacci(int* Fibonacci, int FibonacciLength, int Number) {

	char TempFibonacci[10];	// �� �ڸ� �ִ� �ڸ����� 9���� %0 ������ �����ؼ� 10���� ����
	int NumberQuantity = 0, ElementLength;

	for (int i = 0; i < FibonacciLength; i++) {
		
		_itoa(Fibonacci[i], TempFibonacci, 10);

		ElementLength = strlen(TempFibonacci);
		
		//	�ƽ�Ű�ڵ��̱� ������ �������� +48����� ���ڿ��� ����
		for (int j = 0; j < ElementLength; j++)
			if (TempFibonacci[j] == (char)(Number+48))	
				NumberQuantity++;
	}
	
	return NumberQuantity;
}