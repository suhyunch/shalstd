#include <stdio.h>


int main(void)
{
	//FILE *fp;
	int start, end, num = 0;
	//시작값, 끝값, 수열로 계산되는 값
	int cnt = 0;
	//최대 사이클 수
	int i = 0;
	//해당 숫자의 사이클 수
	int number = 0;

	//fp = fopen("H:\\algorithm\\Q1_input.txt", "r");
	//파일 입출력, 읽기모드로 텍스트 파일을 연다.
	//while (~fscanf(fp, "%d %d", &start, &end))
		//입력이 없을때까지 while문 동작, 파일입출력 형태의 입력
		while (~scanf("%d %d", &start, &end))
	{
		for (int j = start; j <= end; j++)
			//start부터 end까지 각 숫자의 사이클과 수열 계산
		{
			num = j;//start값에서 수열 시작
			i = 1;//사이클 수에는 start 값도 포함
			while (num != 1) //수열의 값이 1이 아니면 다음 계산 진행
			{
				if (num % 2) { num = 3 * num + 1; }
				//홀수일때 3배 후 +1
				else { num = num / 2; }
				//짝수일때 2로 나누기
				i++;//사이클 수 계산
			}
			if (i >= cnt) { cnt = i; number = j; }//사이클 수가 최대인 것만 저장
		}
		printf("%d %d %d : %d \n", start, end, cnt, number);
		//start, end, 사이클수 출력
		cnt = 0; //카운트 값 초기화
		number = 0;
	}
	//fclose(fp);//파일 닫음
	return 0;
}
