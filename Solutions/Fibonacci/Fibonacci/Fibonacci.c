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
		printf("- 정상 동작 -\n\n");
	else {
		printf("- error -");
		return;
	}

	ProcessingTime = clock() - ProcessingStartTime - InputTime;

	printf("프로그램 수행 시간 : %f초\n\n", (double)clock() / 1000);
	printf("입력에 소모된 시간 : %f초\n\n", (double)InputTime / 1000);
	printf("실행 시간 : %f초\n\n", (double)ProcessingTime / 1000);

}

int Pretest1_5(clock_t* InputTime) {

	int *Fibonacci;
	int FibonacciLength, TheNumberOfZero, TheNumberOfOne;
	int i;
	clock_t InputStartTime, InputEndTime;

	for (;;) {
		printf("수열의 사이즈를 입력 해주세요 : ");
		InputStartTime = clock();
		scanf_s("%d", &FibonacciLength);
		InputEndTime = clock();
		*InputTime += (InputEndTime - InputStartTime);
		FlushBuffer();

		if (FibonacciLength >= 1 && FibonacciLength <= 40) 
			break;
		else
			printf("1~40 사이의 정수값만 입력 해주세요.\n\n");
	}

	printf("\n");

	Fibonacci = (int*)malloc(sizeof(int) * FibonacciLength);
	makeFibonacci(Fibonacci, FibonacciLength);

	printf("피보나치 수열 : ");

	for (i = 0; i < FibonacciLength; i++)
		printf("%d ", Fibonacci[i]);
	
	printf("\n\n");

	TheNumberOfZero = countNumberFibonacci(Fibonacci, FibonacciLength, 0);
	TheNumberOfOne = countNumberFibonacci(Fibonacci, FibonacciLength, 1);

	printf("0의 갯수 : %d\n\n", TheNumberOfZero);
	printf("1의 갯수 : %d\n\n", TheNumberOfOne);

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

	char TempFibonacci[10];	// 각 자리 최대 자릿수가 9개니 %0 넣을거 생각해서 10개로 선언
	int NumberQuantity = 0, ElementLength;

	for (int i = 0; i < FibonacciLength; i++) {
		
		_itoa(Fibonacci[i], TempFibonacci, 10);

		ElementLength = strlen(TempFibonacci);
		
		//	아스키코드이기 때문에 정수에서 +48해줘야 문자열과 맞음
		for (int j = 0; j < ElementLength; j++)
			if (TempFibonacci[j] == (char)(Number+48))	
				NumberQuantity++;
	}
	
	return NumberQuantity;
}