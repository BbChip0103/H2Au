#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

#define PI 3.14159265358979323846
#define COS(angle) cos(PI * angle / 180)
#define SIN(angle) sin(PI * angle / 180)
#define VERTICAL_SCALE 1	// �ܼ�â���� ���μ��� ũ�Ⱑ �޶�, 2�� �ϸ� ����ũ�⸦ 1/2�� �ٿ���


int Pretest1_2();
int GetArraySize();
void ResizeWindow(int _array_size);
void PrintSpiral(int _array_size);
void MoveXY(int _x, int _y);

void main() {

	Pretest1_2();

}

int Pretest1_2() {
	int array_size;

	array_size = GetArraySize();

	ResizeWindow(array_size);

	PrintSpiral(array_size);

	return 0;
}

int GetArraySize() {
	int array_size;

	while (TRUE) {
		printf("�迭�� ũ�⸦ �Է����ּ��� : ");
		scanf("%d", &array_size);
		while (getchar() != '\n');	//	flush input buffer

		if (array_size < 1)
			printf("1 �̻��� �ڿ����� �Է����ּ���.\n\n");
		else 
			break;
	}
	
	return array_size;
}

void ResizeWindow(int _array_size) {
	char temp[40];

	if (_array_size < 14) {	// �̰� ���Ϸδ� �ܼ�â�� �� �پ���;;
		system("mode con:cols=14 lines=14");
		
		return;
	}

	sprintf(temp, "mode con:cols=%d lines=%d", _array_size, (_array_size / VERTICAL_SCALE) + 1);
	system(temp);
}

void PrintSpiral(int _array_size) {
	int radius, rotation_count, angle;
	int i;

	radius = _array_size / 2;	// ������ ���
	rotation_count = radius / 3;	// �� ���� ������, �ڿ� ������ ���ڸ� ���� �� ���� ������ �����ο���
	angle = 360 * rotation_count;	// ���� ���

	for (i = 0; i < angle; i++) {
		MoveXY((int)(COS(i) * radius * i / angle) + (radius - 1),
			(int)(SIN(i) * radius * i / (angle * VERTICAL_SCALE)) + (radius / VERTICAL_SCALE) + 1);
		printf("*");
	}

	MoveXY(0, 2 * radius / VERTICAL_SCALE);	// ������ ��� �����ϱ� Ŀ���� �� ������ ����
}

void MoveXY(int _x, int _y) {
	COORD cur;
	cur.X = _x;
	cur.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}