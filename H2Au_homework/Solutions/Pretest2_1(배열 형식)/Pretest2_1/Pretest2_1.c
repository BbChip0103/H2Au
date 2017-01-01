#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Userdata
{
	char Name[100];	// 세상에서 이름 제일 긴 사람이 81자니 넉넉하게 100정도
	char Mail[100];	// 메일 주소 길어봤자 100자 안 넘겠지
} LData;

int Pretest2_1();
LData *loadUserData(int *, int *);
int checkNullFile(FILE *);
int countUserQuantity(FILE *);

void TDD(int ErrorFlag) {

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
}

int main() {

	TDD(Pretest2_1());

}

int Pretest2_1() {

	int FuntionErrorFlag = 0;
	int UserQuantity = 0;
	LData *UserDataSpace;

	UserDataSpace = loadUserData(&FuntionErrorFlag, &UserQuantity);

	if (FuntionErrorFlag != 0)
		return FuntionErrorFlag;

	return 0;
}

LData *loadUserData(int *FuntionErrorFlag, int *UserQuantity) {

	FILE *InputData = fopen("preTest2-1.txt", "r");
	LData *UserData;
	int i, TempLength = 0;
	char TempChar;

	if (checkNullFile(InputData) == 1) {
		*FuntionErrorFlag = 1;
		return;
	}

	*UserQuantity = countUserQuantity(InputData);
	UserData = (LData *)malloc(sizeof(LData) * (*UserQuantity));

	for (i = 0; i < *UserQuantity; i++) {
		for (;;) {
			fscanf(InputData, "%c", &TempChar);

			if (TempChar == ' ')
				break;
			else if (TempChar == '\n')
				continue;

			UserData[i].Name[TempLength++] = TempChar;
		}

		if (UserData[i].Name[0] == '"' && UserData[i].Name[TempLength - 1] == '"')
			UserData[i].Name[TempLength] = '\0';
		else {
			UserData[i].Name[TempLength++] = '?';
			UserData[i].Name[TempLength] = '\0';
		}

		TempLength = 0;

		for (;;) {
			if (fscanf(InputData, "%c", &TempChar) == EOF)
				break;
			else if (TempChar == ',')
				break;
			else if (TempChar == '\n')
				continue;

			UserData[i].Mail[TempLength++] = TempChar;
		}

		UserData[i].Mail[TempLength] = '\0';
		TempLength = 0;
	}

	for (i = 0; i < *UserQuantity; i++) {	// 테스트 코드
		printf("%s ", UserData[i].Name);
		printf("%s\n", UserData[i].Mail);
	}

	return UserData;
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