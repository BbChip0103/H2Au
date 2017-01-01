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
	1. 코드 동작원리
	2. 왜 이렇게 짰나 - 공부 방향성-> 조건문 배열 없이, for문 최소화
	3. 다시코딩? - 원래는 코드가 이렇지 않았습니다;;
	4. 저 Pretest 함수는 뭐임 - 1.디버깅 및 TDD 용이 측면 2.시간 잴 때 용이 3.메인함수에서 이것저것 하면 안됨 4.취항저격
	5. 클린코드 - 구글 C++ 스타일 가이드
*/