#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Pretest1_3();
int getBinary(char*);
int checkBinaryValue(char*);
int BinaryToDicimal(char*);
char* DicimalToBinary(int);

void main() {

	Pretest1_3();

}

int Pretest1_3() {

	char *Binary1, *Binary2, *BinaryResult;
	int Dicimal1, Dicimal2, DicimalMultiplyResult;

	// == char Binary[100], 원래는 가변길이배열 쓰려다가 MS는 지원이 안된대서......
	Binary1 = (char*)malloc(sizeof(char) * 100); 
	Binary2 = (char*)malloc(sizeof(char) * 100);

	printf("두 개의 이진수(100자 이하로만, 음수는 미구현)에 대한 곱하기 프로그램입니다.\n\n");

	for (;;) {
		printf("첫 번째 이진수를 입력하세요 : ");

		if (getBinary(Binary1) == 0)
			break;
	}
	

	for (;;) {
		printf("두 번째 이진수를 입력하세요 : ");

		if (getBinary(Binary2) == 0)
			break;
	}

	printf("\n");

	Dicimal1 = BinaryToDicimal(Binary1);
	Dicimal2 = BinaryToDicimal(Binary2);

	printf("입력한 값들 (2진수)  : 0b%s(2), 0b%s(2)\n", Binary1, Binary2);
	printf("입력한 값들 (10진수) : %d, %d\n\n", Dicimal1, Dicimal2);

	free(Binary1);
	free(Binary2);

	DicimalMultiplyResult = Dicimal1 * Dicimal2;

	BinaryResult = DicimalToBinary(DicimalMultiplyResult);

	printf("입력한 값들의 곱 (10진수) : %d\n", DicimalMultiplyResult);
	printf("입력한 값들의 곱 (2진수) : 0b%s(2)\n\n", BinaryResult);

	free(BinaryResult);

	return 0;
}

//	이진수 입력 부분
int getBinary(char* InputBinary) {	

	for (;;) {
		scanf("%s", InputBinary);

		if (checkBinaryValue(InputBinary))
			break;
		else {
			printf("이진수 값은 0 또는 1만 넣을 수 있습니다. 다시 입력해주세요.\n\n");
			return 1;
		}
	}

	return 0;
}

// 입력한 값이 이진수인지 확인하는 부분
int checkBinaryValue(char* InputValue) {

	int InputLength;

	InputLength = strlen(InputValue);

	for (int i = 0; i < InputLength; i++) 
		if (!(InputValue[i] == '0' || InputValue[i] == '1'))
			return 0;
	
	return 1;
}

int BinaryToDicimal(char* Binary) {

	int Dicimal = 0;
	int BinaryLength;

	BinaryLength = strlen(Binary);

	// 배열 순서가 낮은 순서대로 큰 값이기 때문에 뒤에서부터 읽어줌
	for (int i = 0; i < BinaryLength; i++)
		if(Binary[(BinaryLength - 1) - i] == '1')	
			Dicimal += (1<<i);

	return Dicimal;
}

char* DicimalToBinary(int Dicimal) {

	char* TempBinary;
	int ConvertingCount = 0;

	if (Dicimal == 0) {
		TempBinary = (char*)malloc(sizeof(char) + 2);
		TempBinary[0] = '0';
		TempBinary[1] = '\0';
		return TempBinary;
	}

	for (;;) {
		if (Dicimal < (1 << ConvertingCount)) 
			break;
		else
			ConvertingCount++;
	}

	// 문자열 마지막에 '\0'넣는 것 때문에 1 크게 잡음
	TempBinary = (char*)malloc(sizeof(char) * (ConvertingCount + 1));	

	for (int i = 0; i < ConvertingCount; i++) {
		if ((Dicimal % 2) == 1)
			TempBinary[(ConvertingCount - 1) - i] = '1';
		else
			TempBinary[(ConvertingCount - 1) - i] = '0';

		Dicimal /= 2;
	}

	TempBinary[ConvertingCount] = '\0';

	return TempBinary;
}