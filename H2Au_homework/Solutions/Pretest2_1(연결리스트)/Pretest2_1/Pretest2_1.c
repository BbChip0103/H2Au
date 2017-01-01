#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"

int Pretest2_1();
int loadUserData(List *);
int insertInputDataToList(FILE *, List *, int);
int checkNullFile(FILE *);
int countUserQuantity(FILE *);
int extractName(FILE *, LData *);
int extractMail(FILE *, LData *);

void checkError(int ErrorFlag) {

	enum ErrorNumber
	{
		Good = 0,
		NoFile,
		Unknown,
		ErrorSize = 3
	};

	if (ErrorFlag == Good)
		printf("���� �۵�.\n");
	else if (ErrorFlag == NoFile)
		printf("���� ������ �����ϴ�.\n");
	else if (ErrorFlag == Unknown)
		printf("���� �̻��� ����.\n");

	printf("\n");
	system("pause");
}

void main() {

	checkError(Pretest2_1());

}

int Pretest2_1() {

	List UserDataList;
	LData UserData;
	int ErrorFlag;
	int UserQuantity;
	int i, j;

	ListInit(&UserDataList);

	ErrorFlag = loadUserData(&UserDataList);

	if (ErrorFlag != 0)	// �� �Լ��� ���������� ������� �ʾ��� �ÿ� �����÷��׸� ���� ����
		return ErrorFlag;

	UserQuantity = LCount(&UserDataList);
	
	printf("���� �������� ��: %d \n\n", UserQuantity);

	for (i = 0; i < UserQuantity; i++) {
		LFirst(&UserDataList, &UserData);

		for (j = (i + 1); j < UserQuantity; j++)
			LNext(&UserDataList, &UserData);

		printf("%s ", UserData.Name);
		printf("%s\n", UserData.Mail);
	}

	printf("\n");

	return 0;
}

int loadUserData(List* UserDataList) {	// �ؽ�Ʈ �������� �� �����͸� �ҷ��� ó���ϴ� �κ�

	FILE *InputData = fopen("preTest2-1.txt", "r");
	int UserQuantity;

	if (checkNullFile(InputData) == 1)
		return 1;

	UserQuantity = countUserQuantity(InputData);

	insertInputDataToList(InputData, UserDataList, UserQuantity);	//	���Ḯ��Ʈ ���

	return 0;
}

int checkNullFile(FILE* File) {

	if (File == NULL)	// exception ���� �������� ������ ����
		return 1;

	return 0;
}

int countUserQuantity(FILE *UserData) {

	int UserQuantity = 0;
	char TempChar;

	while (fscanf(UserData, "%c", &TempChar) != EOF)
		if (TempChar == ' ')
			UserQuantity++;

	fseek(UserData, 0, SEEK_SET);

	return UserQuantity;
}

int insertInputDataToList(FILE *InputData, List *UserDataList, int UserQuantity) {

	LData UserData;

	for (int i = 0; i < UserQuantity; i++) {

		extractName(InputData, &UserData);
		extractMail(InputData, &UserData);
		
		LInsert(UserDataList, UserData);
	}

	return 0;
}

// �̸� ����. ���鹮���� ' '�� ���������� �޾Ƽ� �ӽ÷� �����ϸ�, �� ���� '"'�� �ƴ� ��쿣 ���� '?'�� �ٿ��� ����.
int extractName(FILE *InputData, LData *UserData) {	

	int TempLength = 0;
	char TempChar;

	for (;;) {
		fscanf(InputData, "%c", &TempChar);

		if (TempChar == ' ')
			break;
		else if (TempChar == '\n')
			continue;

		UserData->Name[TempLength++] = TempChar;
	}

	if (UserData->Name[0] == '"' && UserData->Name[TempLength - 1] == '"')
		UserData->Name[TempLength] = '\0';
	else {
		UserData->Name[TempLength++] = '?';
		UserData->Name[TempLength] = '\0';
	}

	return 0;
}

// �����ּ� ����. ','�� ���������� �޾Ƽ� �ӽ÷� �����ϸ�, �ؽ�Ʈ�� ���� �������� ��쿣 EOF�� ��ȯ.
int extractMail(FILE *InputData, LData * UserData) {

	int TempLength = 0;
	char TempChar;

	for (;;) {
		if (fscanf(InputData, "%c", &TempChar) == EOF)
			return EOF;
		else if (TempChar == ',')
			break;
		else if (TempChar == '\n')
			continue;

		UserData->Mail[TempLength++] = TempChar;
	}

	UserData->Mail[TempLength] = '\0';

	return 0;
}