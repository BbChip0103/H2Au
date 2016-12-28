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

	// == char Binary[100], ������ �������̹迭 �����ٰ� MS�� ������ �ȵȴ뼭......
	Binary1 = (char*)malloc(sizeof(char) * 100); 
	Binary2 = (char*)malloc(sizeof(char) * 100);

	printf("�� ���� ������(100�� ���Ϸθ�, ������ �̱���)�� ���� ���ϱ� ���α׷��Դϴ�.\n\n");

	for (;;) {
		printf("ù ��° �������� �Է��ϼ��� : ");

		if (getBinary(Binary1) == 0)
			break;
	}
	

	for (;;) {
		printf("�� ��° �������� �Է��ϼ��� : ");

		if (getBinary(Binary2) == 0)
			break;
	}

	printf("\n");

	Dicimal1 = BinaryToDicimal(Binary1);
	Dicimal2 = BinaryToDicimal(Binary2);

	printf("�Է��� ���� (2����)  : 0b%s(2), 0b%s(2)\n", Binary1, Binary2);
	printf("�Է��� ���� (10����) : %d, %d\n\n", Dicimal1, Dicimal2);

	free(Binary1);
	free(Binary2);

	DicimalMultiplyResult = Dicimal1 * Dicimal2;

	BinaryResult = DicimalToBinary(DicimalMultiplyResult);

	printf("�Է��� ������ �� (10����) : %d\n", DicimalMultiplyResult);
	printf("�Է��� ������ �� (2����) : 0b%s(2)\n\n", BinaryResult);

	free(BinaryResult);

	return 0;
}

//	������ �Է� �κ�
int getBinary(char* InputBinary) {	

	for (;;) {
		scanf("%s", InputBinary);

		if (checkBinaryValue(InputBinary))
			break;
		else {
			printf("������ ���� 0 �Ǵ� 1�� ���� �� �ֽ��ϴ�. �ٽ� �Է����ּ���.\n\n");
			return 1;
		}
	}

	return 0;
}

// �Է��� ���� ���������� Ȯ���ϴ� �κ�
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

	// �迭 ������ ���� ������� ū ���̱� ������ �ڿ������� �о���
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

	// ���ڿ� �������� '\0'�ִ� �� ������ 1 ũ�� ����
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