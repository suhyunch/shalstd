#include <stdio.h>
//#include <string.h> memset 이용할 경우 가능

int main()
{
	FILE *fp;
	int N = 0;//사람 숫자
	float money[1000] = { 0 };
//숫자만큼 돈 저장, 소수점이하의 정보를 갖고 있으므로 float
	float sum = 0;
//총 합계
	float S = 0;
//전달 받을 금액의 총 합계
	float avg=0;

	fopen("D:\\atom_coding\\al_pc\\pro3\\input.txt", "r");

	while (1)
	{
		sum = 0.0;
		S = 0.0;
		fscanf(fp, "%d", &N);
		if (N == 0) break;//0입력되면 프로그램 종료
		else if (N >= 1000) puts("999명까지 가능 합니다.");
		for (int i = 0; i < N; i++)
		{
			fscanf(fp, "%fl", &money[i]);
//money[]로 처음에 선언하면 왜 무한 루프가 될까??
			sum = sum + money[i];//총 합
		}

		avg = sum / (float)N;//형변환중요,평균
		for (int i = 0; i < N; i++)
		{
			if (money[i] < avg) S = S + avg - money[i];
//평균보다 작은 금액에 대해 평균과 금액의 차들의 합
//S += avg-money[i];
		}
		printf("$%.2f\n", S);//출력 소숫점 아래 두자리까지
		for (int j = 0; j < 1000; j++) money[j] = 0;//memset이용
	}

	fclose(fp);
	return 0;
}
