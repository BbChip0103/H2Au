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

	printf("압축할 문자열 입력 : ");

	InputSentence = makeDynamicArray();

	InputSentenceLength = strlen(InputSentence);
	
	OutputSentence = doRunLengthCoding(InputSentence, InputSentenceLength);

	free(InputSentence);

	printf("압축된 문자열 : %s\n", OutputSentence);

	free(OutputSentence);

	return 0;
}

char* doRunLengthCoding(char* InputSentence, int InputSentenceLength) {	// 임의의 입력을 받아서 문자열로 만들어 반환하는 동적 배열 부분.

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
			// 만약 압축 결과가 "g134"이런 식으로 된다면 이게 "g...(134번 반복)...g"인지 "g3333"인지 구분 불가하므로 이스케이프 시퀀스를 넣어줘야함. 
			fprintf(TempBuf, "*%c%d", InputSentence[i], RepeatedCount);	// '*'은 이스케이프 시퀀스															
			RepeatedCount = 1;
		}
	}

	FileLength = countFileSize(TempBuf);

	FileContent = (char*)malloc(sizeof(char) * (FileLength+1));	// 문자열 배열 마지막 문자 \0 생각해서 한 사이즈 크게 잡아준다

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