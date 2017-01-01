#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Pretest3_2_5();

void main() {

	clock_t StartTime, EndTime;

	StartTime = clock();
	Pretest3_2_5();
	EndTime = clock();
	
	printf("\n걸린 시간 : %f \n\n", (double)(EndTime * 1000000));

}

int Pretest3_2_5() {

	char Triangle[6][12];
	int i, j;

	// 초기화
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 11; j++)
			Triangle[i][j] = ' ';
		Triangle[i][11] = '\0';
	}

	// 처리
	for (i = 0; i < 5; i++) {
		Triangle[i][i] = (char)((9 - (i * 2)) + 48);
		Triangle[i + 1][10 - (i + 1)] = (char)((9 - (i * 2 + 1)) + 48);
		
		Triangle[0][(i * 2) + 1] = (char)((i * 2) + 48);
		Triangle[0][(i * 2) + 2] = (char)(((i * 2) + 1) + 48);
	}

	// 출력
	for (i = 0; i < 6; i++) {
		printf("%s", Triangle[5 - i]);
		printf("\n");
	}

	return 0;
}