#include<stdio.h>
#include<stdlib.h>

int NumberSlug();

void main() {

	NumberSlug();

}

int NumberSlug() {

	// 2���� ���� �迭 ������ �� ���������ͺ��� ����
	int** SlugArray; 
	// �迭�� ����, ���� ũ�⸦ �Է¹��� ���� ����
	int SlugVerticalSize; 
	int SlugHorizontalSize;
	// ���̴� �κб����� ���� �����ϴ� ����
	int SlugVerticalCount; 
	int SlugHorizontalCount;
	// �󸶳� �� ���� ���̴� �κ������� ���� ���� �����ϴ� ����
	int SlugVerticalMoveCount; 
	int SlugHorizontalMoveCount;
	// ������ �� ����, ��, �迭�� �� ũ�� ���.
	int SlugLength;
	// �迭�� �� �־��� �� ��ġ�� X, Y��ǥ
	int SlugPointX; 
	int SlugPointY; 
	// �ݺ����� i, j ����
	int i, j; 

	// ������ ������� ���ư��鼭 �Է� ���ַ��� �Է� ������ �־�� �ϴµ�, ���ڴ� ���� �����ؼ� ��ó��
	enum Direction {
		Up = 0,
		Right,
		Down,
		Left,
		DirectionSize = 4 // �̷��� ���ָ� �ݺ��� ó���� �� ���ؼ� ���������� ����. �� �ڵ忡�� ���� �Ⱦ��� ��......
	} OutputDirection;

	printf("�迭�� ����� �Է����ּ���.\n");

	// �迭�� ����� �Է¹޴� �κ�
	printf("���� �Է� : ");
	scanf_s("%d", &SlugHorizontalSize);
	printf("���� �Է� : ");
	scanf_s("%d", &SlugVerticalSize);

	printf("\n");

	// 2���� �迭 ��������
	SlugArray = (int**)malloc(sizeof(int*) * SlugVerticalSize);
	for (i = 0; i < SlugVerticalSize; i++)
		SlugArray[i] = (int*)malloc(sizeof(int) * SlugHorizontalSize);

	//���� ����� 2���� �迭�� ���̴� �κ� �������� 1���� �迭�� ���� ���� �� �� �߶���� ��,
	//���� ���� �� �� ������ -1�� ���������� �̷�� ���� �̿��Ͽ� ������ ����

	// �迭�� �� ���� ����. ���� ū ������ �����ؼ� �־ �� �������� ���� ���� 1�� �ǰ� �� ����
	SlugLength = SlugHorizontalSize * SlugVerticalSize; 
	
	// �迭�� ���� �ϴ��� (0, 0)���� ����
	SlugPointX = 0;
	SlugPointY = 0;

	// ������ �ʱⰪ ���� �ö󰡰� ����
	OutputDirection = Up; 

	SlugVerticalCount = SlugVerticalSize; // ī��Ʈ ����. ���⼭�� ���� �ö󰡴°ź��� ����
	SlugHorizontalCount = SlugHorizontalSize - 1; // ���̴� �κ� ��ġ�� �� ������ �ϳ� ���� ������
	
	// �󸶳� �� �ö󰡾� ���̴� �κ������� ��Ÿ���� ������ �ʱ�ȭ
	SlugVerticalMoveCount = SlugVerticalCount; 
	SlugHorizontalMoveCount = SlugHorizontalCount; 

	for (;;) {
		if (SlugLength == 0)
			break;

		SlugArray[SlugPointY][SlugPointX] = SlugLength; // ���� �������� ���� �Ҵ�
		SlugLength -= 1; // ���ڸ� �־�����, 1 �ٿ���

		// ���̴� �κп� �����ϸ� ó�����ִ� �κ�
		if ((OutputDirection == Up || OutputDirection == Down) && SlugVerticalMoveCount == 1) { 
			SlugVerticalCount -= 1;	// ����(common difference)�� -1�� ���������̴� 1 �ٿ���
			SlugVerticalMoveCount = SlugVerticalCount; // �ٽ� ī��Ʈ�� �޾Ƽ� �ʱ�ȭ

			// ���� �ö󰡴� ������ ���, �������� �����ϴ� ���¸� �ٲ���
			if (OutputDirection == Up) { 
				OutputDirection = Right;
				SlugPointX += 1;
			}
			// �������� ������ ���, �������� �����ϴ� ���¸� �ٲ���
			else if (OutputDirection == Down) { 
				OutputDirection = Left;
				SlugPointX -= 1;
			}
		}
		// �˰����� ���� ���� ������
		else if ((OutputDirection == Right || OutputDirection == Left) && SlugHorizontalMoveCount == 1) { 
			SlugHorizontalCount -= 1;
			SlugHorizontalMoveCount = SlugHorizontalCount;

			// �������� ���� ������ ���, �Ʒ��� ���������ϴ� ���¸� �ٲ���
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
			// ���� ���� ������ ���, �������� ���� ��ĭ ��������
			if (OutputDirection == Up) { 
				SlugPointY += 1;
				SlugVerticalMoveCount -= 1;
			}
			// �������� ���� ������ ���, �������� �������� ��ĭ ��������
			else if (OutputDirection == Right) { 
				SlugPointX += 1;
				SlugHorizontalMoveCount -= 1;
			}
			// �Ʒ��� ���� ������ ���, �������� �Ʒ��� ��ĭ ��������
			else if (OutputDirection == Down) { 
				SlugPointY -= 1;
				SlugVerticalMoveCount -= 1;
			}
			// �������� ���� ������ ���, �������� �������� ��ĭ ��������
			else if (OutputDirection == Left) { 
				SlugPointX -= 1;
				SlugHorizontalMoveCount -= 1;
			}

		}

	}

	// ��� �κ�. ���� ������ ������ ���� �� �Ϸ���
	for (i = SlugVerticalSize - 1; i >= 0; i--) { 
		for (j = 0; j < SlugHorizontalSize; j++) {
			printf("%2d ", SlugArray[i][j]);
		}
		printf("\n\n");
	}

	// �� ������ �Ҵ� ����
	for (i = 0; i < SlugVerticalSize; i++) 
		free(SlugArray[i]);
	free(SlugArray);

	return 0;
}