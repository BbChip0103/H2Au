#include <stdio.h>
#include <stdlib.h>
#include"DynamicArray.h"

char* makeDynamicArray() {	// ������ �Է��� �޾Ƽ� ���ڿ��� ����� ��ȯ�ϴ� ���� �迭 �κ�.

	FILE *TempBuf;
	int TempInt, FileLength = 0;
	char *FileContent;

	TempBuf = fopen("temp", "wt+");

	TempInt = fgetc(stdin);

	for (;;) {

		fputc(TempInt, TempBuf);

		if (TempInt == '\n')
			break;

		FileLength++;
		TempInt = getchar();

	}

	FileContent = (char*)malloc(sizeof(char) * (FileLength + 1));

	fseek(TempBuf, 0, SEEK_SET);

	for(int i = 0; i < FileLength; i++)
		fscanf(TempBuf, "%c", &FileContent[i]);

	FileContent[FileLength] = '\0';

	fclose(TempBuf);

	remove("temp");

	return FileContent;
}
