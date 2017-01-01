#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int Pretest3_2_4();
int getHexaData(char *);
void flushBuffer();
int moreHexaData();
char **Calc(List *);
void HexToBin(char *, char [4][5]);
void addSumOfDataList(char **, char [][5]);

void main() {

	Pretest3_2_4();

}

int Pretest3_2_4() {

	List HexaDataList;
	LData HexaData;
	char InputHexaData[7];
	char **SumOfHexaData;
	int i;

	ListInit(&HexaDataList);

	// ������ ������ 16������ �Է¹���
	do {
		getHexaData(InputHexaData);
		for (i = 0; i < 5; i++)
			HexaData.Hex[i] = InputHexaData[i + 2];

		LInsert(&HexaDataList, HexaData);
	} while (moreHexaData());

	system("cls");

	SumOfHexaData = Calc(&HexaDataList);

	if (LFirst(&HexaDataList, &HexaData)) {
		printf("0x%s :", HexaData.Hex);
		
		for (i = 0; i < 4; i++) 
			printf(" %s", HexaData.Bin[i]);

		printf("\n");

		while (LNext(&HexaDataList, &HexaData)) {
			printf("0x%s :", HexaData.Hex);

			for (i = 0; i < 4; i++)
				printf(" %s", HexaData.Bin[i]);

			printf("\n");
		}
	}

	printf("-----------------------------\n");

	printf("���   :");
	for (i = 0; i < 4; i++){
		printf(" ");
		printf("%s", SumOfHexaData[i]);
	}
	printf("\n\n");
	
	return 0;

}

int getHexaData(char *Hexadata) {

	int i;

	for (i = 0; i < 7; i++)	// �迭 �ʱ�ȭ
		Hexadata[i] = -1;

	while (1) {
		printf("16������ 0xNNNN ���·� �Է����ֽʽÿ� : ");

		for (i = 0; i < 6; i++) {	// �迭 �Է�
			Hexadata[i] = getchar();
			if (Hexadata[i] == '\n')
				break;
		}

		if (Hexadata[i] != '\n')
			flushBuffer();
		Hexadata[i] = '\0';

		if (Hexadata[0] != '0' || Hexadata[1] != 'x') {
			printf("�߸� �Է��ϼ̽��ϴ�. �Է��� 0x�� �����ؾ��մϴ�.\n");
			continue;
		}
		else if (Hexadata[6] != '\0') {
			printf("�߸� �Է��ϼ̽��ϴ�. �Է��� �������� 4�ڸ� ���ĸ� �����մϴ�.\n");
			continue;
		}
		else {
			for (i = 2; i < 6; i++) {
				if ((Hexadata[i] >= '0' && Hexadata[i] <= '9') || (Hexadata[i] >= 'a' && Hexadata[i] <= 'f'))
					continue;
				else {
					printf("�߸� �Է��ϼ̽��ϴ�. �Է��� 0 ~ f ������ ���������� �����մϴ�.\n");
					break;
				}
			}

			if (i == 6)
				return 0;
		}
	}
}

void flushBuffer() {

	while (getchar() != '\n');
}

int moreHexaData() {

	char YesOrNo;

	while (1) {
		printf("16������ �� �Է��Ͻðڽ��ϱ�? (y / n) : ");

		YesOrNo = getchar();
		flushBuffer();

		if (YesOrNo == 'y')
			return 1;
		else if (YesOrNo == 'n')
			return 0;
		else {
			printf("������ y�� n�� �����մϴ�.\n");
			continue;
		}
	}
}

char **Calc(List *DataList) {

	LData Data;
	char **SumOfDataList;
	int i, j;

	SumOfDataList = (char **)malloc(sizeof(char *) * 4);

	for (i = 0; i < 4; i++)
		SumOfDataList[i] = (char *)malloc(sizeof(char) * 5);
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			SumOfDataList[i][j] = '0';
		SumOfDataList[i][4] = '\0';
	}

	if (LFirst(DataList, &Data)) {
		HexToBin(Data.Hex, Data.Bin);
		DataList->cur->data = Data;
		addSumOfDataList(SumOfDataList, Data.Bin);

		while (LNext(DataList, &Data)) {
			HexToBin(Data.Hex, Data.Bin);
			DataList->cur->data = Data;
			addSumOfDataList(SumOfDataList, Data.Bin);
		}
	}

	return SumOfDataList;
}

void HexToBin(char Hex[], char Bin[4][5]) {

	int i, j, temp;

	for (i = 0; i < 4; i++)
		Bin[i][4] = '\0';

	for (i = 0; i < 4; i++) {
		if (Hex[i] >= '0' && Hex[i] <= '9') {
			temp = (int)Hex[i] - 48;

			for (j = 0; j < 4; j++) {
				Bin[i][3 - j] = (char)((temp % 2) + 48);
				temp /= 2;
			}
		}
		else if (Hex[i] >= 'a' && Hex[i] <= 'f') {
			temp = (int)Hex[i] - 97 + 10;

			for (j = 0; j < 4; j++) {
				Bin[i][3 - j] = (char)((temp % 2) + 48);
				temp /= 2;
			}
		}
	}
}

void addSumOfDataList(char **SumOfDataList, char Bin[][5]) {

	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++) {
			SumOfDataList[i][j] += (Bin[i][j] - 48);

			if (SumOfDataList[i][j] > '9')
				SumOfDataList[i][j] -= (char)10;
		}
}