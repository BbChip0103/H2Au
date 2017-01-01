#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Pretest1_2();

char** loadNameList(char**, int*, int*);
int checkNullFile(FILE*);
char** createNameSpace(char**, int, int);
char** initializeNameSpace(char**, int, int);
char** extendNameSpace(char**, int, int);
int reliveNameSpace(char**, int);
int addNameFromFile(FILE*, char**, int, int);
int addNameFromList(char*, char*);
int printNameList(char**, int);

int searchJoAndPark(char**, int);
int searchIdenticalFirstName(char**, int, char*);
int isNotExistInList(char**, char*, int);

int searchJeonJongHwa(char**, int);
int searchName(char**, int, char*);

int printNameList_ExceptOverlappingName(char**, int);

int printSortedNameList_ExceptOverlappingName(char**, int);
int CompareByName(const void *x, const void *y);

void TDD(int ErrorFlag) {

	enum ErrorType
	{
		NoError = 0,
		NoFile,
		ErrorSize = 2
	};

	if (ErrorFlag == NoError) printf("���� ����\n");
	else if (ErrorFlag == NoFile) printf("������ ����\n");

	printf("\n");
}

void main() {

	TDD(Pretest1_2());	// TestDrivenDevelopment

	system("pause");

}

int Pretest1_2() {

	char** UserNameList = NULL;
	int NameQuantity = 0;
	int FuntionErrorFlag = 0;

	UserNameList = loadNameList(UserNameList, &NameQuantity, &FuntionErrorFlag);

	if (FuntionErrorFlag == 1)
		return FuntionErrorFlag;

	searchJoAndPark(UserNameList, NameQuantity);
	searchJeonJongHwa(UserNameList, NameQuantity);

	printNameList_ExceptOverlappingName(UserNameList, NameQuantity);
	printSortedNameList_ExceptOverlappingName(UserNameList, NameQuantity);

	return FuntionErrorFlag;
}

char** loadNameList(char** UserNameSpace, int* NameQuantity, int* FuntionErrorFlag) {

	FILE *InputName = fopen("preTest1-2.txt", "r");
	int NameLength = 0;
	char FileInputTemp;

	if (checkNullFile(InputName) == 1) {
		*FuntionErrorFlag = 1;
		return 0;
	}
	
	for (;;) {
		if (fscanf(InputName, "%c", &FileInputTemp) == EOF) {
			UserNameSpace = createNameSpace(UserNameSpace, *NameQuantity, NameLength);
			fseek(InputName, -(NameLength), SEEK_END);		// Ŀ���� �� �ں��� ���ϱ� ��ǥ �ڸ� �A ���� ��ĭ �� ������ ����
			addNameFromFile(InputName, UserNameSpace, *NameQuantity, NameLength);
			NameLength = 0;
			(*NameQuantity)++;
			break;
		}

		if (FileInputTemp == '\n')
			continue;
		else if (FileInputTemp == ',') {
			UserNameSpace = createNameSpace(UserNameSpace, *NameQuantity, NameLength);
			fseek(InputName, -(NameLength+1), SEEK_CUR);		// Ŀ���� ��ǥ �����ؼ� �̸� ũ�⸸ŭ ������ �̵��ؾ��ϴ� -(NameLength+1) ��ŭ �̵��Ѵ�
			addNameFromFile(InputName, UserNameSpace, *NameQuantity, NameLength);
			NameLength = 0;	// ���� �̸� ���� �����ϴ� 0���� �ʱ�ȭ
			fseek(InputName, 1, SEEK_CUR);	// ���� �̸����� �Ѿ���ϴ� ��ǥ �ǳʶ�
			(*NameQuantity)++;
		}
		else
			NameLength++;
	}

	return UserNameSpace;
}

int checkNullFile(FILE* File) {

	if (File == NULL)	// exception ���� �������� ������ ����
		return 1;	

	return 0;
}

char** createNameSpace(char** NameSpace, int NameQuantity, int NameLength) {

	if (NameQuantity == 0)
		NameSpace = initializeNameSpace(NameSpace, NameQuantity, NameLength);
	else
		NameSpace = extendNameSpace(NameSpace, NameQuantity, NameLength);

	return NameSpace;
}

char** initializeNameSpace(char** NameSpace, int NameQuantity, int NameLength) {

	NameSpace = (char**)malloc(sizeof(char*));

	// ���� %0 �־�����ؼ� �̸� ũ�⺸�� 1 ũ�� Ȯ��
	NameSpace[NameQuantity] = (char*)malloc(sizeof(char) * (NameLength + 1));

	return NameSpace;
}

char** extendNameSpace(char** NameSpace,int NameQuantity, int NameLength) {

	NameSpace = (char**)realloc(NameSpace, sizeof(char*) * (NameQuantity + 1));
	NameSpace[NameQuantity] = (char*)malloc(sizeof(char) * (NameLength + 1));

	return NameSpace;
}

int reliveNameSpace(char** NameSpace, int NameQuantity) {
	
	int i;

	for (i = 0; i < NameQuantity; i++)
		free(NameSpace[i]);

	free(NameSpace);

	return 0;
}

int addNameFromFile(FILE* InputName, char** NameSpace, int NameListOrder, int NameLength) {

	int i;

	for (i = 0; i < NameLength; i++)
		fscanf(InputName, "%c", &NameSpace[NameListOrder][i]);

	NameSpace[NameListOrder][NameLength] = '\0';

	return 0;
}

int addNameFromList(char* DestNameList, char* SourceNameList) {

	strcpy(DestNameList, SourceNameList);
	DestNameList[strlen(SourceNameList)] = '\0';

	return 0;
}

int searchJoAndPark(char** NameList, int NameQuantity) {

	char* Jo_FirstName = "��";
	char* Park_FirstName = "��";

	searchIdenticalFirstName(NameList, NameQuantity, Jo_FirstName);
	printf("\n");

	searchIdenticalFirstName(NameList, NameQuantity, Park_FirstName);
	printf("\n");

	return 0;
}

int searchIdenticalFirstName(char** NameList, int NameQuantity, char* FirstName) {

	int i;
	char **TempNameList = NULL;
	int TempNameListQuantity = 0;
	int FirstNameQuantity = 0;

	printf("���� '%s'���� ��� \n", FirstName);

	for (i = 0; i < NameQuantity; i++) {
		if (strncmp(NameList[i], FirstName, strlen(FirstName)) == 0) {
			if (isNotExistInList(TempNameList, NameList[i], TempNameListQuantity)) {
				// %0 �����ͱ��� �����ؼ� +1
				TempNameList = createNameSpace(TempNameList, TempNameListQuantity, (strlen(NameList[i]) + 1));	
				addNameFromList(TempNameList[TempNameListQuantity++], NameList[i]);
			}
			FirstNameQuantity++;
		}
	}

	printNameList(TempNameList, TempNameListQuantity);
	printf("�̸��� �� ���� : %d\n", FirstNameQuantity);

	reliveNameSpace(TempNameList, TempNameListQuantity);

	return 0;
}

int isNotExistInList(char** TargetNameList, char* Name, int ListLength) {

	int i;

	for (i = 0; i < ListLength; i++)
		if (strcmp(TargetNameList[i], Name) == 0)
			return 0;

	return 1;
}

int printNameList(char** NameList, int NameQuantity) {

	int i = 0;

	printf("�̸� ��� : ");

	for (i = 0; i < NameQuantity; i++)
		printf("%s, ", NameList[i]);

	printf("\b\b \n");

	return 0;
}

int searchJeonJongHwa(char** NameList, int NameQuantity) {

	char* TempName = "����ȭ";

	searchName(NameList, NameQuantity, TempName);

	printf("\n");

	return 0;
}

int searchName(char** NameList, int NameQuantity, char* TargetName) {

	int NameIdenticalQuantity = 0;
	int i;

	for (i = 0; i < NameQuantity; i++)
		if (strcmp(NameList[i], TargetName) == 0)
			NameIdenticalQuantity++;

	printf("'%s'��� �̸��� �� �� �ݺ��Ǵ°� : %d\n", TargetName, NameIdenticalQuantity);

	return 0;
}

int printNameList_ExceptOverlappingName(char** NameList, int NameQuantity) {

	int i;
	char **TempNameList = NULL;
	int TempNameListQuantity = 0;
	int NameListOrder = 0;

	printf("�ߺ��� ������ �̸�\n");

	for (i = 0; i < NameQuantity; i++)
		if (isNotExistInList(TempNameList, NameList[i], TempNameListQuantity)) {
			// %0 �����ͱ��� �����ؼ� +1
			TempNameList = createNameSpace(TempNameList, TempNameListQuantity, (strlen(NameList[i]) + 1));	
			addNameFromList(TempNameList[TempNameListQuantity++], NameList[i]);
		}

	printNameList(TempNameList, TempNameListQuantity);
	printf("�̸��� �� ���� : %d\n", TempNameListQuantity);
	printf("\n");

	reliveNameSpace(TempNameList, TempNameListQuantity);

	return 0;
}

int printSortedNameList_ExceptOverlappingName(char** NameList, int NameQuantity) {

	int i;
	char **TempNameList = NULL;
	int TempNameListQuantity = 0;

	printf("�ߺ��� ������ �̸��� ������������ ���\n");

	for (i = 0; i < NameQuantity; i++)
		if (isNotExistInList(TempNameList, NameList[i], TempNameListQuantity)) {
			TempNameList = createNameSpace(TempNameList, TempNameListQuantity, (strlen(NameList[i]) + 1));	// %0 �����ͱ��� �����ؼ� +1 ���ش�
			addNameFromList(TempNameList[TempNameListQuantity++], NameList[i]);
		}

	qsort(TempNameList, TempNameListQuantity, sizeof(TempNameList) , CompareByName);

	printNameList(TempNameList, TempNameListQuantity);
	printf("�̸��� �� ���� : %d\n", TempNameListQuantity);
	printf("\n");

	reliveNameSpace(TempNameList, TempNameListQuantity);

	return 0;
}

int CompareByName(const void *Name1, const void *Name2){	// ��������

	return (-strcmp(*(char**)Name1, *(char**)Name2));
}