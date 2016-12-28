#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

int PreTest1_4();
char *doRunLengthCoding(char *, int);
int countFileSize(FILE *);

int main() {

	PreTest1_4();

	system("pause");

}

int PreTest1_4() {

	char *InputSentence, *OutputSentence;
	int InputSentenceLength = 0, OutputSentenceLength = 0, RepeatedCount = 1;

	printf("������ ���ڿ� �Է� : ");

	InputSentence = makeDynamicArray();

	InputSentenceLength = strlen(InputSentence);
	
	OutputSentence = doRunLengthCoding(InputSentence, InputSentenceLength);

	free(InputSentence);

	printf("����� ���ڿ� : %s\n", OutputSentence);

	free(OutputSentence);

	return 0;
}

char* doRunLengthCoding(char* InputSentence, int InputSentenceLength) {	// ������ �Է��� �޾Ƽ� ���ڿ��� ����� ��ȯ�ϴ� ���� �迭 �κ�.

	FILE *TempBuf;
	int FileLength = 0, RepeatedCount = 1, CharCount = 0;
	char *FileContent;
	char RepeatedChar;
	int i;

	RepeatedChar = InputSentence[0];

	TempBuf = fopen("RunLengthTemp", "wt+");

	for (i = 0; i < InputSentenceLength; i++) {
		if (InputSentence[i] == InputSentence[i + 1])
			RepeatedCount++;
		else {
			// ���� ���� ����� "g134"�̷� ������ �ȴٸ� �̰� "g...(134�� �ݺ�)...g"���� "g3333"���� ���� �Ұ��ϹǷ� �̽������� �������� �־������. 
			fprintf(TempBuf, "*%c%d", InputSentence[i], RepeatedCount);	// '*'�� �̽������� ������															
			RepeatedCount = 1;
		}
	}

	FileLength = countFileSize(TempBuf);

	FileContent = (char*)malloc(sizeof(char) * (FileLength+1));	// ���ڿ� �迭 ������ ���� \0 �����ؼ� �� ������ ũ�� ����ش�

	fseek(TempBuf, 0, SEEK_SET);

	for (i = 0; i < FileLength; i++)
		fscanf(TempBuf, "%c", &FileContent[i]);

	FileContent[FileLength] = '\0';

	fclose(TempBuf);

	remove("RunLengthTemp");

	return FileContent;
}

int countFileSize(FILE *TempFile) {

	int FileSize = 0;

	fseek(TempFile, 0, SEEK_SET);

	while (fgetc(TempFile) != EOF)
		FileSize++;

	return FileSize;
}