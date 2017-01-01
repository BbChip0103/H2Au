#include <stdio.h>
#include <Windows.h>

int Pretest3_2_5();
void MoveXY(int _x, int _y);

void main() {

	Pretest3_2_5();

}

int Pretest3_2_5() {
	int i;

	for (i = 0; i < 5; i++) {
		MoveXY(5 + i, i);
		printf("%d", 2 * i);

		MoveXY(4 - i, 1 + i);
		printf("%d", (2 * i) + 1);

		MoveXY((2 * i) + 1, 5);
		printf("%d", (2 * i));
		printf("%d", (2 * i) + 1);
	}

	return 0;
}

void MoveXY(int _x, int _y) {
	COORD cur;
	cur.X = _x;
	cur.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

/*  
	1. �ڵ� ���ۿ���
	2. �� �̷��� ®�� - ���� ���⼺-> ���ǹ� �迭 ����, for�� �ּ�ȭ
	3. �ٽ��ڵ�? - ������ �ڵ尡 �̷��� �ʾҽ��ϴ�;;
	4. �� Pretest �Լ��� ���� - 1.����� �� TDD ���� ���� 2.�ð� �� �� ���� 3.�����Լ����� �̰����� �ϸ� �ȵ� 4.��������
	5. Ŭ���ڵ� - ���� C++ ��Ÿ�� ���̵�
*/