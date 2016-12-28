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
		printf("정상 작동.\n");
	else if (ErrorFlag == NoFile)
		printf("읽을 파일이 없습니다.\n");
	else if (ErrorFlag == Unknown)
		printf("원인 미상의 오류.\n");

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

	if (ErrorFlag != 0)	// 위 함수가 정상적으로 종료되지 않았을 시에 에러플래그를 위로 던짐
		return ErrorFlag;

	UserQuantity = LCount(&UserDataList);
	
	printf("현재 데이터의 수: %d \n\n", UserQuantity);

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

int loadUserData(List* UserDataList) {	// 텍스트 형식으로 된 데이터를 불러서 처리하는 부분

	FILE *InputData = fopen("preTest2-1.txt", "r");
	int UserQuantity;

	if (checkNullFile(InputData) == 1)
		return 1;

	UserQuantity = countUserQuantity(InputData);

	insertInputDataToList(InputData, UserDataList, UserQuantity);	//	연결리스트 사용

	return 0;
}

int checkNullFile(FILE* File) {

	if (File == NULL)	// exception 위로 던지듯이 쓰려고 만듬
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

// 이름 추출. 공백문자인 ' '를 만날때까지 받아서 임시로 저장하며, 양 끝이 '"'가 아닐 경우엔 끝에 '?'를 붙여서 저장.
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

// 메일주소 추출. ','를 만날때까지 받아서 임시로 저장하며, 텍스트의 끝에 도달했을 경우엔 EOF를 반환.
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