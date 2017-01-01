#include<stdio.h>
#include<stdlib.h>

int NumberSlug();

void main() {

	NumberSlug();

}

int NumberSlug() {

	// 2차원 동적 배열 역할을 할 이중포인터변수 선언
	int** SlugArray; 
	// 배열의 수직, 수평 크기를 입력받을 변수 선언
	int SlugVerticalSize; 
	int SlugHorizontalSize;
	// 꺾이는 부분까지의 수를 저장하는 변수
	int SlugVerticalCount; 
	int SlugHorizontalCount;
	// 얼마나 더 가야 꺾이는 부분인지를 세는 수를 저장하는 변수
	int SlugVerticalMoveCount; 
	int SlugHorizontalMoveCount;
	// 달팽이 총 길이, 즉, 배열의 총 크기 계산.
	int SlugLength;
	// 배열에 값 넣어줄 곳 위치의 X, Y좌표
	int SlugPointX; 
	int SlugPointY; 
	// 반복문용 i, j 선언
	int i, j; 

	// 달팽이 모양으로 돌아가면서 입력 해주려면 입력 방향이 있어야 하는데, 숫자는 보기 불편해서 선처리
	enum Direction {
		Up = 0,
		Right,
		Down,
		Left,
		DirectionSize = 4 // 이렇게 해주면 반복문 처리할 때 편해서 습관적으로 선언. 이 코드에선 딱히 안쓰는 듯......
	} OutputDirection;

	printf("배열의 사이즈를 입력해주세요.\n");

	// 배열의 사이즈를 입력받는 부분
	printf("가로 입력 : ");
	scanf_s("%d", &SlugHorizontalSize);
	printf("세로 입력 : ");
	scanf_s("%d", &SlugVerticalSize);

	printf("\n");

	// 2차원 배열 동적선언
	SlugArray = (int**)malloc(sizeof(int*) * SlugVerticalSize);
	for (i = 0; i < SlugVerticalSize; i++)
		SlugArray[i] = (int*)malloc(sizeof(int) * SlugHorizontalSize);

	//구현 방법은 2차원 배열을 꺾이는 부분 기점으로 1차원 배열로 가로 세로 각 각 잘라봤을 때,
	//가로 세로 각 각 공차가 -1인 등차수열을 이루는 것을 이용하여 구현할 예정

	// 배열의 총 갯수 구함. 제일 큰 수부터 시작해서 넣어서 맨 마지막에 들어가는 것이 1이 되게 할 예정
	SlugLength = SlugHorizontalSize * SlugVerticalSize; 
	
	// 배열의 좌측 하단인 (0, 0)부터 시작
	SlugPointX = 0;
	SlugPointY = 0;

	// 방향의 초기값 위로 올라가게 설정
	OutputDirection = Up; 

	SlugVerticalCount = SlugVerticalSize; // 카운트 설정. 여기서는 위로 올라가는거부터 시작
	SlugHorizontalCount = SlugHorizontalSize - 1; // 꺾이는 부분 겹치는 것 때문에 하나 빼고 시작함
	
	// 얼마나 더 올라가야 꺾이는 부분인지를 나타내는 변수도 초기화
	SlugVerticalMoveCount = SlugVerticalCount; 
	SlugHorizontalMoveCount = SlugHorizontalCount; 

	for (;;) {
		if (SlugLength == 0)
			break;

		SlugArray[SlugPointY][SlugPointX] = SlugLength; // 현재 기준점에 숫자 할당
		SlugLength -= 1; // 숫자를 넣었으니, 1 줄여줌

		// 꺾이는 부분에 도달하면 처리해주는 부분
		if ((OutputDirection == Up || OutputDirection == Down) && SlugVerticalMoveCount == 1) { 
			SlugVerticalCount -= 1;	// 공차(common difference)가 -1인 등차수열이니 1 줄여줌
			SlugVerticalMoveCount = SlugVerticalCount; // 다시 카운트값 받아서 초기화

			// 위로 올라가던 상태일 경우, 우측으로 가야하니 상태를 바꿔줌
			if (OutputDirection == Up) { 
				OutputDirection = Right;
				SlugPointX += 1;
			}
			// 내려오던 상태일 경우, 좌측으로 가야하니 상태를 바꿔줌
			else if (OutputDirection == Down) { 
				OutputDirection = Left;
				SlugPointX -= 1;
			}
		}
		// 알고리즘은 위와 같은 동일함
		else if ((OutputDirection == Right || OutputDirection == Left) && SlugHorizontalMoveCount == 1) { 
			SlugHorizontalCount -= 1;
			SlugHorizontalMoveCount = SlugHorizontalCount;

			// 우측으로 가던 상태일 경우, 아래로 내려가야하니 상태를 바꿔줌
			if (OutputDirection == Right) { 
				OutputDirection = Down;
				SlugPointY -= 1;
			}
			else if (OutputDirection == Left) {
				OutputDirection = Up;
				SlugPointY += 1;
			}
		}
		else {
			// 위로 가는 상태일 경우, 기준점을 위로 한칸 움직여줌
			if (OutputDirection == Up) { 
				SlugPointY += 1;
				SlugVerticalMoveCount -= 1;
			}
			// 우측으로 가는 상태일 경우, 기준점을 우측으로 한칸 움직여줌
			else if (OutputDirection == Right) { 
				SlugPointX += 1;
				SlugHorizontalMoveCount -= 1;
			}
			// 아래로 가는 상태일 경우, 기준점을 아래로 한칸 움직여줌
			else if (OutputDirection == Down) { 
				SlugPointY -= 1;
				SlugVerticalMoveCount -= 1;
			}
			// 좌측으로 가는 상태일 경우, 기준점을 좌측으로 한칸 움직여줌
			else if (OutputDirection == Left) { 
				SlugPointX -= 1;
				SlugHorizontalMoveCount -= 1;
			}

		}

	}

	// 출력 부분. 글자 사이의 간격은 어케 못 하려나
	for (i = SlugVerticalSize - 1; i >= 0; i--) { 
		for (j = 0; j < SlugHorizontalSize; j++) {
			printf("%2d ", SlugArray[i][j]);
		}
		printf("\n\n");
	}

	// 다 썼으니 할당 해제
	for (i = 0; i < SlugVerticalSize; i++) 
		free(SlugArray[i]);
	free(SlugArray);

	return 0;
}